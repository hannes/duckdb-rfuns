#include "rfuns_extension.hpp"
#include "duckdb/parser/parsed_data/create_scalar_function_info.hpp"

#include <math.h>
#include <climits>

namespace duckdb {
namespace rfuns {

namespace {

enum Relop {
	EQ,
	LT
};

template <typename LHS, typename RHS, Relop OP>
bool relop(LHS lhs, RHS rhs) {
	switch (OP)
	{
	case EQ: return lhs == rhs;
	case LT: return lhs <  rhs;

	default:
		break;
	}
	return false;
}

template <LogicalTypeId LHS_LOGICAL, typename LHS, LogicalTypeId RHS_LOGICAL, typename RHS, Relop OP>
void BaseRRelopFunctionSimple(DataChunk &args, ExpressionState &state, Vector &result) {
	auto parts = BinaryTypeAssert<LHS_LOGICAL, RHS_LOGICAL>(args);

	BinaryExecutor::Execute<LHS, RHS, bool>(parts.lefts, parts.rights, result, args.size(), relop<LHS, RHS, OP>);
}

template <Relop OP>
void BaseRRelopFunctionDouble(DataChunk &args, ExpressionState &state, Vector &result) {
	auto parts = BinaryTypeAssert<LogicalType::DOUBLE, LogicalType::DOUBLE>(args);
	auto fun = [&](double left, double right, ValidityMask &mask, idx_t idx) {
		if (isnan(left) || isnan(right)) {
			mask.SetInvalid(idx);
			return false;
		}
		return relop<double, double, OP>(left, right);
	};

	BinaryExecutor::ExecuteWithNulls<double, double, bool>(parts.lefts, parts.rights, result, args.size(), fun);
}

template <typename type, Relop OP>
bool ExecuteBaseRRelopFunctionDoubleInteger(double left, type right, ValidityMask &mask, idx_t idx) {
	if (isnan(left)) {
		mask.SetInvalid(idx);
		return false;
	}
	return relop<double, int32_t, OP>(left, right);
}

template <LogicalTypeId LOGICAL_TYPE, Relop OP>
void BaseRRelopFunctionDoubleInteger(DataChunk &args, ExpressionState &state, Vector &result) {
	using type = typename std::conditional<LOGICAL_TYPE == LogicalType::INTEGER, int32_t, bool>::type;

	auto parts = BinaryTypeAssert<LogicalType::DOUBLE, LOGICAL_TYPE>(args);
	BinaryExecutor::ExecuteWithNulls<double, type, bool>(parts.lefts, parts.rights, result, args.size(),
	                                                     ExecuteBaseRRelopFunctionDoubleInteger<type, OP>);
}

template <LogicalTypeId LOGICAL_TYPE, Relop OP>
void BaseRRelopFunctionIntegerDouble(DataChunk &args, ExpressionState &state, Vector &result) {
	using type = typename std::conditional<LOGICAL_TYPE == LogicalType::INTEGER, int32_t, bool>::type;

	auto parts = BinaryTypeAssert<LOGICAL_TYPE, LogicalType::DOUBLE>(args);
	BinaryExecutor::ExecuteWithNulls<double, type, bool>(parts.rights, parts.lefts, result, args.size(),
	                                                     ExecuteBaseRRelopFunctionDoubleInteger<type, OP>);
}

template <Relop OP>
void BaseRRelopFunctionString(DataChunk &args, ExpressionState &state, Vector &result) {
	auto parts = BinaryTypeAssert<LogicalType::VARCHAR, LogicalType::VARCHAR>(args);
	BinaryExecutor::Execute<string_t, string_t, bool>(parts.lefts, parts.rights, result, args.size(), relop<string_t, string_t, OP>);
}

template <Relop OP>
bool ExecuteBaseRRelopFunctionStringInteger(string_t left, int32_t right) {
	char right_chr[100];
	snprintf(right_chr, sizeof(right_chr), "%d", right);
	return relop<string_t, string_t, OP>(left, right_chr);
}

template <Relop OP>
void BaseRRelopFunctionStringInteger(DataChunk &args, ExpressionState &state, Vector &result) {
	auto parts = BinaryTypeAssert<LogicalType::VARCHAR, LogicalType::INTEGER>(args);

	return BinaryExecutor::Execute<string_t, int32_t, bool>(parts.lefts, parts.rights, result, args.size(),
	                                                        &ExecuteBaseRRelopFunctionStringInteger<OP>);
}

template <Relop OP>
void BaseRRelopFunctionIntegerString(DataChunk &args, ExpressionState &state, Vector &result) {
	auto parts = BinaryTypeAssert<LogicalType::INTEGER, LogicalType::VARCHAR>(args);

	return BinaryExecutor::Execute<string_t, int32_t, bool>(parts.rights, parts.lefts, result, args.size(),
	                                                        &ExecuteBaseRRelopFunctionStringInteger<OP>);
}

template <Relop OP>
bool ExecuteBaseRRelopFunctionStringBoolean(string_t left, bool right) {
	return relop<string_t, string_t, OP>(left, right ? "TRUE" : "FALSE");
}

template <Relop OP>
void BaseRRelopFunctionStringBoolean(DataChunk &args, ExpressionState &state, Vector &result) {
	auto parts = BinaryTypeAssert<LogicalType::VARCHAR, LogicalType::BOOLEAN>(args);

	return BinaryExecutor::Execute<string_t, bool, bool>(parts.lefts, parts.rights, result, args.size(),
	                                                     &ExecuteBaseRRelopFunctionStringBoolean<OP>);
}

template <Relop OP>
void BaseRRelopFunctionBooleanString(DataChunk &args, ExpressionState &state, Vector &result) {
	auto parts = BinaryTypeAssert<LogicalType::BOOLEAN, LogicalType::VARCHAR>(args);

	return BinaryExecutor::Execute<string_t, bool, bool>(parts.rights, parts.lefts, result, args.size(),
	                                                     &ExecuteBaseRRelopFunctionStringBoolean<OP>);
}

template <Relop OP>
bool ExecuteBaseRRelopFunctionStringDouble(string_t left, double right) {
	char right_chr[100];
	snprintf(right_chr, sizeof(right_chr), "%.17g", right);
	return relop<string_t, string_t, OP>(left, right_chr);
}

template <Relop OP>
void BaseRRelopFunctionStringDouble(DataChunk &args, ExpressionState &state, Vector &result) {
	auto parts = BinaryTypeAssert<LogicalType::VARCHAR, LogicalType::DOUBLE>(args);

	return BinaryExecutor::Execute<string_t, double, bool>(parts.lefts, parts.rights, result, args.size(),
	                                                       &ExecuteBaseRRelopFunctionStringDouble<OP>);
}

template <Relop OP>
void BaseRRelopFunctionDoubleString(DataChunk &args, ExpressionState &state, Vector &result) {
	auto parts = BinaryTypeAssert<LogicalType::DOUBLE, LogicalType::VARCHAR>(args);

	return BinaryExecutor::Execute<string_t, double, bool>(parts.rights, parts.lefts, result, args.size(),
	                                                       &ExecuteBaseRRelopFunctionStringDouble<OP>);
}

template <Relop OP>
ScalarFunctionSet base_r_relop(string name) {
	ScalarFunctionSet set(name);

	// (int | lgl) <=> (int | lgl)
	set.AddFunction(ScalarFunction({LogicalType::BOOLEAN, LogicalType::BOOLEAN}, LogicalType::BOOLEAN,
	                               BaseRRelopFunctionSimple<LogicalType::BOOLEAN, bool, LogicalType::BOOLEAN, bool, OP>));
	set.AddFunction(ScalarFunction({LogicalType::BOOLEAN, LogicalType::INTEGER}, LogicalType::BOOLEAN,
	                               BaseRRelopFunctionSimple<LogicalType::BOOLEAN, bool, LogicalType::INTEGER, int32_t, OP>));
	set.AddFunction(ScalarFunction({LogicalType::INTEGER, LogicalType::BOOLEAN}, LogicalType::BOOLEAN,
	                               BaseRRelopFunctionSimple<LogicalType::INTEGER, int32_t, LogicalType::BOOLEAN, bool, OP>));
	set.AddFunction(
	    ScalarFunction({LogicalType::INTEGER, LogicalType::INTEGER}, LogicalType::BOOLEAN,
	                   BaseRRelopFunctionSimple<LogicalType::INTEGER, int32_t, LogicalType::INTEGER, int32_t, OP>));

	// double == (int | lgl)
	set.AddFunction(ScalarFunction({LogicalType::DOUBLE, LogicalType::INTEGER}, LogicalType::BOOLEAN,
	                               BaseRRelopFunctionDoubleInteger<LogicalType::INTEGER, OP>));
	set.AddFunction(ScalarFunction({LogicalType::INTEGER, LogicalType::DOUBLE}, LogicalType::BOOLEAN,
	                               BaseRRelopFunctionIntegerDouble<LogicalType::INTEGER, OP>));
	set.AddFunction(ScalarFunction({LogicalType::DOUBLE, LogicalType::BOOLEAN}, LogicalType::BOOLEAN,
	                               BaseRRelopFunctionDoubleInteger<LogicalType::BOOLEAN, OP>));
	set.AddFunction(ScalarFunction({LogicalType::BOOLEAN, LogicalType::DOUBLE}, LogicalType::BOOLEAN,
	                               BaseRRelopFunctionIntegerDouble<LogicalType::BOOLEAN, OP>));

	// string == int
	set.AddFunction(ScalarFunction({LogicalType::VARCHAR, LogicalType::INTEGER}, LogicalType::BOOLEAN,
	                               BaseRRelopFunctionStringInteger<OP>));
	set.AddFunction(ScalarFunction({LogicalType::INTEGER, LogicalType::VARCHAR}, LogicalType::BOOLEAN,
	                               BaseRRelopFunctionIntegerString<OP>));

	// string == lgl
	set.AddFunction(ScalarFunction({LogicalType::VARCHAR, LogicalType::BOOLEAN}, LogicalType::BOOLEAN,
	                               BaseRRelopFunctionStringBoolean<OP>));
	set.AddFunction(ScalarFunction({LogicalType::BOOLEAN, LogicalType::VARCHAR}, LogicalType::BOOLEAN,
	                               BaseRRelopFunctionBooleanString<OP>));

	set.AddFunction(
	    ScalarFunction({LogicalType::DOUBLE, LogicalType::DOUBLE}, LogicalType::BOOLEAN, BaseRRelopFunctionDouble<OP>));
	set.AddFunction(
	    ScalarFunction({LogicalType::VARCHAR, LogicalType::VARCHAR}, LogicalType::BOOLEAN, BaseRRelopFunctionString<OP>));
	set.AddFunction(
	    ScalarFunction({LogicalType::VARCHAR, LogicalType::DOUBLE}, LogicalType::BOOLEAN, BaseRRelopFunctionStringDouble<OP>));
	set.AddFunction(
	    ScalarFunction({LogicalType::DOUBLE, LogicalType::VARCHAR}, LogicalType::BOOLEAN, BaseRRelopFunctionDoubleString<OP>));

	return set;
}

} // namespace

ScalarFunctionSet base_r_eq() {
	return base_r_relop<EQ>("r_base::==");
}
ScalarFunctionSet base_r_lt() {
	return base_r_relop<LT>("r_base::<");
}

} // namespace rfuns
} // namespace duckdb
