#define DUCKDB_EXTENSION_MAIN

#include "rfuns_extension.hpp"
#include "duckdb.hpp"
#include "duckdb/common/exception.hpp"
#include "duckdb/common/string_util.hpp"
#include "duckdb/function/scalar_function.hpp"
#include "duckdb/main/extension_util.hpp"
#include <duckdb/parser/parsed_data/create_scalar_function_info.hpp>

// OpenSSL linked through vcpkg
#include <openssl/opensslv.h>

namespace duckdb {

inline void RfunsScalarFun(DataChunk &args, ExpressionState &state, Vector &result) {
    auto &name_vector = args.data[0];
    UnaryExecutor::Execute<string_t, string_t>(
	    name_vector, result, args.size(),
	    [&](string_t name) {
			return StringVector::AddString(result, "Rfuns "+name.GetString()+" 🐥");;
        });
}

inline void RfunsOpenSSLVersionScalarFun(DataChunk &args, ExpressionState &state, Vector &result) {
    auto &name_vector = args.data[0];
    UnaryExecutor::Execute<string_t, string_t>(
	    name_vector, result, args.size(),
	    [&](string_t name) {
			return StringVector::AddString(result, "Rfuns " + name.GetString() +
                                                     ", my linked OpenSSL version is " +
                                                     OPENSSL_VERSION_TEXT );;
        });
}

static void LoadInternal(DatabaseInstance &instance) {
    // Register a scalar function
    auto rfuns_scalar_function = ScalarFunction("rfuns", {LogicalType::VARCHAR}, LogicalType::VARCHAR, RfunsScalarFun);
    ExtensionUtil::RegisterFunction(instance, rfuns_scalar_function);

    // Register another scalar function
    auto rfuns_openssl_version_scalar_function = ScalarFunction("rfuns_openssl_version", {LogicalType::VARCHAR},
                                                LogicalType::VARCHAR, RfunsOpenSSLVersionScalarFun);
    ExtensionUtil::RegisterFunction(instance, rfuns_openssl_version_scalar_function);
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
