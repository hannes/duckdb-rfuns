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

template <typename physical_type>
string_t to_string(physical_type x) {
	return string_t(std::to_string(x));
}

template <>
string_t to_string<bool>(bool x) {
	return string_t(x ? "TRUE" : "FALSE");
}

template <>
string_t to_string<string_t>(string_t x) {
	return x;
}

template <>
string_t to_string<date_t>(date_t x) {
	return string_t(Date::ToString(x));
}

template <>
string_t to_string<timestamp_t>(timestamp_t x) {
	return string_t(Timestamp::ToString(x));
}

template <LogicalTypeId TYPE>
ScalarFunction AsCharacterFunction() {
	using physical_type = typename physical<TYPE>::type;

	auto fun = [](DataChunk &args, ExpressionState &state, Vector &result) {
		UnaryExecutor::Execute<physical_type, string_t>(
			args.data[0], result, args.size(), to_string<physical_type>
		);
	};
	return ScalarFunction({TYPE}, LogicalType::VARCHAR, fun);
}

}

ScalarFunctionSet base_r_as_character() {
	ScalarFunctionSet set("r_base::as.character");

	set.AddFunction(AsCharacterFunction<LogicalType::BOOLEAN  >());
	set.AddFunction(AsCharacterFunction<LogicalType::INTEGER  >());
	set.AddFunction(AsCharacterFunction<LogicalType::DOUBLE   >());
	set.AddFunction(AsCharacterFunction<LogicalType::VARCHAR  >());
	set.AddFunction(AsCharacterFunction<LogicalType::DATE     >());
	set.AddFunction(AsCharacterFunction<LogicalType::TIMESTAMP>());

	return set;
}

}
}
