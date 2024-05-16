#include "rfuns_extension.hpp"
#include "duckdb/parser/parsed_data/create_scalar_function_info.hpp"
#include "duckdb/common/operator/double_cast_operator.hpp"

#include <math.h>
#include <climits>
#include <limits>
#include <cmath>

namespace duckdb {
namespace rfuns {

namespace {

template <typename T>
int32_t check_int_range(T value, ValidityMask &mask, idx_t idx) {
	if (value > std::numeric_limits<int32_t>::max() || value < std::numeric_limits<int32_t>::min() ) {
		mask.SetInvalid(idx);
	}

	return static_cast<int32_t>(value);
}

template <typename FROM, typename TO>
TO cast(FROM input, ValidityMask &mask, idx_t idx) {
	return static_cast<TO>(input);
}

template <>
int32_t cast<double, int32_t>(double input, ValidityMask &mask, idx_t idx) {
	if (std::isnan(input)) {
		mask.SetInvalid(idx);
	}
	return check_int_range(input, mask, idx);
}

template <>
double cast<string_t, double>(string_t input, ValidityMask &mask, idx_t idx) {
	double result;
	if (!TryDoubleCast<double>(input.GetData(), input.GetSize(), result, false)) {
		mask.SetInvalid(idx);
	}

	return result;
}

template <>
int32_t cast<string_t, int32_t>(string_t input, ValidityMask &mask, idx_t idx) {
	auto dbl = cast<string_t, double>(input, mask, idx);
	return cast<double, int32_t>(dbl, mask, idx);
}

template <>
int32_t cast<date_t, int32_t>(date_t input, ValidityMask &mask, idx_t idx) {
	return input.days;
}

template <>
double cast<date_t, double>(date_t input, ValidityMask &mask, idx_t idx) {
	return input.days;
}

template <>
int32_t cast<timestamp_t, int32_t>(timestamp_t input, ValidityMask &mask, idx_t idx) {
	return check_int_range(Timestamp::GetEpochSeconds(input), mask, idx);
}

template <>
double cast<timestamp_t, double>(timestamp_t input, ValidityMask &mask, idx_t idx) {
	return check_int_range(Timestamp::GetEpochSeconds(input), mask, idx);
}

template <LogicalTypeId TYPE, LogicalTypeId RESULT_TYPE>
ScalarFunction AsNumberFunction() {
	using physical_type = typename physical<TYPE>::type;
	using result_type = typename physical<RESULT_TYPE>::type;

	auto fun = [](DataChunk &args, ExpressionState &state, Vector &result) {
		UnaryExecutor::ExecuteWithNulls<physical_type, result_type>(
			args.data[0], result, args.size(), cast<physical_type, result_type>
		);
	};
	return ScalarFunction({TYPE}, RESULT_TYPE, fun);
}

template <LogicalTypeId RESULT_TYPE>
ScalarFunctionSet as_number(std::string name) {
	ScalarFunctionSet set(name);

	set.AddFunction(AsNumberFunction<LogicalType::BOOLEAN   , RESULT_TYPE>());
	set.AddFunction(AsNumberFunction<LogicalType::INTEGER   , RESULT_TYPE>());
	set.AddFunction(AsNumberFunction<LogicalType::DOUBLE    , RESULT_TYPE>());
	set.AddFunction(AsNumberFunction<LogicalType::VARCHAR   , RESULT_TYPE>());
	set.AddFunction(AsNumberFunction<LogicalType::DATE      , RESULT_TYPE>());
	set.AddFunction(AsNumberFunction<LogicalType::TIMESTAMP , RESULT_TYPE>());

	return set;
}

}

ScalarFunctionSet base_r_as_integer() {
	return as_number<LogicalTypeId::INTEGER>("r_base::as.integer");
}

ScalarFunctionSet base_r_as_numeric() {
	return as_number<LogicalTypeId::DOUBLE>("r_base::as.numeric");
}

}
}
