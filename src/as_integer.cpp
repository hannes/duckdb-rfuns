#include "rfuns_extension.hpp"
#include "duckdb/parser/parsed_data/create_scalar_function_info.hpp"

#include <math.h>
#include <climits>
#include <limits>

namespace duckdb {
namespace rfuns {

namespace {

template <typename T>
int32_t cast(T input, ValidityMask &mask, idx_t idx) {
	return static_cast<int32_t>(input);
}


template <>
int32_t cast<double>(double input, ValidityMask &mask, idx_t idx) {
	if (isnan(input) || input > std::numeric_limits<int32_t>::max() || input < std::numeric_limits<int32_t>::min() ) {
		mask.SetInvalid(idx);
	}

	return static_cast<int32_t>(input);
}

}

#define AS_INTEGER(__TYPE__) ScalarFunction(                                                      \
	{LogicalType::__TYPE__},                                                                      \
	LogicalType::INTEGER,                                                                         \
	[](DataChunk &args, ExpressionState &state, Vector &result) {                                 \
		UnaryExecutor::ExecuteWithNulls<typename physical<LogicalType::__TYPE__>::type, int32_t>( \
			args.data[0], result, args.size(),                                                    \
			cast<typename physical<LogicalType::__TYPE__>::type>                                  \
		);                                                                                        \
	})

ScalarFunctionSet base_r_as_integer() {
	ScalarFunctionSet set("r_base::as.integer");

	set.AddFunction(AS_INTEGER(BOOLEAN));
	set.AddFunction(AS_INTEGER(INTEGER));
	set.AddFunction(AS_INTEGER(DOUBLE));

	return set;
}

}
}
