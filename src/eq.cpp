#include "rfuns_extension.hpp"
#include "duckdb/parser/parsed_data/create_scalar_function_info.hpp"

#include <math.h>
#include <climits>
#include <tuple>

namespace duckdb {
namespace rfuns {

namespace {

template <LogicalTypeId LHS_LOGICAL, typename LHS, LogicalTypeId RHS_LOGICAL, typename RHS>
void BaseREqFunctionSimple(DataChunk &args, ExpressionState &state, Vector &result) {
	auto parts = BinaryTypeAssert<LHS_LOGICAL, RHS_LOGICAL>(args);

	auto fun = [](LHS left, RHS right) {
		return (left == right);
	};
	BinaryExecutor::Execute<LHS, RHS, bool>(parts.lefts, parts.rights, result, args.size(), fun);
}

void BaseREqFunctionInteger(DataChunk &args, ExpressionState &state, Vector &result) {
	auto parts = BinaryTypeAssert<LogicalType::INTEGER, LogicalType::INTEGER>(args);

	auto fun = [](int32_t left, int32_t right) {
		return (left == right);
	};
	BinaryExecutor::Execute<int32_t, int32_t, bool>(parts.lefts, parts.rights, result, args.size(), fun);
}

void BaseREqFunctionDouble(DataChunk &args, ExpressionState &state, Vector &result) {
	auto parts = BinaryTypeAssert<LogicalType::DOUBLE, LogicalType::DOUBLE>(args);
	auto fun = [&](double left, double right, ValidityMask &mask, idx_t idx) {
		if (isnan(left) || isnan(right)) {
			mask.SetInvalid(idx);
			return false;
		}
		return (left == right);
	};

	BinaryExecutor::ExecuteWithNulls<double, double, bool>(parts.lefts, parts.rights, result, args.size(), fun);
}

template <typename type>
bool ExecuteBaseREqFunctionDoubleInteger(double left, type right, ValidityMask &mask, idx_t idx) {
	if (isnan(left)) {
		mask.SetInvalid(idx);
		return false;
	}
	return (left == right);
}

template <LogicalTypeId LOGICAL_TYPE>
void BaseREqFunctionDoubleInteger(DataChunk &args, ExpressionState &state, Vector &result) {
	using type = typename std::conditional<LOGICAL_TYPE == LogicalType::INTEGER, int32_t, bool>::type;

	auto parts = BinaryTypeAssert<LogicalType::DOUBLE, LOGICAL_TYPE>(args);
	BinaryExecutor::ExecuteWithNulls<double, type, bool>(parts.lefts, parts.rights, result, args.size(),
	                                                     ExecuteBaseREqFunctionDoubleInteger<type>);
}

template <LogicalTypeId LOGICAL_TYPE>
void BaseREqFunctionIntegerDouble(DataChunk &args, ExpressionState &state, Vector &result) {
	using type = typename std::conditional<LOGICAL_TYPE == LogicalType::INTEGER, int32_t, bool>::type;

	auto parts = BinaryTypeAssert<LOGICAL_TYPE, LogicalType::DOUBLE>(args);
	BinaryExecutor::ExecuteWithNulls<double, type, bool>(parts.rights, parts.lefts, result, args.size(),
	                                                     ExecuteBaseREqFunctionDoubleInteger<type>);
}

static void BaseREqFunctionString(DataChunk &args, ExpressionState &state, Vector &result) {
	auto parts = BinaryTypeAssert<LogicalType::VARCHAR, LogicalType::VARCHAR>(args);
	BinaryExecutor::Execute<string_t, string_t, bool>(parts.lefts, parts.rights, result, args.size(),
	                                                  [&](string_t left, string_t right) { return (left == right); });
}

static bool ExecuteBaseREqFunctionStringInteger(string_t left, int32_t right) {
	char right_chr[100];
	snprintf(right_chr, sizeof(right_chr), "%d", right);
	return (left == right_chr);
}

static void BaseREqFunctionStringInteger(DataChunk &args, ExpressionState &state, Vector &result) {
	auto parts = BinaryTypeAssert<LogicalType::VARCHAR, LogicalType::INTEGER>(args);

	return BinaryExecutor::Execute<string_t, int32_t, bool>(parts.lefts, parts.rights, result, args.size(),
	                                                        &ExecuteBaseREqFunctionStringInteger);
}

static void BaseREqFunctionIntegerString(DataChunk &args, ExpressionState &state, Vector &result) {
	auto parts = BinaryTypeAssert<LogicalType::INTEGER, LogicalType::VARCHAR>(args);

	return BinaryExecutor::Execute<string_t, int32_t, bool>(parts.rights, parts.lefts, result, args.size(),
	                                                        &ExecuteBaseREqFunctionStringInteger);
}

static bool ExecuteBaseREqFunctionStringBoolean(string_t left, bool right) {
	return left == (right ? "TRUE" : "FALSE");
}

static void BaseREqFunctionStringBoolean(DataChunk &args, ExpressionState &state, Vector &result) {
	auto parts = BinaryTypeAssert<LogicalType::VARCHAR, LogicalType::BOOLEAN>(args);

	return BinaryExecutor::Execute<string_t, bool, bool>(parts.lefts, parts.rights, result, args.size(),
	                                                     &ExecuteBaseREqFunctionStringBoolean);
}

static void BaseREqFunctionBooleanString(DataChunk &args, ExpressionState &state, Vector &result) {
	auto parts = BinaryTypeAssert<LogicalType::BOOLEAN, LogicalType::VARCHAR>(args);

	return BinaryExecutor::Execute<string_t, bool, bool>(parts.rights, parts.lefts, result, args.size(),
	                                                     &ExecuteBaseREqFunctionStringBoolean);
}

static bool ExecuteBaseREqFunctionStringDouble(string_t left, double right) {
	char right_chr[100];
	snprintf(right_chr, sizeof(right_chr), "%.17g", right);
	return (left == right_chr);
}

static void BaseREqFunctionStringDouble(DataChunk &args, ExpressionState &state, Vector &result) {
	auto parts = BinaryTypeAssert<LogicalType::VARCHAR, LogicalType::DOUBLE>(args);

	return BinaryExecutor::Execute<string_t, double, bool>(parts.lefts, parts.rights, result, args.size(),
	                                                       &ExecuteBaseREqFunctionStringDouble);
}

static void BaseREqFunctionDoubleString(DataChunk &args, ExpressionState &state, Vector &result) {
	auto parts = BinaryTypeAssert<LogicalType::DOUBLE, LogicalType::VARCHAR>(args);

	return BinaryExecutor::Execute<string_t, double, bool>(parts.rights, parts.lefts, result, args.size(),
	                                                       &ExecuteBaseREqFunctionStringDouble);
}

} // namespace

ScalarFunctionSet base_r_eq() {
	ScalarFunctionSet set("r_base::==");
	// (int | lgl) == (int | lgl)
	set.AddFunction(ScalarFunction({LogicalType::BOOLEAN, LogicalType::BOOLEAN}, LogicalType::BOOLEAN,
	                               BaseREqFunctionSimple<LogicalType::BOOLEAN, bool, LogicalType::BOOLEAN, bool>));
	set.AddFunction(ScalarFunction({LogicalType::BOOLEAN, LogicalType::INTEGER}, LogicalType::BOOLEAN,
	                               BaseREqFunctionSimple<LogicalType::BOOLEAN, bool, LogicalType::INTEGER, int32_t>));
	set.AddFunction(ScalarFunction({LogicalType::INTEGER, LogicalType::BOOLEAN}, LogicalType::BOOLEAN,
	                               BaseREqFunctionSimple<LogicalType::INTEGER, int32_t, LogicalType::BOOLEAN, bool>));
	set.AddFunction(
	    ScalarFunction({LogicalType::INTEGER, LogicalType::INTEGER}, LogicalType::BOOLEAN,
	                   BaseREqFunctionSimple<LogicalType::INTEGER, int32_t, LogicalType::INTEGER, int32_t>));

	// double == (int | lgl)
	set.AddFunction(ScalarFunction({LogicalType::DOUBLE, LogicalType::INTEGER}, LogicalType::BOOLEAN,
	                               BaseREqFunctionDoubleInteger<LogicalType::INTEGER>));
	set.AddFunction(ScalarFunction({LogicalType::INTEGER, LogicalType::DOUBLE}, LogicalType::BOOLEAN,
	                               BaseREqFunctionIntegerDouble<LogicalType::INTEGER>));
	set.AddFunction(ScalarFunction({LogicalType::DOUBLE, LogicalType::BOOLEAN}, LogicalType::BOOLEAN,
	                               BaseREqFunctionDoubleInteger<LogicalType::BOOLEAN>));
	set.AddFunction(ScalarFunction({LogicalType::BOOLEAN, LogicalType::DOUBLE}, LogicalType::BOOLEAN,
	                               BaseREqFunctionIntegerDouble<LogicalType::BOOLEAN>));

	// string == int
	set.AddFunction(ScalarFunction({LogicalType::VARCHAR, LogicalType::INTEGER}, LogicalType::BOOLEAN,
	                               BaseREqFunctionStringInteger));
	set.AddFunction(ScalarFunction({LogicalType::INTEGER, LogicalType::VARCHAR}, LogicalType::BOOLEAN,
	                               BaseREqFunctionIntegerString));

	// string == lgl
	set.AddFunction(ScalarFunction({LogicalType::VARCHAR, LogicalType::BOOLEAN}, LogicalType::BOOLEAN,
	                               BaseREqFunctionStringBoolean));
	set.AddFunction(ScalarFunction({LogicalType::BOOLEAN, LogicalType::VARCHAR}, LogicalType::BOOLEAN,
	                               BaseREqFunctionBooleanString));

	set.AddFunction(
	    ScalarFunction({LogicalType::DOUBLE, LogicalType::DOUBLE}, LogicalType::BOOLEAN, BaseREqFunctionDouble));
	set.AddFunction(
	    ScalarFunction({LogicalType::VARCHAR, LogicalType::VARCHAR}, LogicalType::BOOLEAN, BaseREqFunctionString));
	set.AddFunction(
	    ScalarFunction({LogicalType::VARCHAR, LogicalType::DOUBLE}, LogicalType::BOOLEAN, BaseREqFunctionStringDouble));
	set.AddFunction(
	    ScalarFunction({LogicalType::DOUBLE, LogicalType::VARCHAR}, LogicalType::BOOLEAN, BaseREqFunctionDoubleString));

	return set;
}

} // namespace rfuns
} // namespace duckdb
