#include "rfuns_extension.hpp"
#include "duckdb/parser/parsed_data/create_scalar_function_info.hpp"

#include <math.h>
#include <climits>

namespace duckdb {
namespace rfuns {

ScalarFunctionSet binary_dispatch(ScalarFunctionSet fn) {
	ScalarFunctionSet set(StringUtil::Format("dispatch(%s)", fn.name));

	set.AddFunction(ScalarFunction(
		{LogicalType::ANY, LogicalType::ANY},
		LogicalType::VARCHAR,
		[fn](DataChunk &args, ExpressionState &state, Vector &result) {
			vector<LogicalType> types(args.data.size());
			types[0] = args.data[0].GetType();
			types[1] = args.data[1].GetType();
			auto variant = const_cast<ScalarFunctionSet&>(fn).GetFunctionByArguments(state.GetContext(), types);

			auto info = StringUtil::Format(
				"lhs = %s, rhs = %s, signature = %s",
				EnumUtil::ToChars(types[0].id()),
				EnumUtil::ToChars(types[1].id()),
				variant.ToString().c_str()
			);
			result.SetValue(0, info);
		}
	));
	return set;
}

} // namespace rfuns
} // namespace duckdb
