#ifndef TYPEASVALUE_SRC_CONDITIONAL_COND_H_
#define TYPEASVALUE_SRC_CONDITIONAL_COND_H_

#include "type.h"
#include "list/cons.h"
#include "list/detail/find_variadic.h"

namespace tav {

namespace detail {

template <typename Pair>
using cond_predicate = IsTrue<Car<Pair>>;

}

template <typename... Branches>
using Cond = Cdr<Eval<
	detail::find_variadic<detail::cond_predicate, Branches...>
>>;

template <
	typename Condition,
	typename Result
>
using Branch = Pair<Condition, Result>;

template <typename Result>
using Else = Branch<Boolean<true>, Result>;

}

#endif  // TYPEASVALUE_SRC_CONDITIONAL_COND_H_
