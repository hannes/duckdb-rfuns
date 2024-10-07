#include "rfuns_extension.hpp"
#include "duckdb/parser/parsed_data/create_scalar_function_info.hpp"
#include "duckdb/common/operator/string_cast.hpp"
#include "duckdb/common/operator/double_cast_operator.hpp"

#include <math.h>
#include <climits>
#include <iostream>
#include <cmath>

namespace duckdb {
namespace rfuns {

namespace {

enum Relop {
	EQ,
	NEQ,
	LT,
	LTE,
	GT,
	GTE
};

template <typename LHS, typename RHS, Relop OP>
struct SimpleDispatch {
	inline bool operator()(LHS lhs, RHS rhs);
};


template <typename LHS, typename RHS>
struct SimpleDispatch<LHS, RHS, EQ> {
	inline bool operator()(LHS lhs, RHS rhs) {
		return lhs == rhs;
	}
};

template <typename LHS, typename RHS>
struct SimpleDispatch<LHS, RHS, NEQ> {
	inline bool operator()(LHS lhs, RHS rhs) {
		return !(lhs == rhs);
	}
};

template <typename LHS, typename RHS>
struct SimpleDispatch<LHS, RHS, LT> {
	inline bool operator()(LHS lhs, RHS rhs) {
		return lhs < rhs;
	}
};

template <typename LHS, typename RHS>
struct SimpleDispatch<LHS, RHS, LTE> {
	inline bool operator()(LHS lhs, RHS rhs) {
		return lhs < rhs || lhs == rhs;
	}
};

template <typename LHS, typename RHS>
struct SimpleDispatch<LHS, RHS, GT> {
	inline bool operator()(LHS lhs, RHS rhs) {
		return lhs > rhs;
	}
};

template <typename LHS, typename RHS>
struct SimpleDispatch<LHS, RHS, GTE> {
	inline bool operator()(LHS lhs, RHS rhs) {
		return lhs > rhs || lhs == rhs;
	}
};

template <typename LHS, typename RHS, Relop OP>
struct RelopDispatch {
	inline bool operator()(LHS lhs, RHS rhs) {
		return SimpleDispatch<LHS, RHS, OP>()(lhs, rhs);
	}
};

template <typename LHS, typename RHS, Relop OP>
inline bool relop(LHS lhs, RHS rhs);

string_t bool_to_string(bool x) {
	return string_t(x ? "TRUE" : "FALSE");
}

template <Relop OP>
struct RelopDispatch<string_t, date_t, OP> {
	inline bool operator()(string_t lhs, date_t rhs) {
		return SimpleDispatch<date_t, date_t, OP>()(Date::FromString(lhs.GetString(), false), rhs);
	}
};

template <Relop OP>
struct RelopDispatch<date_t, string_t, OP> {
	inline bool operator()(date_t lhs, string_t rhs) {
		return SimpleDispatch<date_t, date_t, OP>()(lhs, Date::FromString(rhs.GetString(), false));
	}
};

template <Relop OP>
struct RelopDispatch<string_t, timestamp_t, OP> {
	inline bool operator()(string_t lhs, timestamp_t rhs) {
		return SimpleDispatch<timestamp_t, timestamp_t, OP>()(Timestamp::FromString(lhs.GetString()), rhs);
	}
};

template <Relop OP>
struct RelopDispatch<timestamp_t, string_t, OP> {
	inline bool operator()(timestamp_t lhs, string_t rhs) {
		return SimpleDispatch<timestamp_t, timestamp_t, OP>()(lhs, Timestamp::FromString(rhs.GetString()));
	}
};

template <Relop OP>
struct RelopDispatch<bool, string_t, OP> {
	inline bool operator()(bool lhs, string_t rhs) {
		return SimpleDispatch<string_t, string_t, OP>()(bool_to_string(lhs), rhs);
	}
};

template <Relop OP>
struct RelopDispatch<string_t, bool, OP> {
	inline bool operator()(string_t lhs, bool rhs) {
		return SimpleDispatch<string_t, string_t, OP>()(lhs, bool_to_string(rhs));
	}
};

template <Relop OP>
struct RelopDispatch<string_t, string_t, OP> {
	inline bool operator()(string_t lhs, string_t rhs) {
		return SimpleDispatch<string_t, string_t, OP>()(lhs, rhs);
	}
};

template <typename LHS, typename RHS, Relop OP>
inline bool relop(LHS lhs, RHS rhs) {
	return RelopDispatch<LHS, RHS, OP>()(lhs, rhs);
}

template <typename LHS, typename RHS>
struct relop_adds_null : public std::integral_constant<bool, false>{};

template <typename LHS>
struct relop_adds_null<LHS, double> : public std::integral_constant<bool, true>{};

template <typename RHS>
struct relop_adds_null<double, RHS> : public std::integral_constant<bool, true>{};

template <>
struct relop_adds_null<double, double> : public std::integral_constant<bool, true>{};

template <typename T>
bool set_null(T value, ValidityMask &mask, idx_t idx) {
	return false;
}

template <>
bool set_null<double>(double value, ValidityMask &mask, idx_t idx) {
	if (std::isnan(value)) {
		mask.SetInvalid(idx);
		return true;
	}
	return false;
}

template <LogicalTypeId LHS_LOGICAL, typename LHS_TYPE, LogicalTypeId RHS_LOGICAL, typename RHS_TYPE, Relop OP>
void RelopExecuteDispatch(DataChunk &args, ExpressionState &state, Vector &result, std::false_type) {
	auto parts = BinaryTypeAssert<LHS_LOGICAL, RHS_LOGICAL>(args);
	BinaryExecutor::Execute<LHS_TYPE, RHS_TYPE, bool>(parts.lefts, parts.rights, result, args.size(), relop<LHS_TYPE, RHS_TYPE, OP>);
}

template <LogicalTypeId LHS_LOGICAL, typename LHS_TYPE, LogicalTypeId RHS_LOGICAL, typename RHS_TYPE, Relop OP>
void RelopExecuteDispatch(DataChunk &args, ExpressionState &state, Vector &result, std::true_type) {
	auto parts = BinaryTypeAssert<LHS_LOGICAL, RHS_LOGICAL>(args);
	auto fun = [&](LHS_TYPE left, RHS_TYPE right, ValidityMask &mask, idx_t idx) {
		if (set_null<LHS_TYPE>(left, mask, idx)) return false;
		if (set_null<RHS_TYPE>(right, mask, idx)) return false;
		return relop<LHS_TYPE, RHS_TYPE, OP>(left, right);
	};
	BinaryExecutor::ExecuteWithNulls<LHS_TYPE, RHS_TYPE, bool>(parts.lefts, parts.rights, result, args.size(), fun);
}

template <LogicalTypeId LHS_LOGICAL, typename LHS_TYPE, LogicalTypeId RHS_LOGICAL, typename RHS_TYPE, Relop OP>
void RelopExecute(DataChunk &args, ExpressionState &state, Vector &result) {
	RelopExecuteDispatch<LHS_LOGICAL, LHS_TYPE, RHS_LOGICAL, RHS_TYPE, OP>(args, state, result, typename relop_adds_null<LHS_TYPE, RHS_TYPE>::type());
}

#define RELOP_VARIANT(__LHS__, __RHS__) ScalarFunction(                      \
	/* arguments   = */ {LogicalType::__LHS__, LogicalType::__RHS__},        \
	/* return_type = */ LogicalType::BOOLEAN,                                \
	/* function    = */ RelopExecute<                                        \
		LogicalType::__LHS__, typename physical<LogicalType::__LHS__>::type, \
	    LogicalType::__RHS__, typename physical<LogicalType::__RHS__>::type, \
	    OP                                                                   \
	>)

#define RELOP_VARIANT_BIND_FAIL(__LHS__, __RHS__, __WHY__) ScalarFunction(                \
	  /* arguments   = */ {LogicalType::__LHS__, LogicalType::__RHS__},                   \
	  /* return_type = */ LogicalType::BOOLEAN,                                           \
	  /* function    = */ [](DataChunk &args, ExpressionState &state, Vector &result) {}, \
	  /* bind        = */ [](ClientContext &context, ScalarFunction &bound_function, vector<duckdb::unique_ptr<Expression>> &arguments) -> unique_ptr<FunctionData> { \
		throw InvalidInputException("%s : %s <=> %s", __WHY__, EnumUtil::ToChars(LogicalType::__LHS__), EnumUtil::ToChars(LogicalType::__RHS__)); \
		})

template <Relop OP>
ScalarFunctionSet base_r_relop(string name) {
	ScalarFunctionSet set(name);

	set.AddFunction(RELOP_VARIANT(BOOLEAN, BOOLEAN));
	set.AddFunction(RELOP_VARIANT(BOOLEAN, INTEGER));
	set.AddFunction(RELOP_VARIANT(INTEGER, BOOLEAN));
	set.AddFunction(RELOP_VARIANT(INTEGER, INTEGER));

	set.AddFunction(RELOP_VARIANT(DOUBLE, INTEGER));
	set.AddFunction(RELOP_VARIANT(INTEGER, DOUBLE));
	set.AddFunction(RELOP_VARIANT(DOUBLE, BOOLEAN));
	set.AddFunction(RELOP_VARIANT(BOOLEAN, DOUBLE));

	set.AddFunction(RELOP_VARIANT(DOUBLE, DOUBLE));
	set.AddFunction(RELOP_VARIANT(VARCHAR, VARCHAR));

	set.AddFunction(RELOP_VARIANT(TIMESTAMP, TIMESTAMP));
	set.AddFunction(RELOP_VARIANT(DATE, DATE));

	set.AddFunction(RELOP_VARIANT_BIND_FAIL(TIMESTAMP, DATE, "Comparing times and dates is not supported"));
	set.AddFunction(RELOP_VARIANT_BIND_FAIL(DATE, TIMESTAMP, "Comparing dates and times is not supported"));

	return set;
}

} // namespace

ScalarFunctionSet base_r_eq() {
	return base_r_relop<EQ>("r_base::==");
}
ScalarFunctionSet base_r_neq() {
	return base_r_relop<NEQ>("r_base::!=");
}
ScalarFunctionSet base_r_lt() {
	return base_r_relop<LT>("r_base::<");
}
ScalarFunctionSet base_r_lte() {
	return base_r_relop<LTE>("r_base::<=");
}
ScalarFunctionSet base_r_gt() {
	return base_r_relop<GT>("r_base::>");
}
ScalarFunctionSet base_r_gte() {
	return base_r_relop<GTE>("r_base::>=");
}

namespace {

template <typename LHS_TYPE, typename RHS_TYPE>
bool try_equal(LHS_TYPE lhs, RHS_TYPE rhs) {
	return relop<LHS_TYPE, RHS_TYPE, EQ>(lhs, rhs);
}

template <>
bool try_equal<string_t, timestamp_t> (string_t lhs, timestamp_t rhs) {
	timestamp_t result;
	if (Timestamp::TryConvertTimestamp(lhs.GetString().c_str(), lhs.GetString().length(), result) != TimestampCastResult::SUCCESS ){
		return false;
	}
	return result == rhs;
}

template <>
bool try_equal<timestamp_t, string_t> (timestamp_t lhs, string_t rhs) {
	return try_equal(rhs, lhs);
}

template <>
bool try_equal<string_t, date_t> (string_t lhs, date_t rhs) {
	date_t result;
	idx_t pos;
	bool special = false;
	if (!Date::TryConvertDate(lhs.GetString().c_str(), lhs.GetString().length(), pos, result, special, false)) {
		return false;
	}
	return result == rhs;
}

template <>
bool try_equal<date_t, string_t> (date_t lhs, string_t rhs) {
	return try_equal(rhs, lhs);
}

template <typename LHS_TYPE, typename RHS_TYPE>
void InExecute(DataChunk &args, ExpressionState &state, Vector &result) {

	auto count = args.size();
	auto x = args.data[0];

	auto y = args.data[1];
	if (y.GetVectorType() != VectorType::CONSTANT_VECTOR) {
		throw InvalidInputException("rhs must be a constant");
	}
	auto y_size = ListVector::GetListSize(y);
	auto y_data = FlatVector::GetData<RHS_TYPE>(ListVector::GetEntry(y));
	auto y_mask = FlatVector::Validity(ListVector::GetEntry(y));

	bool na_in_y = [&](){
		if (!y_mask.AllValid()) {
			idx_t y_base_idx = 0;
			auto y_entry_count = ValidityMask::EntryCount(y_size);
			for (idx_t y_entry_idx = 0; y_entry_idx < y_entry_count; y_entry_idx++) {
				auto y_validity_entry = y_mask.GetValidityEntry(y_entry_idx);
				idx_t y_next = MinValue<idx_t>(y_base_idx + ValidityMask::BITS_PER_VALUE, y_size);

				if (!ValidityMask::AllValid(y_validity_entry)) {
					if (ValidityMask::NoneValid(y_validity_entry)) {
						return true;
					} else {
						idx_t y_start = y_base_idx;
						for (; y_base_idx < y_next; y_base_idx++) {
							if (!ValidityMask::RowIsValid(y_validity_entry, y_base_idx - y_start)) {
								return true;
							}
						}
					}
				}
			}
		}

		return false;
	}();


	auto is_in_y = [&](LHS_TYPE left) {
		// special case when there are no NAs in y
		if (!na_in_y) {
			for (int i = 0; i < y_size; i++) {
				if (try_equal(left, y_data[i])) {
					return true;
				}
			}
			return false;
		}

		// there are NAs in y, so do entry by entry
		idx_t y_base_idx = 0;
		auto y_entry_count = ValidityMask::EntryCount(y_size);
		for (idx_t y_entry_idx = 0; y_entry_idx < y_entry_count; y_entry_idx++) {
			auto y_validity_entry = y_mask.GetValidityEntry(y_entry_idx);
			idx_t y_next = MinValue<idx_t>(y_base_idx + ValidityMask::BITS_PER_VALUE, y_size);

			if (ValidityMask::AllValid(y_validity_entry)) {
				for (; y_base_idx < y_next; y_base_idx++) {
					if (try_equal(left, y_data[y_base_idx])) {
						return true;
					}
				}
			} else if (ValidityMask::NoneValid(y_validity_entry)) {
				// nothing to do, because inside is_in_y() we know left is valid
				for (; y_base_idx < y_next; y_base_idx++) {}
			} else {
				idx_t y_start = y_base_idx;

				for (; y_base_idx < y_next; y_base_idx++) {
					if (ValidityMask::RowIsValid(y_validity_entry, y_base_idx - y_start)) {
						if (try_equal(left, y_data[y_base_idx])) {
							return true;
						}
					}
				}
			}

		}
		return false;
	};

	auto in_loop = [&](idx_t count, LHS_TYPE* x_data, bool* result_data, ValidityMask mask) {
		idx_t base_idx = 0;
		auto entry_count = ValidityMask::EntryCount(count);
		for (idx_t entry_idx = 0; entry_idx < entry_count; entry_idx++) {
			auto validity_entry = mask.GetValidityEntry(entry_idx);
			idx_t next = MinValue<idx_t>(base_idx + ValidityMask::BITS_PER_VALUE, count);

			if (ValidityMask::AllValid(validity_entry)) {
				for (; base_idx < next; base_idx++) {
					result_data[base_idx] = is_in_y(x_data[base_idx]);
				}
			} else if (ValidityMask::NoneValid(validity_entry)) {
				// None valid:
				for (; base_idx < next; base_idx++) {
					result_data[base_idx] = !y_mask.AllValid();
				}
			} else {
				// partially valid: need to check individual elements for validity
				idx_t start = base_idx;

				for (; base_idx < next; base_idx++) {
					if (ValidityMask::RowIsValid(validity_entry, base_idx - start)) {
						result_data[base_idx] = is_in_y(x_data[base_idx]);
					} else {
						result_data[base_idx] = na_in_y;
					}
				}
			}
		}
	};

	switch(x.GetVectorType()) {
		case VectorType::FLAT_VECTOR: {
			result.SetVectorType(VectorType::FLAT_VECTOR);

			in_loop(
				count,
				FlatVector::GetData<LHS_TYPE>(x),
				FlatVector::GetData<bool>(result),
				FlatVector::Validity(x)
			);

			break;
		}

		case VectorType::CONSTANT_VECTOR: {
			result.SetVectorType(VectorType::CONSTANT_VECTOR);
			auto result_data = ConstantVector::GetData<bool>(result);
			*result_data = is_in_y(*ConstantVector::GetData<LHS_TYPE>(x));

			break;
		}

		default : {
			UnifiedVectorFormat vdata;
			x.ToUnifiedFormat(count, vdata);
			result.SetVectorType(VectorType::FLAT_VECTOR);
			in_loop(
				count,
				FlatVector::GetData<LHS_TYPE>(x),
				FlatVector::GetData<bool>(result),
				vdata.validity
			);

			break;
		}
	}

}

#define IN_VARIANT(__LHS__, __RHS__) ScalarFunction(                                      \
	/* arguments   = */ {LogicalType::__LHS__, LogicalType::LIST(LogicalType::__RHS__)},  \
	/* return_type = */ LogicalType::BOOLEAN,                                \
	/* function    = */ InExecute<                                           \
		typename physical<LogicalType::__LHS__>::type, \
	    typename physical<LogicalType::__RHS__>::type  \
	>)

} // namespace

ScalarFunctionSet base_r_in() {
	ScalarFunctionSet set("r_base::%in%");

	set.AddFunction(IN_VARIANT(DOUBLE, DOUBLE));
	set.AddFunction(IN_VARIANT(BOOLEAN, BOOLEAN));
	set.AddFunction(IN_VARIANT(BOOLEAN, INTEGER));
	set.AddFunction(IN_VARIANT(INTEGER, BOOLEAN));
	set.AddFunction(IN_VARIANT(INTEGER, INTEGER));

	set.AddFunction(IN_VARIANT(DOUBLE, INTEGER));
	set.AddFunction(IN_VARIANT(INTEGER, DOUBLE));
	set.AddFunction(IN_VARIANT(DOUBLE, BOOLEAN));
	set.AddFunction(IN_VARIANT(BOOLEAN, DOUBLE));

	set.AddFunction(IN_VARIANT(VARCHAR, VARCHAR));
	set.AddFunction(IN_VARIANT(TIMESTAMP, TIMESTAMP));
	set.AddFunction(IN_VARIANT(DATE, DATE));

	return set;
}



} // namespace rfuns
} // namespace duckdb
