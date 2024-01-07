#define DUCKDB_EXTENSION_MAIN

#include "rfuns_extension.hpp"
#include "duckdb.hpp"
#include "duckdb/common/exception.hpp"
#include "duckdb/function/scalar_function.hpp"
#include "duckdb/main/extension_util.hpp"
#include "duckdb/parser/parsed_data/create_scalar_function_info.hpp"

#include <math.h>
#include <climits>

namespace duckdb {

static void BaseRAddFunctionInteger(DataChunk &args, ExpressionState &state, Vector &result) {
	auto &lefts = args.data[0];
	D_ASSERT(lefts.GetType() == LogicalType::INTEGER);
	auto &rights = args.data[1];
	D_ASSERT(rights.GetType() == LogicalType::INTEGER);
	BinaryExecutor::ExecuteWithNulls<int32_t, int32_t, int32_t>(
	    lefts, rights, result, args.size(), [&](int32_t left, int32_t right, ValidityMask &mask, idx_t idx) {
		    int64_t result = (int64_t)left + right;
		    if (result > INT_MAX || result < (INT_MIN + 1)) {
			    // FIXME: Need warning: NAs produced by integer overflow
			    mask.SetInvalid(idx);
			    return 0;
		    }
		    return (int32_t)result;
	    });
}

static void BaseRAddFunctionDouble(DataChunk &args, ExpressionState &state, Vector &result) {
	auto &lefts = args.data[0];
	D_ASSERT(lefts.GetType() == LogicalType::DOUBLE);
	auto &rights = args.data[1];
	D_ASSERT(rights.GetType() == LogicalType::DOUBLE);
	BinaryExecutor::ExecuteWithNulls<double, double, double>(
	    lefts, rights, result, args.size(), [&](double left, double right, ValidityMask &mask, idx_t idx) {
		    if (isnan(left) || isnan(right)) {
			    mask.SetInvalid(idx);
			    return 0.0;
		    }
		    return left + right;
	    });
}

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

inline void RfunsScalarFun(DataChunk &args, ExpressionState &state, Vector &result) {
	auto &name_vector = args.data[0];
	UnaryExecutor::Execute<string_t, string_t>(name_vector, result, args.size(), [&](string_t name) {
		return StringVector::AddString(result, "Rfuns " + name.GetString() + " 🐥");
		;
	});
}

static void LoadInternal(DatabaseInstance &instance) {
	ScalarFunctionSet base_r_add("r_base::+");
	base_r_add.AddFunction(
	    ScalarFunction({LogicalType::INTEGER, LogicalType::INTEGER}, LogicalType::INTEGER, BaseRAddFunctionInteger));
	base_r_add.AddFunction(
	    ScalarFunction({LogicalType::DOUBLE, LogicalType::DOUBLE}, LogicalType::DOUBLE, BaseRAddFunctionDouble));

	ExtensionUtil::RegisterFunction(instance, base_r_add);

	ScalarFunctionSet base_r_eq("r_base::==");
	base_r_eq.AddFunction(
	    ScalarFunction({LogicalType::INTEGER, LogicalType::INTEGER}, LogicalType::BOOLEAN, BaseREqFunctionInteger));
	base_r_eq.AddFunction(
	    ScalarFunction({LogicalType::DOUBLE, LogicalType::DOUBLE}, LogicalType::BOOLEAN, BaseREqFunctionDouble));
	base_r_eq.AddFunction(
	    ScalarFunction({LogicalType::VARCHAR, LogicalType::VARCHAR}, LogicalType::BOOLEAN, BaseREqFunctionString));
	base_r_eq.AddFunction(
	    ScalarFunction({LogicalType::VARCHAR, LogicalType::INTEGER}, LogicalType::BOOLEAN, BaseREqFunctionStringInteger));
	base_r_eq.AddFunction(
	    ScalarFunction({LogicalType::INTEGER, LogicalType::VARCHAR}, LogicalType::BOOLEAN, BaseREqFunctionIntegerString));
	base_r_eq.AddFunction(
	    ScalarFunction({LogicalType::VARCHAR, LogicalType::DOUBLE}, LogicalType::BOOLEAN, BaseREqFunctionStringDouble));
	base_r_eq.AddFunction(
	    ScalarFunction({LogicalType::DOUBLE, LogicalType::VARCHAR}, LogicalType::BOOLEAN, BaseREqFunctionDoubleString));

	ExtensionUtil::RegisterFunction(instance, base_r_eq);

	// Register a scalar function
	auto rfuns_scalar_function = ScalarFunction("rfuns", {LogicalType::VARCHAR}, LogicalType::VARCHAR, RfunsScalarFun);
	ExtensionUtil::RegisterFunction(instance, rfuns_scalar_function);
}

void RfunsExtension::Load(DuckDB &db) {
	LoadInternal(*db.instance);
}
std::string RfunsExtension::Name() {
	return "rfuns";
}

} // namespace duckdb

extern "C" {

DUCKDB_EXTENSION_API void rfuns_init(duckdb::DatabaseInstance &db) {
	duckdb::DuckDB db_wrapper(db);
	db_wrapper.LoadExtension<duckdb::RfunsExtension>();
}

DUCKDB_EXTENSION_API const char *rfuns_version() {
	return duckdb::DuckDB::LibraryVersion();
}
}

#ifndef DUCKDB_EXTENSION_MAIN
#error DUCKDB_EXTENSION_MAIN not defined
#endif
