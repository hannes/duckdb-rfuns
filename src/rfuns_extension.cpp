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

inline void RfunsScalarFun(DataChunk &args, ExpressionState &state, Vector &result) {
	auto &name_vector = args.data[0];
	UnaryExecutor::Execute<string_t, string_t>(name_vector, result, args.size(), [&](string_t name) {
		return StringVector::AddString(result, "Rfuns " + name.GetString() + " 🐥");
		;
	});
}

static void LoadInternal(DatabaseInstance &instance) {
	ExtensionUtil::RegisterFunction(instance, rfuns::base_r_add());
	ExtensionUtil::RegisterFunction(instance, rfuns::base_r_eq());
	
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
