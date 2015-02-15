#ifndef TYPEASVALUE_SRC_LIST_OPERATION_HIGHER_DROP_WHILE_H_
#define TYPEASVALUE_SRC_LIST_OPERATION_HIGHER_DROP_WHILE_H_

#include "conditional/if.h"

namespace tav {

namespace detail {

template <
	template<typename> class Predicate,
	typename                 Current
>
struct DropWhile {
	typedef If<
		Eval<Predicate<Head<Current>>>,
		Eval<DropWhile<Predicate, Tail<Current>>>,
		Current
	> type;
};

template <
	template<typename> class Predicate
>
struct DropWhile<Predicate, void> {
	typedef void type;
};

}

template <
	template<typename> class Predicate,
	typename                 Current
>
using DropWhile = Eval<detail::DropWhile<Predicate, Current>>;

}

#endif  // TYPEASVALUE_SRC_LIST_OPERATION_HIGHER_DROP_WHILE_H_
