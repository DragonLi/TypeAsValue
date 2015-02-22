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

template <typename Function>
using Eval = typename Function::type;

template <
	typename X,
	typename Y
>
using IsEqual = Eval<std::is_same<X, Y>>;

template <
	typename X,
	typename Y
>
using IsEqualType = IsEqual<
	typename X::value_type,
	typename Y::value_type
>;

template <
	typename X,
	typename Y
>
using IsEqualValue = Boolean<X::value == Y::value>;

template <typename X>
using IsBoolean = IsEqual<typename X::value_type, bool>;

template <typename X>
using IsTrue = IsEqualValue<X, Boolean<true>>;

template <typename X>
using IsSize = IsEqual<typename X::value_type, std::size_t>;

}

#endif  // TYPEASVALUE_SRC_TYPE_H_
