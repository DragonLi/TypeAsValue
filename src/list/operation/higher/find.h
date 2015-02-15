#ifndef TYPEASVALUE_SRC_LIST_OPERATION_HIGHER_FIND_H_
#define TYPEASVALUE_SRC_LIST_OPERATION_HIGHER_FIND_H_

#include "type.h"
#include "conditional/if.h"

namespace tav {

namespace detail {

template <
	template<typename> class Predicate,
	typename                 Current
>
struct Find {
	typedef If<
		Eval<Predicate<Head<Current>>>,
		Head<Current>,
		Eval<Find<Predicate, Tail<Current>>>
	> type;
};

template <
	template<typename> class Predicate
>
struct Find<Predicate, void> {
	typedef Boolean<false> type;
};

}

template <
	template<typename> class Predicate,
	typename                 List
>
using Find = Eval<detail::Find<Predicate, List>>;

}

#endif  // TYPEASVALUE_SRC_LIST_OPERATION_HIGHER_FIND_H_
