#include "rfuns_extension.hpp"
#include "duckdb/parser/parsed_data/create_scalar_function_info.hpp"

#include <math.h>
#include <climits>
#include <sstream>
#include <iostream>

namespace duckdb {
namespace rfuns {

ScalarFunctionSet binary_dispatch(string name, ScalarFunctionSet fn) {
	ScalarFunctionSet set(name);

	auto binder = [fn](DataChunk &args, ExpressionState &state, Vector &result) {
		vector<LogicalType> types(args.data.size());
		types[0] = args.data[0].GetType();
		types[1] = args.data[1].GetType();
		auto variant = const_cast<ScalarFunctionSet&>(fn).GetFunctionByArguments(state.GetContext(), types);

		std::stringstream ss;
		ss << "lhs = " << EnumUtil::ToChars(types[0].id())
		   << ", rhs = " << EnumUtil::ToChars(types[1].id())
		   << ". signature = " << variant.ToString();

		std::cout << ss.str() << std::endl;

		*ConstantVector::GetData<string_t>(result) = ss.str();
	};

	set.AddFunction(ScalarFunction({LogicalType::ANY, LogicalType::ANY}, LogicalType::VARCHAR, binder));
	return set;
}

} // namespace rfuns
} // namespace duckdb
