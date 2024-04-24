#include "rfuns_extension.hpp"
#include "duckdb/parser/parsed_data/create_scalar_function_info.hpp"

#include <math.h>
#include <climits>
#include <iostream>

namespace duckdb {
namespace rfuns {

template <bool is_double>
struct IsNaWrapper {
	IsNaWrapper(Vector&){}

	inline bool is_na(idx_t) {
		return false;
	}
};

template <>
struct IsNaWrapper<true> {
	IsNaWrapper(Vector& input) : data(FlatVector::GetData<double>(input)){}

	inline bool is_na(idx_t idx) {
		return isnan(data[idx]);
	}

	double* data;
};

template <bool is_double>
void isna(DataChunk &args, ExpressionState &state, Vector &result) {
	auto count = args.size();
	auto input = args.data[0];
	auto mask = FlatVector::Validity(input);
	auto wrapper = IsNaWrapper<is_double>(input);

	result.SetVectorType(VectorType::FLAT_VECTOR);
	auto result_data = FlatVector::GetData<bool>(result);

	idx_t base_idx = 0;
	auto entry_count = ValidityMask::EntryCount(count);
	for (idx_t entry_idx = 0; entry_idx < entry_count; entry_idx++) {
		auto validity_entry = mask.GetValidityEntry(entry_idx);
		idx_t next = MinValue<idx_t>(base_idx + ValidityMask::BITS_PER_VALUE, count);

		if (ValidityMask::AllValid(validity_entry)) {
			// all valid: check with isnan()
			for (; base_idx < next; base_idx++) {
				result_data[base_idx] = wrapper.is_na(base_idx);
			}
		} else if (ValidityMask::NoneValid(validity_entry)) {
			// None valid:
			for (; base_idx < next; base_idx++) {
				result_data[base_idx] = true;
			}
		} else {
			// partially valid: need to check individual elements for validity
			idx_t start = base_idx;
			for (; base_idx < next; base_idx++) {
				if (ValidityMask::RowIsValid(validity_entry, base_idx - start)) {
					D_ASSERT(mask.RowIsValid(base_idx));
					result_data[base_idx] = wrapper.is_na(base_idx);
				} else {
					result_data[base_idx] = true;
				}
			}
		}
	}
}

ScalarFunctionSet base_r_is_na() {
	ScalarFunctionSet set("r_base::is.na");

	set.AddFunction(ScalarFunction({LogicalType::DOUBLE}, LogicalType::BOOLEAN, isna<true>));
	return set;
}

}
}
