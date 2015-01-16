#ifndef TYPEASVALUE_SRC_OPERATION_MATH_H_
#define TYPEASVALUE_SRC_OPERATION_MATH_H_

#include "type.h"

namespace tav {

template <
	typename X,
	typename Y
>
using add = typename std::integral_constant<
	decltype(X::value + Y::value),
	X::value + Y::value
>::type;

template <
	typename X,
	typename Y
>
using substract = typename std::integral_constant<
	decltype(X::value - Y::value),
	X::value - Y::value
>::type;

template <
	typename X,
	typename Y
>
using multiply = typename std::integral_constant<
	decltype(X::value * Y::value),
	X::value * Y::value
>::type;

template <
	typename X,
	typename Y
>
using divide = typename std::integral_constant<
	decltype(X::value / Y::value),
	X::value / Y::value
>::type;

}

#endif  // TYPEASVALUE_SRC_OPERATION_MATH_H_
