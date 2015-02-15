#ifndef TYPEASVALUE_SRC_CONDITIONAL_COND_H_
#define TYPEASVALUE_SRC_CONDITIONAL_COND_H_

#include <type_traits>

#include "list/list.h"
#include "list/operation/higher/find.h"

namespace tav {

namespace detail {

template <typename Pair>
using cond_predicate = IsTrue<Car<Pair>>;

}

template <typename... Branches>
using Cond = Cdr<
	Find<
		detail::cond_predicate,
		List<Branches...>
	>
>;

}

#endif  // TYPEASVALUE_SRC_CONDITIONAL_COND_H_
