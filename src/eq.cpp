#include "rfuns_extension.hpp"
#include "duckdb/parser/parsed_data/create_scalar_function_info.hpp"

#include <math.h>
#include <climits>

namespace duckdb {
namespace rfuns {

namespace {

static void BaseREqFunctionInteger(DataChunk &args, ExpressionState &state, Vector &result) {
	auto &lefts = args.data[0];
	D_ASSERT(lefts.GetType() == LogicalType::INTEGER);
	auto &rights = args.data[1];
	D_ASSERT(rights.GetType() == LogicalType::INTEGER);
	BinaryExecutor::Execute<int32_t, int32_t, bool>(lefts, rights, result, args.size(),
	                                                [&](int32_t left, int32_t right) { return (left == right); });
}

static void BaseREqFunctionDouble(DataChunk &args, ExpressionState &state, Vector &result) {
	auto &lefts = args.data[0];
	D_ASSERT(lefts.GetType() == LogicalType::DOUBLE);
	auto &rights = args.data[1];
	D_ASSERT(rights.GetType() == LogicalType::DOUBLE);
	BinaryExecutor::ExecuteWithNulls<double, double, bool>(
	    lefts, rights, result, args.size(), [&](double left, double right, ValidityMask &mask, idx_t idx) {
		    if (isnan(left) || isnan(right)) {
			    mask.SetInvalid(idx);
			    return false;
		    }
		    return (left == right);
	    });
}

static void BaseREqFunctionString(DataChunk &args, ExpressionState &state, Vector &result) {
	auto &lefts = args.data[0];
	D_ASSERT(lefts.GetType() == LogicalType::VARCHAR);
	auto &rights = args.data[1];
	D_ASSERT(rights.GetType() == LogicalType::VARCHAR);
	BinaryExecutor::Execute<string_t, string_t, bool>(lefts, rights, result, args.size(),
	                                                  [&](string_t left, string_t right) { return (left == right); });
}

static bool ExecuteBaseREqFunctionStringInteger(string_t left, int32_t right) {
	char right_chr[100];
	snprintf(right_chr, sizeof(right_chr), "%d", right);
	return (left == right_chr);
}

static void BaseREqFunctionStringInteger(DataChunk &args, ExpressionState &state, Vector &result) {
	auto &lefts = args.data[0];
	D_ASSERT(lefts.GetType() == LogicalType::VARCHAR);
	auto &rights = args.data[1];
	D_ASSERT(rights.GetType() == LogicalType::INTEGER);

	return BinaryExecutor::Execute<string_t, int32_t, bool>(lefts, rights, result, args.size(),
	                                                        &ExecuteBaseREqFunctionStringInteger);
}

static void BaseREqFunctionIntegerString(DataChunk &args, ExpressionState &state, Vector &result) {
	auto &lefts = args.data[0];
	D_ASSERT(lefts.GetType() == LogicalType::INTEGER);
	auto &rights = args.data[1];
	D_ASSERT(rights.GetType() == LogicalType::VARCHAR);

	return BinaryExecutor::Execute<string_t, int32_t, bool>(rights, lefts, result, args.size(),
	                                                        &ExecuteBaseREqFunctionStringInteger);
}

static bool ExecuteBaseREqFunctionStringDouble(string_t left, double right) {
	char right_chr[100];
	snprintf(right_chr, sizeof(right_chr), "%.17g", right);
	return (left == right_chr);
}

static void BaseREqFunctionStringDouble(DataChunk &args, ExpressionState &state, Vector &result) {
	auto &lefts = args.data[0];
	D_ASSERT(lefts.GetType() == LogicalType::VARCHAR);
	auto &rights = args.data[1];
	D_ASSERT(rights.GetType() == LogicalType::DOUBLE);

	return BinaryExecutor::Execute<string_t, double, bool>(lefts, rights, result, args.size(),
	                                                       &ExecuteBaseREqFunctionStringDouble);
}

static void BaseREqFunctionDoubleString(DataChunk &args, ExpressionState &state, Vector &result) {
	auto &lefts = args.data[0];
	D_ASSERT(lefts.GetType() == LogicalType::DOUBLE);
	auto &rights = args.data[1];
	D_ASSERT(rights.GetType() == LogicalType::VARCHAR);

	return BinaryExecutor::Execute<string_t, double, bool>(rights, lefts, result, args.size(),
	                                                       &ExecuteBaseREqFunctionStringDouble);
}

}

ScalarFunctionSet base_r_eq() {
    ScalarFunctionSet set("r_base::==");
	set.AddFunction(
	    ScalarFunction({LogicalType::INTEGER, LogicalType::INTEGER}, LogicalType::BOOLEAN, BaseREqFunctionInteger));
	set.AddFunction(
	    ScalarFunction({LogicalType::DOUBLE, LogicalType::DOUBLE}, LogicalType::BOOLEAN, BaseREqFunctionDouble));
	set.AddFunction(
	    ScalarFunction({LogicalType::VARCHAR, LogicalType::VARCHAR}, LogicalType::BOOLEAN, BaseREqFunctionString));
	set.AddFunction(ScalarFunction({LogicalType::VARCHAR, LogicalType::INTEGER}, LogicalType::BOOLEAN,
	                                     BaseREqFunctionStringInteger));
	set.AddFunction(ScalarFunction({LogicalType::INTEGER, LogicalType::VARCHAR}, LogicalType::BOOLEAN,
	                                     BaseREqFunctionIntegerString));
	set.AddFunction(
	    ScalarFunction({LogicalType::VARCHAR, LogicalType::DOUBLE}, LogicalType::BOOLEAN, BaseREqFunctionStringDouble));
	set.AddFunction(
	    ScalarFunction({LogicalType::DOUBLE, LogicalType::VARCHAR}, LogicalType::BOOLEAN, BaseREqFunctionDoubleString));

    return set;
}

}
}
