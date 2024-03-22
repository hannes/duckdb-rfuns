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
struct RelopDispatch {

	inline bool operator()(LHS lhs, RHS rhs);

};

template <typename LHS, typename RHS>
struct RelopDispatch<LHS, RHS, EQ> {
	inline bool operator()(LHS lhs, RHS rhs) {
		return lhs == rhs;
	}
};

template <typename LHS, typename RHS>
struct RelopDispatch<LHS, RHS, NEQ> {
	inline bool operator()(LHS lhs, RHS rhs) {
		return !(lhs == rhs);
	}
};

template <typename LHS, typename RHS>
struct RelopDispatch<LHS, RHS, LT> {
	inline bool operator()(LHS lhs, RHS rhs) {
		return lhs < rhs;
	}
};

template <typename LHS, typename RHS>
struct RelopDispatch<LHS, RHS, LTE> {
	inline bool operator()(LHS lhs, RHS rhs) {
		return lhs < rhs || lhs == rhs;
	}
};

template <typename LHS, typename RHS>
struct RelopDispatch<LHS, RHS, GT> {
	inline bool operator()(LHS lhs, RHS rhs) {
		return lhs > rhs;
	}
};

template <typename LHS, typename RHS>
struct RelopDispatch<LHS, RHS, GTE> {
	inline bool operator()(LHS lhs, RHS rhs) {
		return lhs > rhs || lhs == rhs;
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


template <LogicalTypeId LHS_LOGICAL, typename LHS, LogicalTypeId RHS_LOGICAL, typename RHS, Relop OP>
void BaseRRelopFunctionInt(DataChunk &args, ExpressionState &state, Vector &result) {
	auto parts = BinaryTypeAssert<LHS_LOGICAL, RHS_LOGICAL>(args);

	BinaryExecutor::Execute<LHS, RHS, bool>(parts.lefts, parts.rights, result, args.size(), relop<int32_t, int32_t, OP>);
}

template <LogicalTypeId LOGICAL, typename T, Relop OP>
void BaseRRelopFunctionSimple(DataChunk &args, ExpressionState &state, Vector &result) {
	auto parts = BinaryTypeAssert<LOGICAL, LOGICAL>(args);
	BinaryExecutor::Execute<T, T, bool>(parts.lefts, parts.rights, result, args.size(), relop<T, T, OP>);
}

template <Relop OP>
void BaseRRelopFunctionDouble(DataChunk &args, ExpressionState &state, Vector &result) {
	auto parts = BinaryTypeAssert<LogicalType::DOUBLE, LogicalType::DOUBLE>(args);
	auto fun = [&](double left, double right, ValidityMask &mask, idx_t idx) {
		if (isnan(left) || isnan(right)) {
			mask.SetInvalid(idx);
			return false;
		}
		return relop<double, double, OP>(left, right);
	};

	BinaryExecutor::ExecuteWithNulls<double, double, bool>(parts.lefts, parts.rights, result, args.size(), fun);
}

template <LogicalTypeId LOGICAL_TYPE, Relop OP>
void BaseRRelopFunctionDoubleInteger(DataChunk &args, ExpressionState &state, Vector &result) {
	using type = typename std::conditional<LOGICAL_TYPE == LogicalType::INTEGER, int32_t, bool>::type;

	auto parts = BinaryTypeAssert<LogicalType::DOUBLE, LOGICAL_TYPE>(args);
	auto exec = [](double left, type right, ValidityMask &mask, idx_t idx) {
		if (isnan(left)) {
			mask.SetInvalid(idx);
			return false;
		}
		return relop<double, type, OP>(left, right);
	};
	BinaryExecutor::ExecuteWithNulls<double, type, bool>(parts.lefts, parts.rights, result, args.size(), exec);
}

template <LogicalTypeId LOGICAL_TYPE, Relop OP>
void BaseRRelopFunctionIntegerDouble(DataChunk &args, ExpressionState &state, Vector &result) {
	using type = typename std::conditional<LOGICAL_TYPE == LogicalType::INTEGER, int32_t, bool>::type;

	auto parts = BinaryTypeAssert<LOGICAL_TYPE, LogicalType::DOUBLE>(args);
	auto exec = [](type left, double right, ValidityMask &mask, idx_t idx) {
		if (isnan(right)) {
			mask.SetInvalid(idx);
			return false;
		}
		return relop<type, double, OP>(left, right);
	};
	BinaryExecutor::ExecuteWithNulls<type, double, bool>(parts.lefts, parts.rights, result, args.size(), exec);
}

template <Relop OP>
void BaseRRelopFunctionString(DataChunk &args, ExpressionState &state, Vector &result) {
	auto parts = BinaryTypeAssert<LogicalType::VARCHAR, LogicalType::VARCHAR>(args);
	BinaryExecutor::Execute<string_t, string_t, bool>(parts.lefts, parts.rights, result, args.size(), relop<string_t, string_t, OP>);
}

template <Relop OP>
void BaseRRelopFunctionStringInteger(DataChunk &args, ExpressionState &state, Vector &result) {
	auto parts = BinaryTypeAssert<LogicalType::VARCHAR, LogicalType::INTEGER>(args);

	auto exec = [](string_t left, int32_t right) {
		char right_chr[100];
		snprintf(right_chr, sizeof(right_chr), "%d", right);
		return relop<string_t, string_t, OP>(left, right_chr);
	};
	return BinaryExecutor::Execute<string_t, int32_t, bool>(parts.lefts, parts.rights, result, args.size(), exec);
}

template <Relop OP>
void BaseRRelopFunctionIntegerString(DataChunk &args, ExpressionState &state, Vector &result) {
	auto parts = BinaryTypeAssert<LogicalType::INTEGER, LogicalType::VARCHAR>(args);

	auto exec = [](int32_t left, string_t right) {
		char left_chr[100];
		snprintf(left_chr, sizeof(left_chr), "%d", left);
		return relop<string_t, string_t, OP>(left_chr, right);
	};
	return BinaryExecutor::Execute<int32_t, string_t, bool>(parts.lefts, parts.rights, result, args.size(), exec);
}

template <Relop OP>
void BaseRRelopFunctionStringBoolean(DataChunk &args, ExpressionState &state, Vector &result) {
	auto parts = BinaryTypeAssert<LogicalType::VARCHAR, LogicalType::BOOLEAN>(args);

	auto exec = [](string_t left, bool right) {
		return relop<string_t, string_t, OP>(left, right ? "TRUE" : "FALSE");
	};
	return BinaryExecutor::Execute<string_t, bool, bool>(parts.lefts, parts.rights, result, args.size(), exec);
}

template <Relop OP>
void BaseRRelopFunctionBooleanString(DataChunk &args, ExpressionState &state, Vector &result) {
	auto parts = BinaryTypeAssert<LogicalType::BOOLEAN, LogicalType::VARCHAR>(args);

	auto exec = [](bool left, string_t right) {
		return relop<string_t, string_t, OP>(left ? "TRUE" : "FALSE", right);
	};
	return BinaryExecutor::Execute<bool, string_t, bool>(parts.lefts, parts.rights, result, args.size(), exec);
}

template <Relop OP>
void BaseRRelopFunctionStringDouble(DataChunk &args, ExpressionState &state, Vector &result) {
	auto parts = BinaryTypeAssert<LogicalType::VARCHAR, LogicalType::DOUBLE>(args);

	auto exec = [](string_t left, double right) {
		char right_chr[100];
		snprintf(right_chr, sizeof(right_chr), "%.17g", right);
		return relop<string_t, string_t, OP>(left, right_chr);
	};
	return BinaryExecutor::Execute<string_t, double, bool>(parts.lefts, parts.rights, result, args.size(), exec);
}

template <Relop OP>
void BaseRRelopFunctionDoubleString(DataChunk &args, ExpressionState &state, Vector &result) {
	auto parts = BinaryTypeAssert<LogicalType::DOUBLE, LogicalType::VARCHAR>(args);

	auto exec = [](double left, string_t right) {
		char left_chr[100];
		snprintf(left_chr, sizeof(left_chr), "%.17g", left);
		return relop<string_t, string_t, OP>(left_chr, right);
	};
	return BinaryExecutor::Execute<double, string_t, bool>(parts.lefts, parts.rights, result, args.size(), exec);
}

template <Relop OP>
ScalarFunctionSet base_r_relop(string name) {
	ScalarFunctionSet set(name);

	// (int | lgl) <=> (int | lgl)
	set.AddFunction(ScalarFunction({LogicalType::BOOLEAN, LogicalType::BOOLEAN}, LogicalType::BOOLEAN,
	                               BaseRRelopFunctionInt<LogicalType::BOOLEAN, bool, LogicalType::BOOLEAN, bool, OP>));
	set.AddFunction(ScalarFunction({LogicalType::BOOLEAN, LogicalType::INTEGER}, LogicalType::BOOLEAN,
	                               BaseRRelopFunctionInt<LogicalType::BOOLEAN, bool, LogicalType::INTEGER, int32_t, OP>));
	set.AddFunction(ScalarFunction({LogicalType::INTEGER, LogicalType::BOOLEAN}, LogicalType::BOOLEAN,
	                               BaseRRelopFunctionInt<LogicalType::INTEGER, int32_t, LogicalType::BOOLEAN, bool, OP>));
	set.AddFunction(
	    ScalarFunction({LogicalType::INTEGER, LogicalType::INTEGER}, LogicalType::BOOLEAN,
	                   BaseRRelopFunctionInt<LogicalType::INTEGER, int32_t, LogicalType::INTEGER, int32_t, OP>));

	// double <=> (int | lgl)
	set.AddFunction(ScalarFunction({LogicalType::DOUBLE, LogicalType::INTEGER}, LogicalType::BOOLEAN,
	                               BaseRRelopFunctionDoubleInteger<LogicalType::INTEGER, OP>));
	set.AddFunction(ScalarFunction({LogicalType::INTEGER, LogicalType::DOUBLE}, LogicalType::BOOLEAN,
	                               BaseRRelopFunctionIntegerDouble<LogicalType::INTEGER, OP>));
	set.AddFunction(ScalarFunction({LogicalType::DOUBLE, LogicalType::BOOLEAN}, LogicalType::BOOLEAN,
	                               BaseRRelopFunctionDoubleInteger<LogicalType::BOOLEAN, OP>));
	set.AddFunction(ScalarFunction({LogicalType::BOOLEAN, LogicalType::DOUBLE}, LogicalType::BOOLEAN,
	                               BaseRRelopFunctionIntegerDouble<LogicalType::BOOLEAN, OP>));

	// string <=> int
	set.AddFunction(ScalarFunction({LogicalType::VARCHAR, LogicalType::INTEGER}, LogicalType::BOOLEAN,
	                               BaseRRelopFunctionStringInteger<OP>));
	set.AddFunction(ScalarFunction({LogicalType::INTEGER, LogicalType::VARCHAR}, LogicalType::BOOLEAN,
	                               BaseRRelopFunctionIntegerString<OP>));

	// string <=> lgl
	set.AddFunction(ScalarFunction({LogicalType::VARCHAR, LogicalType::BOOLEAN}, LogicalType::BOOLEAN,
	                               BaseRRelopFunctionStringBoolean<OP>));
	set.AddFunction(ScalarFunction({LogicalType::BOOLEAN, LogicalType::VARCHAR}, LogicalType::BOOLEAN,
	                               BaseRRelopFunctionBooleanString<OP>));

	set.AddFunction(
	    ScalarFunction({LogicalType::DOUBLE, LogicalType::DOUBLE}, LogicalType::BOOLEAN, BaseRRelopFunctionDouble<OP>));
	set.AddFunction(
	    ScalarFunction({LogicalType::VARCHAR, LogicalType::VARCHAR}, LogicalType::BOOLEAN, BaseRRelopFunctionString<OP>));
	set.AddFunction(
	    ScalarFunction({LogicalType::VARCHAR, LogicalType::DOUBLE}, LogicalType::BOOLEAN, BaseRRelopFunctionStringDouble<OP>));
	set.AddFunction(
	    ScalarFunction({LogicalType::DOUBLE, LogicalType::VARCHAR}, LogicalType::BOOLEAN, BaseRRelopFunctionDoubleString<OP>));

	// timestamp <=> timestamp
	set.AddFunction(
		ScalarFunction({LogicalType::TIMESTAMP, LogicalType::TIMESTAMP}, LogicalType::BOOLEAN, BaseRRelopFunctionSimple<LogicalType::TIMESTAMP, timestamp_t, OP>));

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
