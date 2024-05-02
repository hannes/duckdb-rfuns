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
namespace rfuns {

static void register_binary(DatabaseInstance &instance, ScalarFunctionSet fun) {
	// fun()
	ExtensionUtil::RegisterFunction(instance, fun);

	// dispatch(fun())
	ExtensionUtil::RegisterFunction(instance, binary_dispatch(fun));
}

static void register_rfuns(DatabaseInstance &instance) {
	// +
	register_binary(instance, base_r_add());

	// relop
	register_binary(instance, base_r_eq());
	register_binary(instance, base_r_neq());
	register_binary(instance, base_r_lt());
	register_binary(instance, base_r_lte());
	register_binary(instance, base_r_gt());
	register_binary(instance, base_r_gte());

	ExtensionUtil::RegisterFunction(instance, base_r_is_na());
	ExtensionUtil::RegisterFunction(instance, base_r_as_integer());
	// ExtensionUtil::RegisterFunction(instance, base_r_as_numeric());

	ExtensionUtil::RegisterFunction(instance, base_r_sum());
	ExtensionUtil::RegisterFunction(instance, base_r_min());
	ExtensionUtil::RegisterFunction(instance, base_r_max());
}
}  // namespace rfuns

static void LoadInternal(DatabaseInstance &instance) {
	rfuns::register_rfuns(instance);
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
