#include "rfuns_extension.hpp"
#include "duckdb/parser/parsed_data/create_scalar_function_info.hpp"

#include <math.h>
#include <climits>

namespace duckdb {
namespace rfuns {

namespace {

}

ScalarFunctionSet base_r_lt() {
	ScalarFunctionSet set("r_base::<");

	return set;
}


}
}
