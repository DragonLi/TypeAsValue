#ifndef TYPEASVALUE_SRC_LIST_OPERATION_HIGHER_FIND_H_
#define TYPEASVALUE_SRC_LIST_OPERATION_HIGHER_FIND_H_

#include "type.h"
#include "conditional/if.h"

namespace tav {

template <
	template<typename> class Predicate,
	typename                 Current
>
struct Find {
	typedef If<
		Predicate<Head<Current>>::type::value,
		Head<Current>,
		typename Find<Predicate, Tail<Current>>::type
	> type;
};

template <
	template<typename> class Predicate
>
struct Find<Predicate, void> {
	typedef Boolean<false> type;
};

}

#endif  // TYPEASVALUE_SRC_LIST_OPERATION_HIGHER_FIND_H_
