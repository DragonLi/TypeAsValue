#ifndef TYPEASVALUE_SRC_TYPE_H_
#define TYPEASVALUE_SRC_TYPE_H_

#include <type_traits>

namespace tav {

template <int Value>
using Int = std::integral_constant<int, Value>;

template <std::size_t Value>
using Size = std::integral_constant<std::size_t, Value>;

template <bool Value>
using Boolean = std::integral_constant<bool, Value>;

template <char Value>
using Char = std::integral_constant<char, Value>;

template <
	typename X,
	typename Y
>
using IsEqualType = typename std::is_same<
	typename X::value_type,
	typename Y::value_type
>::type;

template <
	typename X,
	typename Y
>
using IsEqualValue = Boolean<X::value == Y::value>;

template <typename X>
using IsTrue = IsEqualValue<X, Boolean<true>>;

}

#endif  // TYPEASVALUE_SRC_TYPE_H_
