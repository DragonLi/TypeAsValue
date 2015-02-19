#ifndef TYPEASVALUE_SRC_CONDITIONAL_COND_H_
#define TYPEASVALUE_SRC_CONDITIONAL_COND_H_

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

}

#endif  // TYPEASVALUE_SRC_CONDITIONAL_COND_H_
