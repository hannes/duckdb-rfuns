#include "rfuns_extension.hpp"

#include "duckdb/parser/parsed_data/create_aggregate_function_info.hpp"

#include <math.h>
#include <climits>
#include "duckdb/core_functions/aggregate/sum_helpers.hpp"
#include "duckdb/core_functions/aggregate/distributive_functions.hpp"

namespace duckdb {
namespace rfuns {

unique_ptr<FunctionData> BindRSum(ClientContext &context, AggregateFunction &function, vector<unique_ptr<Expression>> &arguments) {
	function = SumFun::GetFunctions().GetFunctionByArguments(context, {arguments[0]->return_type});
	return nullptr;
}

AggregateFunction RSum(const LogicalType& type) {
	return AggregateFunction(
		{type, LogicalType::BOOLEAN}, type,
		nullptr, nullptr, nullptr, nullptr, nullptr, FunctionNullHandling::DEFAULT_NULL_HANDLING, nullptr,
		BindRSum
	);
}

AggregateFunctionSet base_r_sum() {
	AggregateFunctionSet set("r_base::sum");

	set.AddFunction(RSum(LogicalType::INTEGER));
	set.AddFunction(RSum(LogicalType::DOUBLE));

	return set;
}

}
}
