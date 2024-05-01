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
int32_t check_range(T value, ValidityMask &mask, idx_t idx) {
	if (value > std::numeric_limits<int32_t>::max() || value < std::numeric_limits<int32_t>::min() ) {
		mask.SetInvalid(idx);
	}

	return static_cast<int32_t>(value);
}

template <typename T>
int32_t cast(T input, ValidityMask &mask, idx_t idx) {
	return static_cast<int32_t>(input);
}

template <>
int32_t cast<double>(double input, ValidityMask &mask, idx_t idx) {
	if (isnan(input)) {
		mask.SetInvalid(idx);
	}
	return check_range(input, mask, idx);
}

template <>
int32_t cast<string_t>(string_t input, ValidityMask &mask, idx_t idx) {
	double result;
	if (!TryDoubleCast<double>(input.GetData(), input.GetSize(), result, false)) {
		mask.SetInvalid(idx);
	}

	return cast<double>(result, mask, idx);
}

template <>
int32_t cast<date_t>(date_t input, ValidityMask &mask, idx_t idx) {
	return input.days;
}

template <>
int32_t cast<timestamp_t>(timestamp_t input, ValidityMask &mask, idx_t idx) {
	return check_range(Timestamp::GetEpochSeconds(input), mask, idx);
}

template <LogicalTypeId TYPE>
ScalarFunction AsIntegerFunction() {
	using physical_type = typename physical<TYPE>::type;

	auto fun = [](DataChunk &args, ExpressionState &state, Vector &result) {
		UnaryExecutor::ExecuteWithNulls<physical_type, int32_t>(
			args.data[0], result, args.size(), cast<physical_type>
		);
	};
	return ScalarFunction({TYPE}, LogicalType::INTEGER, fun);
}

}

ScalarFunctionSet base_r_as_integer() {
	ScalarFunctionSet set("r_base::as.integer");

	set.AddFunction(AsIntegerFunction<LogicalType::BOOLEAN>());
	set.AddFunction(AsIntegerFunction<LogicalType::INTEGER>());
	set.AddFunction(AsIntegerFunction<LogicalType::DOUBLE>());

	set.AddFunction(AsIntegerFunction<LogicalType::VARCHAR>());

	set.AddFunction(AsIntegerFunction<LogicalType::DATE>());
	set.AddFunction(AsIntegerFunction<LogicalType::TIMESTAMP>());

	return set;
}

}
}
