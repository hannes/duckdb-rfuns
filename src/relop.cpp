#include "rfuns_extension.hpp"
#include "duckdb/parser/parsed_data/create_scalar_function_info.hpp"

#include <math.h>
#include <climits>

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

// borrowed from EncodeInteger
string_t to_string(int x) {
	char s[100];
	snprintf(s, sizeof(s), "%d", x);
	return string_t(s);
}

string_t to_string(bool x) {
	return string_t(x ? "TRUE" : "FALSE");
}

string_t to_string(double x) {
	char s[100];
	snprintf(s, sizeof(s), "%.17g", x);
	return string_t(s);
}

template <typename LHS, Relop OP>
struct RelopDispatch<LHS, string_t, OP> {
	inline bool operator()(LHS lhs, string_t rhs) {
		return SimpleDispatch<string_t, string_t, OP>()(to_string(lhs), rhs);
	}
};

template <typename RHS, Relop OP>
struct RelopDispatch<string_t, RHS, OP> {
	inline bool operator()(string_t lhs, RHS rhs) {
		return SimpleDispatch<string_t, string_t, OP>()(lhs, to_string(rhs));
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
	if (isnan(value)) {
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

template <LogicalTypeId LOGICAL_TYPE>
struct physical ;

template <>
struct physical<LogicalType::BOOLEAN> {
	using type = bool;
};
template <>
struct physical<LogicalType::INTEGER> {
	using type = int32_t;
};
template <>
struct physical<LogicalType::DOUBLE> {
	using type = double;
};
template <>
struct physical<LogicalType::VARCHAR> {
	using type = string_t;
};
template <>
struct physical<LogicalType::TIMESTAMP> {
	using type = timestamp_t;
};
template <>
struct physical<LogicalType::DATE> {
	using type = date_t;
};

#define RELOP_VARIANT(__LHS__, __RHS__)                                                 \
  ScalarFunction({LogicalType::__LHS__, LogicalType::__RHS__}, LogicalType::BOOLEAN,    \
                 RelopExecute<                                                          \
                   LogicalType::__LHS__, typename physical<LogicalType::__LHS__>::type, \
	               LogicalType::__RHS__, typename physical<LogicalType::__RHS__>::type, \
	               OP                                                                   \
				>)

template <LogicalTypeId LHS_LOGICAL, LogicalTypeId RHS_LOGICAL, const char* WHY>
void RelopFails(DataChunk &args, ExpressionState &state, Vector &result) {
	throw NotImplementedException(
		StringUtil::Format("%s : %s <=> %s", WHY, EnumUtil::ToChars(LHS_LOGICAL), EnumUtil::ToChars(RHS_LOGICAL))
	);
}

#define SET_RELOP_FAILS_VARIANT(__LHS__, __RHS__, __WHY__) { \
	ScalarFunction fun( \
	  {LogicalType::__LHS__, LogicalType::__RHS__}, LogicalType::BOOLEAN, \
	  [](DataChunk &args, ExpressionState &state, Vector &result) { \
		throw NotImplementedException( \
			StringUtil::Format("%s : %s <=> %s", __WHY__, EnumUtil::ToChars(LogicalType::__LHS__), EnumUtil::ToChars(LogicalType::__RHS__)) \
		); \
	  }); \
	set.AddFunction(fun); \
}

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

	set.AddFunction(RELOP_VARIANT(VARCHAR, INTEGER));
	set.AddFunction(RELOP_VARIANT(INTEGER, VARCHAR));
	set.AddFunction(RELOP_VARIANT(VARCHAR, BOOLEAN));
	set.AddFunction(RELOP_VARIANT(BOOLEAN, VARCHAR));

	set.AddFunction(RELOP_VARIANT(DOUBLE, DOUBLE));
	set.AddFunction(RELOP_VARIANT(VARCHAR, VARCHAR));
	set.AddFunction(RELOP_VARIANT(VARCHAR, DOUBLE));
	set.AddFunction(RELOP_VARIANT(DOUBLE, VARCHAR));

	set.AddFunction(RELOP_VARIANT(TIMESTAMP, TIMESTAMP));
	set.AddFunction(RELOP_VARIANT(DATE, DATE));

	SET_RELOP_FAILS_VARIANT(TIMESTAMP, DATE, "Comparing times and dates is not supported")
	SET_RELOP_FAILS_VARIANT(DATE, TIMESTAMP, "Comparing dates and times is not supported")

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

} // namespace rfuns
} // namespace duckdb
