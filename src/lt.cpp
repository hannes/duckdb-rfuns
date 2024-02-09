#include "rfuns_extension.hpp"
#include "duckdb/parser/parsed_data/create_scalar_function_info.hpp"

#include <math.h>
#include <climits>

namespace duckdb {
namespace rfuns {

namespace {

template <LogicalTypeId LHS_LOGICAL, typename LHS, LogicalTypeId RHS_LOGICAL, typename RHS>
void BaseRLessThanFunctionSimple(DataChunk &args, ExpressionState &state, Vector &result) {
	auto parts = BinaryTypeAssert<LHS_LOGICAL, RHS_LOGICAL>(args);

	auto fun = [](LHS left, RHS right) {
		return (left < right);
	};
	BinaryExecutor::Execute<LHS, RHS, bool>(parts.lefts, parts.rights, result, args.size(), fun);
}

}

ScalarFunctionSet base_r_lt() {
	ScalarFunctionSet set("r_base::<");

	// (int | lgl) == (int | lgl)
	set.AddFunction(ScalarFunction({LogicalType::BOOLEAN, LogicalType::BOOLEAN}, LogicalType::BOOLEAN,
	                               BaseRLessThanFunctionSimple<LogicalType::BOOLEAN, bool, LogicalType::BOOLEAN, bool>));
	set.AddFunction(ScalarFunction({LogicalType::BOOLEAN, LogicalType::INTEGER}, LogicalType::BOOLEAN,
	                               BaseRLessThanFunctionSimple<LogicalType::BOOLEAN, bool, LogicalType::INTEGER, int32_t>));
	set.AddFunction(ScalarFunction({LogicalType::INTEGER, LogicalType::BOOLEAN}, LogicalType::BOOLEAN,
	                               BaseRLessThanFunctionSimple<LogicalType::INTEGER, int32_t, LogicalType::BOOLEAN, bool>));
	set.AddFunction(
	    ScalarFunction({LogicalType::INTEGER, LogicalType::INTEGER}, LogicalType::BOOLEAN,
	                   BaseRLessThanFunctionSimple<LogicalType::INTEGER, int32_t, LogicalType::INTEGER, int32_t>));


	return set;
}


}
}
