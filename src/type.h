#ifndef TYPEASVALUE_SRC_TYPE_H_
#define TYPEASVALUE_SRC_TYPE_H_

#include <type_traits>

namespace tav {

template <int Value>
using Int = typename std::integral_constant<int, Value>::type;

template <std::size_t Value>
using Size = typename std::integral_constant<std::size_t, Value>::type;

template <bool Value>
using Boolean = typename std::integral_constant<bool, Value>::type;

template <
	typename X,
	typename Y
>
using EqualType = typename std::is_same<
	typename X::value_type,
	typename Y::value_type
>::type;

template <
	typename X,
	typename Y
>
using EqualValue = Boolean<X::value == Y::value>;

}

#endif  // TYPEASVALUE_SRC_TYPE_H_
