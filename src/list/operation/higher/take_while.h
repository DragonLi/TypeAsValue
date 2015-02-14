#ifndef TYPEASVALUE_SRC_LIST_OPERATION_HIGHER_TAKE_WHILE_H_
#define TYPEASVALUE_SRC_LIST_OPERATION_HIGHER_TAKE_WHILE_H_

#include "conditional/if.h"

namespace tav {

template <
	template<typename> class Predicate,
	typename                 Current
>
struct TakeWhile {
	typedef Eval<If<
		Eval<Predicate<Head<Current>>>,
		Eval<Cons<
			Head<Current>,
			Eval<TakeWhile<Predicate, Tail<Current>>>
		>>,
		void
	>> type;
};

template <
	template<typename> class Predicate
>
struct TakeWhile<Predicate, void> {
	typedef void type;
};

}

#endif  // TYPEASVALUE_SRC_LIST_OPERATION_HIGHER_TAKE_WHILE_H_
