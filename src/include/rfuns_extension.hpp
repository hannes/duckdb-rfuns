#pragma once

#include "duckdb.hpp"

namespace duckdb {
namespace rfuns {

struct BinaryChunk {
	duckdb::Vector &lefts;
	duckdb::Vector &rights;
};

template <LogicalTypeId LHS_LOGICAL_TYPE, LogicalTypeId RHS_LOGICAL_TYPE>
BinaryChunk BinaryTypeAssert(DataChunk &args) {
	auto &lefts = args.data[0];
	D_ASSERT(lefts.GetType() == LHS_LOGICAL_TYPE);

	auto &rights = args.data[1];
	D_ASSERT(rights.GetType() == LHS_LOGICAL_TYPE);

	return {lefts, rights};
}

ScalarFunctionSet base_r_add();

// relop
ScalarFunctionSet base_r_eq();
ScalarFunctionSet base_r_neq();
ScalarFunctionSet base_r_lt();
ScalarFunctionSet base_r_lte();
ScalarFunctionSet base_r_gt();
ScalarFunctionSet base_r_gte();

// sum
AggregateFunctionSet base_r_sum();

ScalarFunctionSet binary_dispatch(ScalarFunctionSet fn) ;

// is_na
ScalarFunctionSet base_r_is_na();

} // namespace rfuns

class RfunsExtension : public Extension {
public:
	void Load(DuckDB &db) override;
	std::string Name() override;
};

} // namespace duckdb
