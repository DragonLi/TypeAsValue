#ifndef TYPEASVALUE_SRC_OPERATION_MATH_H_
#define TYPEASVALUE_SRC_OPERATION_MATH_H_

#include "type.h"
#include "logic.h"

namespace tav {

template <
	typename X,
	typename Y
>
using Add = std::integral_constant<
	decltype(X::value + Y::value),
	X::value + Y::value
>;

template <
	typename X,
	typename Y
>
using Substract = std::integral_constant<
	decltype(X::value - Y::value),
	X::value - Y::value
>;

template <
	typename X,
	typename Y
>
using Multiply = std::integral_constant<
	decltype(X::value * Y::value),
	X::value * Y::value
>;

template <
	typename X,
	typename Y
>
using Divide = std::integral_constant<
	decltype(X::value / Y::value),
	X::value / Y::value
>;

template <typename Base>
using Square = Multiply<Base, Base>;

template <
	typename X,
	typename Y
>
using Modulo = std::integral_constant<
	decltype(X::value % Y::value),
	X::value % Y::value
>;

template <typename X>
using Even = IsEqualValue<
	Modulo<X, Size<2>>,
	Size<0>
>;

template <typename X>
using Odd = Not<Even<X>>;

template <
	typename X,
	typename Y
>
using GreaterThan = Boolean<(X::value > Y::value)>;

template <
	typename X,
	typename Y
>
using LowerThan = Boolean<(X::value < Y::value)>;

}

#endif  // TYPEASVALUE_SRC_OPERATION_MATH_H_
