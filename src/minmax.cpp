#include "rfuns_extension.hpp"

#include "duckdb/parser/parsed_data/create_aggregate_function_info.hpp"

#include <math.h>
#include <climits>
#include "duckdb/core_functions/aggregate/distributive_functions.hpp"

namespace duckdb {
namespace rfuns {

template <class T>
struct RMinMaxState {
	T value;
	bool is_set;
	bool is_null;
};

template <class MinMaxOP, bool NA_RM>
struct RMinMaxOperation {

	template <class STATE>
	static void Initialize(STATE &state) {
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
		} else if (!state.is_set ){
			state.value = input;
			state.is_set = true;
		} else {
			MinMaxOP::template Execute<STATE, INPUT_TYPE>(state, input);
		}
	}

	template <class INPUT_TYPE, class STATE, class OP>
	static void ConstantOperation(STATE &state, const INPUT_TYPE &input, AggregateUnaryInput &unary_input, idx_t count) {
		if (state.is_null) return;

		if (!NA_RM && !unary_input.RowIsValid()) {
			state.is_null = true;
		} else if (!state.is_set ){
			state.value = input;
			state.is_set = true;
		} else {
			MinMaxOP::template Execute<STATE, INPUT_TYPE>(state, input);
		}
	}

	template <class STATE, class OP>
	static void Combine(const STATE &source, STATE &target, AggregateInputData &) {
		if (!source.is_set) {
			return;
		}

		if (!target.is_set) {
			target = source;
		}
	}

	template <class T, class STATE>
	static void Finalize(STATE &state, T &target, AggregateFinalizeData &finalize_data) {
		if (state.is_null || !state.is_set) {
			finalize_data.ReturnNull();
		} else {
			target = state.value;
		}
	}
};

struct RMinOperation {
	template <class STATE, class INPUT_TYPE>
	static void Execute(STATE &state, INPUT_TYPE input) {
		if (LessThan::Operation<INPUT_TYPE>(input, state.value)) {
			state.value = input;
		}
	}

};

struct RMaxOperation {
	template <class STATE, class INPUT_TYPE>
	static void Execute(STATE &state, INPUT_TYPE input) {
		if (GreaterThan::Operation<INPUT_TYPE>(input, state.value)) {
			state.value = input;
		}
	}
};

template <typename OP, typename T, bool NA_RM>
unique_ptr<FunctionData> BindRMinMax_dispatch(ClientContext &context, AggregateFunction &function, vector<unique_ptr<Expression>> &arguments) {
	auto type = arguments[0]->return_type;
	function = AggregateFunction::UnaryAggregate<RMinMaxState<T>, T, T, RMinMaxOperation<OP, NA_RM>>(type, type) ;
	return nullptr;
}

template <typename OP, typename T>
unique_ptr<FunctionData> BindRMinMax(ClientContext &context, AggregateFunction &function, vector<unique_ptr<Expression>> &arguments) {
	auto na_rm = arguments[1]->ToString() == "true";
	if (na_rm) {
		return BindRMinMax_dispatch<OP, T, true>(context, function, arguments);
	} else {
		return BindRMinMax_dispatch<OP, T, false>(context, function, arguments);
	}
}

template <typename OP, LogicalTypeId TYPE>
void add_RMinMax(AggregateFunctionSet& set) {
	set.AddFunction(AggregateFunction(
		{TYPE, LogicalType::BOOLEAN}, TYPE,
		nullptr, nullptr, nullptr, nullptr, nullptr, FunctionNullHandling::DEFAULT_NULL_HANDLING, nullptr,
		BindRMinMax<OP, typename physical<TYPE>::type>
	));

	set.AddFunction(AggregateFunction(
		{TYPE}, TYPE,
		nullptr, nullptr, nullptr, nullptr, nullptr, FunctionNullHandling::DEFAULT_NULL_HANDLING, nullptr,
		BindRMinMax_dispatch<OP, typename physical<TYPE>::type, false>
	));
}

template <typename OP>
AggregateFunctionSet base_r_minmax(std::string name) {
	AggregateFunctionSet set(name);

	add_RMinMax<OP, LogicalType::BOOLEAN>(set);
	add_RMinMax<OP, LogicalType::INTEGER>(set);
	add_RMinMax<OP, LogicalType::DOUBLE>(set);
	add_RMinMax<OP, LogicalType::TIMESTAMP>(set);

	return set;
}

AggregateFunctionSet base_r_min() {
	return base_r_minmax<RMinOperation>("r_base::min");
}

AggregateFunctionSet base_r_max() {
	return base_r_minmax<RMaxOperation>("r_base::max");
}


}
}
