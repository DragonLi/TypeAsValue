#ifndef TYPEASVALUE_SRC_LIST_OPERATION_HIGHER_TAKE_WHILE_H_
#define TYPEASVALUE_SRC_LIST_OPERATION_HIGHER_TAKE_WHILE_H_

#include "type.h"
#include "conditional/if.h"

namespace tav {

template <
	template<typename> class Predicate,
	typename                 Current
>
struct TakeWhile {
	typedef If<
		Predicate<Head<Current>>::type::value,
		Cons<
			Head<Current>,
			typename TakeWhile<Predicate, Tail<Current>>::type
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

#endif  // TYPEASVALUE_SRC_LIST_OPERATION_HIGHER_TAKE_WHILE_H_
