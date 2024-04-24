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

template <class ADDOP>
struct RSumKeepNaOperation {

	template <class STATE>
	static void Initialize(STATE &state) {
		state.is_set = false;
		state.is_null = false;
		state.value = 0;
	}

	static bool IgnoreNull() {
		return false;
	}

	template <class INPUT_TYPE, class STATE, class OP>
	static void Operation(STATE &state, const INPUT_TYPE &input, AggregateUnaryInput &unary_input) {
		if (state.is_null) return;
		state.is_set = true;
		if (!unary_input.RowIsValid()) {
			state.is_null = true;
		} else {
			ADDOP::template AddNumber<STATE, INPUT_TYPE>(state, input);
		}
	}

	template <class INPUT_TYPE, class STATE, class OP>
	static void ConstantOperation(STATE &state, const INPUT_TYPE &input, AggregateUnaryInput &unary_input, idx_t count) {
		if (!unary_input.RowIsValid()) {
			state.is_null = true;
		} else {
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
		if (!state.is_set || state.is_null) {
			finalize_data.ReturnNull();
		} else {
			target = state.value;
		}
	}
};

unique_ptr<FunctionData> BindRSum(ClientContext &context, AggregateFunction &function, vector<unique_ptr<Expression>> &arguments) {
	auto& na_rm = arguments[1];

	auto na_keep = na_rm->ToString() != "true";
	if (na_keep) {
		auto type = arguments[0]->return_type;
		switch (type.id()) {
		case LogicalTypeId::DOUBLE:
			function = AggregateFunction::UnaryAggregate<RSumKeepNaState<double>, double, double, RSumKeepNaOperation<RegularAdd>>(type, type);
			break;
		case LogicalTypeId::INTEGER:
			function = AggregateFunction::UnaryAggregate<RSumKeepNaState<hugeint_t>, int32_t, hugeint_t, RSumKeepNaOperation<HugeintAdd>>(type, type);
			break;
		default:
			break;
		}
	} else {
		function = SumFun::GetFunctions().GetFunctionByArguments(context, {arguments[0]->return_type});
	}

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
