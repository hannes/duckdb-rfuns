#include "rfuns_extension.hpp"
#include "duckdb/parser/parsed_data/create_scalar_function_info.hpp"

#include <math.h>
#include <climits>
#include <iostream>
#include <cmath>

#include <unordered_set>

namespace duckdb {
namespace rfuns {

template <typename T>
void in(DataChunk &args, ExpressionState &state, Vector &result) {
	auto y = args.data[1];
	auto size = ListVector::GetListSize(y);
	auto y_data = FlatVector::GetData<T>(ListVector::GetEntry(y));

	// TODO: handle NA in set
	auto set = unordered_set<T>();
	for (int i = 0; i < size; i++) {
		set.insert(y_data[i]);
	}

	UnaryExecutor::ExecuteWithNulls<T, bool>(
		args.data[0], result, args.size(), [&](T input, ValidityMask &mask, idx_t idx) {
			// TODO: handle NA in set
			return set.count(input) != 0;
		}
	);

}

ScalarFunctionSet base_r_in() {
	ScalarFunctionSet set("r_base::%in%");

	set.AddFunction(ScalarFunction({LogicalType::DOUBLE, LogicalType::LIST(LogicalType::DOUBLE)}, LogicalType::BOOLEAN, in<double>));
	set.AddFunction(ScalarFunction({LogicalType::INTEGER, LogicalType::LIST(LogicalType::INTEGER)}, LogicalType::BOOLEAN, in<int32_t>));
	set.AddFunction(ScalarFunction({LogicalType::BOOLEAN, LogicalType::LIST(LogicalType::BOOLEAN)}, LogicalType::BOOLEAN, in<bool>));

	return set;
}

}
}
