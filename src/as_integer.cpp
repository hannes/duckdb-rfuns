#include "rfuns_extension.hpp"
#include "duckdb/parser/parsed_data/create_scalar_function_info.hpp"
#include "duckdb/common/operator/double_cast_operator.hpp"

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

template <>
int32_t cast<string_t>(string_t input, ValidityMask &mask, idx_t idx) {
	double result;
	if (!TryDoubleCast<double>(input.GetData(), input.GetSize(), result, false)) {
		mask.SetInvalid(idx);
	}

	return cast<double>(result, mask, idx);
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

	set.AddFunction(AS_INTEGER(VARCHAR));

	return set;
}

}
}
