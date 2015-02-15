#ifndef TYPEASVALUE_SRC_LIST_OPERATION_HIGHER_TAKE_WHILE_H_
#define TYPEASVALUE_SRC_LIST_OPERATION_HIGHER_TAKE_WHILE_H_

#include "conditional/if.h"

namespace tav {

namespace detail {

template <
	template<typename> class Predicate,
	typename                 Current
>
struct TakeWhile {
	typedef If<
		Eval<Predicate<Head<Current>>>,
		Cons<
			Head<Current>,
			Eval<TakeWhile<Predicate, Tail<Current>>>
		>,
		void
	> type;
};

template <
	template<typename> class Predicate
>
struct TakeWhile<Predicate, void> {
	typedef void type;
};

}

template <
	template<typename> class Predicate,
	typename                 Current
>
using TakeWhile = Eval<detail::TakeWhile<Predicate, Current>>;

}

#endif  // TYPEASVALUE_SRC_LIST_OPERATION_HIGHER_TAKE_WHILE_H_
