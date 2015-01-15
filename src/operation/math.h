#ifndef TYPEASVALUE_SRC_OPERATION_MATH_H_
#define TYPEASVALUE_SRC_OPERATION_MATH_H_

#include "type.h"

namespace tav {

template <
	typename X,
	typename Y
>
struct add {
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
	typedef std::integral_constant<
		decltype(X::value / Y::value),
		X::value / Y::value
	> type;
};

}

#endif  // TYPEASVALUE_SRC_OPERATION_MATH_H_
