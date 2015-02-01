#ifndef TYPEASVALUE_SRC_LIST_OPERATION_HIGHER_DROP_WHILE_H_
#define TYPEASVALUE_SRC_LIST_OPERATION_HIGHER_DROP_WHILE_H_

#include "conditional/if.h"

namespace tav {

template <
	template<typename> class Predicate,
	typename                 Current
>
struct DropWhile {
	typedef If<
		Predicate<Head<Current>>::type::value,
		typename DropWhile<Predicate, Tail<Current>>::type,
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

#endif  // TYPEASVALUE_SRC_LIST_OPERATION_HIGHER_DROP_WHILE_H_
