#ifndef TYPEASVALUE_SRC_CONDITIONAL_COND_H_
#define TYPEASVALUE_SRC_CONDITIONAL_COND_H_

#include "type.h"
#include "list/cons.h"
#include "list/detail/find_variadic.h"

namespace tav {

namespace detail {

template <typename... Branches>
class select_cond_branch {
	private:
		template <typename Pair>
		using predicate = IsTrue<Car<Pair>>;

	public:
		using type = Eval<detail::find_variadic<predicate, Branches...>>;

	static_assert(
		IsPair<type>::value,
		"all branch conditions resolve to false"
	);
};

}

template <typename... Branches>
using Cond = Cdr<Eval<detail::select_cond_branch<Branches...>>>;

template <
	typename Condition,
	typename Result
>
using Branch = Pair<Condition, Result>;

template <typename Result>
using Else = Branch<Boolean<true>, Result>;

}

#endif  // TYPEASVALUE_SRC_CONDITIONAL_COND_H_
