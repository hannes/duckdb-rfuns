#include "rfuns_extension.hpp"

#include "duckdb/parser/parsed_data/create_scalar_function_info.hpp"

#include <math.h>
#include <climits>

namespace duckdb {
namespace rfuns {

namespace {
static void BaseRAddFunctionInteger(DataChunk &args, ExpressionState &state, Vector &result) {
	auto &lefts = args.data[0];
	D_ASSERT(lefts.GetType() == LogicalType::INTEGER);
	auto &rights = args.data[1];
	D_ASSERT(rights.GetType() == LogicalType::INTEGER);
	BinaryExecutor::ExecuteWithNulls<int32_t, int32_t, int32_t>(
	    lefts, rights, result, args.size(), [&](int32_t left, int32_t right, ValidityMask &mask, idx_t idx) {
		    int64_t result = (int64_t)left + right;
		    if (result > INT_MAX || result < (INT_MIN + 1)) {
			    // FIXME: Need warning: NAs produced by integer overflow
			    mask.SetInvalid(idx);
			    return 0;
		    }
		    return (int32_t)result;
	    });
}

static void BaseRAddFunctionDouble(DataChunk &args, ExpressionState &state, Vector &result) {
	auto &lefts = args.data[0];
	D_ASSERT(lefts.GetType() == LogicalType::DOUBLE);
	auto &rights = args.data[1];
	D_ASSERT(rights.GetType() == LogicalType::DOUBLE);
	BinaryExecutor::ExecuteWithNulls<double, double, double>(
	    lefts, rights, result, args.size(), [&](double left, double right, ValidityMask &mask, idx_t idx) {
		    if (isnan(left) || isnan(right)) {
			    mask.SetInvalid(idx);
			    return 0.0;
		    }
		    return left + right;
	    });
}
}

ScalarFunctionSet base_r_add() {
    ScalarFunctionSet set("r_base::+");
	set.AddFunction(
	    ScalarFunction({LogicalType::INTEGER, LogicalType::INTEGER}, LogicalType::INTEGER, BaseRAddFunctionInteger));
	set.AddFunction(
	    ScalarFunction({LogicalType::DOUBLE, LogicalType::DOUBLE}, LogicalType::DOUBLE, BaseRAddFunctionDouble));

    return set;
}

}
}
