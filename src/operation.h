#ifndef TYPEASVALUE_SRC_OPERATION_H_
#define TYPEASVALUE_SRC_OPERATION_H_

#include "type.h"

namespace tav {

template <
	typename X,
	typename Y
>
struct add {
	static_assert(
		equal_type<X, Y>::value,
		"only values of the same type may be added"
	);

	typedef std::integral_constant<
		decltype(X::value + Y::value),
		X::value + Y::value
	> type;
};

template <
	typename X,
	typename Y
>
struct substract {
	static_assert(
		equal_type<X, Y>::value,
		"only values of the same type may be substracted"
	);

	typedef std::integral_constant<
		decltype(X::value - Y::value),
		X::value - Y::value
	> type;
};

template <
	typename X,
	typename Y
>
struct multiply {
	static_assert(
		equal_type<X, Y>::value,
		"only values of the same type may be multiplied"
	);

	typedef std::integral_constant<
		decltype(X::value * Y::value),
		X::value * Y::value
	> type;
};

template <
	typename X,
	typename Y
>
struct divide {
	static_assert(
		equal_type<X, Y>::value,
		"only values of the same type may be divided"
	);

	typedef std::integral_constant<
		decltype(X::value / Y::value),
		X::value / Y::value
	> type;
};

}

#endif  // TYPEASVALUE_SRC_OPERATION_H_
