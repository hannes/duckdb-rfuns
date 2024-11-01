#include "rfuns_extension.hpp"
#include "duckdb/parser/parsed_data/create_scalar_function_info.hpp"
#include "duckdb/common/operator/double_cast_operator.hpp"

#include <math.h>
#include <climits>
#include <limits>
#include <cmath>
#include <iostream>

namespace duckdb {
namespace rfuns {

namespace {

template <typename physical_type>
string to_string(physical_type x) {
	return std::to_string(x);
}

template <>
string to_string<bool>(bool x) {
	return string(x ? "TRUE" : "FALSE");
}

template <>
string to_string<string_t>(string_t x) {
	return x.GetString();
}

template <>
string to_string<date_t>(date_t x) {
	return Date::ToString(x);
}

template <>
string to_string<timestamp_t>(timestamp_t x) {
	return Timestamp::ToString(x);
}

template <LogicalTypeId TYPE>
ScalarFunction AsCharacterFunction() {
	using physical_type = typename physical<TYPE>::type;

	auto fun = [](DataChunk &args, ExpressionState &state, Vector &result) {
		UnaryExecutor::Execute<physical_type, string_t>(
			args.data[0], 
			result, 
			args.size(), 
			[&](physical_type input) {
				return StringVector::AddString(result, to_string<physical_type>(input));
			}
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
