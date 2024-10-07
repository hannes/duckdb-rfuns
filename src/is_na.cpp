#include "rfuns_extension.hpp"
#include "duckdb/parser/parsed_data/create_scalar_function_info.hpp"

#include <math.h>
#include <climits>
#include <iostream>
#include <cmath>

namespace duckdb {
namespace rfuns {

void isna_double_loop(idx_t count, const double* data, bool* result_data, ValidityMask mask) {
	idx_t base_idx = 0;
	auto entry_count = ValidityMask::EntryCount(count);
	for (idx_t entry_idx = 0; entry_idx < entry_count; entry_idx++) {
		auto validity_entry = mask.GetValidityEntry(entry_idx);
		idx_t next = MinValue<idx_t>(base_idx + ValidityMask::BITS_PER_VALUE, count);

		if (ValidityMask::AllValid(validity_entry)) {
			// all valid: check with std::isnan()
			for (; base_idx < next; base_idx++) {
				result_data[base_idx] = std::isnan(data[base_idx]);
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
					result_data[base_idx] = std::isnan(data[base_idx]);
				} else {
					result_data[base_idx] = true;
				}
			}
		}
	}
}

void isna_double(DataChunk &args, ExpressionState &state, Vector &result) {
	auto count = args.size();
	auto input = args.data[0];

	switch(input.GetVectorType()) {
		case VectorType::FLAT_VECTOR: {
			result.SetVectorType(VectorType::FLAT_VECTOR);

			isna_double_loop(
				count,
				FlatVector::GetData<double>(input),
				FlatVector::GetData<bool>(result),
				FlatVector::Validity(input)
			);

			break;
		}

		case VectorType::CONSTANT_VECTOR: {
			result.SetVectorType(VectorType::CONSTANT_VECTOR);
			auto result_data = ConstantVector::GetData<bool>(result);
			auto ldata = ConstantVector::GetData<double>(input);

			*result_data = ConstantVector::IsNull(input) || std::isnan(*ldata);

			break;
		}

		default: {
			UnifiedVectorFormat vdata;
			input.ToUnifiedFormat(count, vdata);
			result.SetVectorType(VectorType::FLAT_VECTOR);

			isna_double_loop(
				count,
				UnifiedVectorFormat::GetData<double>(vdata),
				FlatVector::GetData<bool>(result),
				vdata.validity
			);

			break;
		}
	}
}

void isna_any_loop(idx_t count, bool* result_data, ValidityMask mask) {
	if (mask.AllValid()) {
		for (idx_t i = 0; i < count; i++) {
			result_data[i] = false;
		}
		return;
	}

	idx_t base_idx = 0;
	auto entry_count = ValidityMask::EntryCount(count);
	for (idx_t entry_idx = 0; entry_idx < entry_count; entry_idx++) {
		auto validity_entry = mask.GetValidityEntry(entry_idx);
		idx_t next = MinValue<idx_t>(base_idx + ValidityMask::BITS_PER_VALUE, count);

		if (ValidityMask::AllValid(validity_entry)) {
			// all valid
			for (; base_idx < next; base_idx++) {
				result_data[base_idx] = false;
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
				result_data[base_idx] = !ValidityMask::RowIsValid(validity_entry, base_idx - start);
			}
		}
	}

}

void isna_any(DataChunk &args, ExpressionState &state, Vector &result) {
	auto count = args.size();
	auto input = args.data[0];

	switch(input.GetVectorType()) {
		case VectorType::FLAT_VECTOR: {
			result.SetVectorType(VectorType::FLAT_VECTOR);
			isna_any_loop(
				count,
				FlatVector::GetData<bool>(result),
				FlatVector::Validity(input)
			);

			break;
		}

		case VectorType::CONSTANT_VECTOR: {
			result.SetVectorType(VectorType::CONSTANT_VECTOR);
			auto result_data = ConstantVector::GetData<bool>(result);
			*result_data = ConstantVector::IsNull(input);

			break;
		}

		default : {
			UnifiedVectorFormat vdata;
			input.ToUnifiedFormat(count, vdata);
			result.SetVectorType(VectorType::FLAT_VECTOR);
			isna_any_loop(
				count,
				FlatVector::GetData<bool>(result),
				vdata.validity
			);

			break;
		}
	}

}


ScalarFunctionSet base_r_is_na() {
	ScalarFunctionSet set("r_base::is.na");

	set.AddFunction(ScalarFunction({LogicalType::DOUBLE}, LogicalType::BOOLEAN, isna_double));
	set.AddFunction(ScalarFunction({LogicalType::ANY}   , LogicalType::BOOLEAN, isna_any));

	return set;
}

}
}
