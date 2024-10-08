#include "rfuns_extension.hpp"

#include "duckdb/parser/parsed_data/create_aggregate_function_info.hpp"

#include <math.h>
#include <climits>
#include "duckdb/core_functions/aggregate/sum_helpers.hpp"
#include "duckdb/core_functions/aggregate/distributive_functions.hpp"

namespace duckdb {
namespace rfuns {

template <class T>
struct RSumKeepNaState {
	T value;
	bool is_set;
	bool is_null;
};

template <class ADDOP, bool NA_RM>
struct RSumOperation {

	template <class STATE>
	static void Initialize(STATE &state) {
		state.value = 0;
		state.is_set = false;
		state.is_null = false;
	}

	static bool IgnoreNull() {
		return NA_RM;
	}

	template <class INPUT_TYPE, class STATE, class OP>
	static void Operation(STATE &state, const INPUT_TYPE &input, AggregateUnaryInput &unary_input) {
		if (state.is_null) return;
		if (!NA_RM && !unary_input.RowIsValid()) {
			state.is_null = true;
		} else {
			if (!state.is_set) {
				state.is_set = true;
			}
			ADDOP::template AddNumber<STATE, INPUT_TYPE>(state, input);
		}
	}

	template <class INPUT_TYPE, class STATE, class OP>
	static void ConstantOperation(STATE &state, const INPUT_TYPE &input, AggregateUnaryInput &unary_input, idx_t count) {
		if (!NA_RM && !unary_input.RowIsValid()) {
			state.is_null = true;
		} else {
			if (!state.is_set) {
				state.is_set = true;
			}
			ADDOP::template AddConstant<STATE, INPUT_TYPE>(state, input, count);
		}
	}

	template <class STATE, class OP>
	static void Combine(const STATE &source, STATE &target, AggregateInputData &) {
		if (!target.is_set) {
			target = source;
		}
	}

	template <class T, class STATE>
	static void Finalize(STATE &state, T &target, AggregateFinalizeData &finalize_data) {
		if (state.is_null) {
			finalize_data.ReturnNull();
		} else {
			target = state.value;
		}
	}
};

template <bool NA_RM>
unique_ptr<FunctionData> BindRSum_dispatch(ClientContext &context, AggregateFunction &function, vector<unique_ptr<Expression>> &arguments) {
	auto type = arguments[0]->return_type;

	switch (type.id()) {
	case LogicalTypeId::DOUBLE:
		function = AggregateFunction::UnaryAggregate<RSumKeepNaState<double>, double, double, RSumOperation<RegularAdd, NA_RM>>(type, type);
		break;
	case LogicalTypeId::INTEGER:
		function = AggregateFunction::UnaryAggregate<RSumKeepNaState<double>, int32_t, double, RSumOperation<RegularAdd, NA_RM>>(type, LogicalTypeId::DOUBLE);
		break;
	case LogicalTypeId::BOOLEAN:
		function = AggregateFunction::UnaryAggregate<RSumKeepNaState<int32_t>, bool, int32_t, RSumOperation<RegularAdd, NA_RM>>(type, LogicalType::INTEGER);
		break;
	default:
		break;
	}

	return nullptr;
}

unique_ptr<FunctionData> BindRSum(ClientContext &context, AggregateFunction &function, vector<unique_ptr<Expression>> &arguments) {
	auto na_rm = arguments[1]->ToString() == "true";
	if (na_rm) {
		return BindRSum_dispatch<true>(context, function, arguments);
	} else {
		return BindRSum_dispatch<false>(context, function, arguments);
	}
}

void add_RSum(AggregateFunctionSet& set, const LogicalType& type, const LogicalType& return_type) {
	set.AddFunction(AggregateFunction(
		{type, LogicalType::BOOLEAN}, return_type,
		nullptr, nullptr, nullptr, nullptr, nullptr, FunctionNullHandling::DEFAULT_NULL_HANDLING, nullptr,
		BindRSum
	));

	set.AddFunction(AggregateFunction(
		{type}, return_type,
		nullptr, nullptr, nullptr, nullptr, nullptr, FunctionNullHandling::DEFAULT_NULL_HANDLING, nullptr,
		BindRSum_dispatch<false>
	));
}

AggregateFunctionSet base_r_sum() {
	AggregateFunctionSet set("r_base::sum");

	add_RSum(set, LogicalType::BOOLEAN, LogicalType::INTEGER);
	add_RSum(set, LogicalType::INTEGER, LogicalType::DOUBLE);
	add_RSum(set, LogicalType::DOUBLE, LogicalType::DOUBLE);

	return set;
}

}
}
