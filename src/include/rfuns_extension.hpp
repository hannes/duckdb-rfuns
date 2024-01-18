#pragma once

#include "duckdb.hpp"

namespace duckdb {
namespace rfuns {

ScalarFunctionSet base_r_add();
ScalarFunctionSet base_r_eq();

}

class RfunsExtension : public Extension {
public:
	void Load(DuckDB &db) override;
	std::string Name() override;
};

} // namespace duckdb
