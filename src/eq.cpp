#include "rfuns_extension.hpp"
#include "duckdb/parser/parsed_data/create_scalar_function_info.hpp"

#include <math.h>
#include <climits>
#include <tuple>

namespace duckdb {
namespace rfuns {

namespace {

struct EqChunk {
    duckdb::Vector& lefts;
    duckdb::Vector& rights;
};

template <LogicalTypeId LHS_LOGICAL_TYPE, LogicalTypeId RHS_LOGICAL_TYPE>
EqChunk EqTypeAssert(DataChunk &args) {
    auto &lefts = args.data[0];
    D_ASSERT(lefts.GetType() == LHS_LOGICAL_TYPE);

    auto &rights = args.data[1];
    D_ASSERT(rights.GetType() == LHS_LOGICAL_TYPE);

    return {lefts, rights};
}

template <LogicalTypeId LHS_LOGICAL, typename LHS, LogicalTypeId RHS_LOGICAL, typename RHS>
void BaseREqFunctionSimple(DataChunk &args, ExpressionState &state, Vector &result) {
    auto parts = EqTypeAssert<LHS_LOGICAL, RHS_LOGICAL>(args);

    auto fun = [](LHS left, RHS right) { return (left == right); };
    BinaryExecutor::Execute<LHS, RHS, bool>(parts.lefts, parts.rights, result, args.size(), fun);
}

void BaseREqFunctionInteger(DataChunk &args, ExpressionState &state, Vector &result) {
    auto parts = EqTypeAssert<LogicalType::INTEGER, LogicalType::INTEGER>(args);

    auto fun = [](int32_t left, int32_t right) { return (left == right); };
    BinaryExecutor::Execute<int32_t, int32_t, bool>(parts.lefts, parts.rights, result, args.size(), fun);
}

void BaseREqFunctionDouble(DataChunk &args, ExpressionState &state, Vector &result) {
    auto parts = EqTypeAssert<LogicalType::DOUBLE, LogicalType::DOUBLE>(args);
	auto fun = [&](double left, double right, ValidityMask &mask, idx_t idx) {
        if (isnan(left) || isnan(right)) {
            mask.SetInvalid(idx);
            return false;
        }
        return (left == right);
    };

    BinaryExecutor::ExecuteWithNulls<double, double, bool>(parts.lefts, parts.rights, result, args.size(), fun);
}

bool ExecuteBaseREqFunctionDoubleInteger(double left, int32_t right, ValidityMask &mask, idx_t idx) {
    if (isnan(left)) {
        mask.SetInvalid(idx);
        return false;
    }
    return (left == right);
}

void BaseREqFunctionDoubleInteger(DataChunk &args, ExpressionState &state, Vector &result) {
    auto parts = EqTypeAssert<LogicalType::DOUBLE, LogicalType::INTEGER>(args);
	BinaryExecutor::ExecuteWithNulls<double, int32_t, bool>(parts.lefts, parts.rights, result, args.size(), 
        ExecuteBaseREqFunctionDoubleInteger
    );
}

void BaseREqFunctionIntegerDouble(DataChunk &args, ExpressionState &state, Vector &result) {
    auto parts = EqTypeAssert<LogicalType::INTEGER, LogicalType::DOUBLE>(args);
	BinaryExecutor::ExecuteWithNulls<double, int32_t, bool>(parts.rights, parts.lefts, result, args.size(), 
        ExecuteBaseREqFunctionDoubleInteger
    );
}

static void BaseREqFunctionString(DataChunk &args, ExpressionState &state, Vector &result) {
	auto parts = EqTypeAssert<LogicalType::VARCHAR, LogicalType::VARCHAR>(args);
	BinaryExecutor::Execute<string_t, string_t, bool>(parts.lefts, parts.rights, result, args.size(),
	                                                  [&](string_t left, string_t right) { return (left == right); });
}

static bool ExecuteBaseREqFunctionStringInteger(string_t left, int32_t right) {
	char right_chr[100];
	snprintf(right_chr, sizeof(right_chr), "%d", right);
	return (left == right_chr);
}

static void BaseREqFunctionStringInteger(DataChunk &args, ExpressionState &state, Vector &result) {
	auto parts = EqTypeAssert<LogicalType::VARCHAR, LogicalType::INTEGER>(args);
    
	return BinaryExecutor::Execute<string_t, int32_t, bool>(parts.lefts, parts.rights, result, args.size(),
	                                                        &ExecuteBaseREqFunctionStringInteger);
}

static void BaseREqFunctionIntegerString(DataChunk &args, ExpressionState &state, Vector &result) {
	auto parts = EqTypeAssert<LogicalType::INTEGER, LogicalType::VARCHAR>(args);

	return BinaryExecutor::Execute<string_t, int32_t, bool>(parts.rights, parts.lefts, result, args.size(),
	                                                        &ExecuteBaseREqFunctionStringInteger);
}

static bool ExecuteBaseREqFunctionStringDouble(string_t left, double right) {
	char right_chr[100];
	snprintf(right_chr, sizeof(right_chr), "%.17g", right);
	return (left == right_chr);
}

static void BaseREqFunctionStringDouble(DataChunk &args, ExpressionState &state, Vector &result) {
	auto parts = EqTypeAssert<LogicalType::VARCHAR, LogicalType::DOUBLE>(args);
    
	return BinaryExecutor::Execute<string_t, double, bool>(parts.lefts, parts.rights, result, args.size(),
	                                                       &ExecuteBaseREqFunctionStringDouble);
}

static void BaseREqFunctionDoubleString(DataChunk &args, ExpressionState &state, Vector &result) {
	auto parts = EqTypeAssert<LogicalType::DOUBLE, LogicalType::VARCHAR>(args);

	return BinaryExecutor::Execute<string_t, double, bool>(parts.rights, parts.lefts, result, args.size(),
	                                                       &ExecuteBaseREqFunctionStringDouble);
}

}

ScalarFunctionSet base_r_eq() {
    ScalarFunctionSet set("r_base::==");
    // (int | lgl) == (int | lgl) 
    set.AddFunction(ScalarFunction({LogicalType::BOOLEAN, LogicalType::BOOLEAN}, LogicalType::BOOLEAN, BaseREqFunctionSimple<LogicalType::BOOLEAN, bool   , LogicalType::BOOLEAN, bool>));
    set.AddFunction(ScalarFunction({LogicalType::BOOLEAN, LogicalType::INTEGER}, LogicalType::BOOLEAN, BaseREqFunctionSimple<LogicalType::BOOLEAN, bool   , LogicalType::INTEGER, int32_t>));
    set.AddFunction(ScalarFunction({LogicalType::INTEGER, LogicalType::BOOLEAN}, LogicalType::BOOLEAN, BaseREqFunctionSimple<LogicalType::INTEGER, int32_t, LogicalType::BOOLEAN, bool>));    
    set.AddFunction(ScalarFunction({LogicalType::INTEGER, LogicalType::INTEGER}, LogicalType::BOOLEAN, BaseREqFunctionSimple<LogicalType::INTEGER, int32_t, LogicalType::INTEGER, int32_t>));    

    // double == int
    set.AddFunction(ScalarFunction({LogicalType::DOUBLE, LogicalType::INTEGER}, LogicalType::BOOLEAN, BaseREqFunctionDoubleInteger));
    set.AddFunction(ScalarFunction({LogicalType::INTEGER, LogicalType::DOUBLE}, LogicalType::BOOLEAN, BaseREqFunctionIntegerDouble));

	set.AddFunction(ScalarFunction({LogicalType::DOUBLE, LogicalType::DOUBLE}, LogicalType::BOOLEAN, BaseREqFunctionDouble));
	set.AddFunction(ScalarFunction({LogicalType::VARCHAR, LogicalType::VARCHAR}, LogicalType::BOOLEAN, BaseREqFunctionString));
	set.AddFunction(ScalarFunction({LogicalType::VARCHAR, LogicalType::INTEGER}, LogicalType::BOOLEAN,BaseREqFunctionStringInteger));
	set.AddFunction(ScalarFunction({LogicalType::INTEGER, LogicalType::VARCHAR}, LogicalType::BOOLEAN,BaseREqFunctionIntegerString));
	set.AddFunction(ScalarFunction({LogicalType::VARCHAR, LogicalType::DOUBLE}, LogicalType::BOOLEAN, BaseREqFunctionStringDouble));
	set.AddFunction(ScalarFunction({LogicalType::DOUBLE, LogicalType::VARCHAR}, LogicalType::BOOLEAN, BaseREqFunctionDoubleString));

    return set;
}

}
}
