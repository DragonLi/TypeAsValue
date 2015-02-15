#ifndef TYPEASVALUE_SRC_LIST_OPERATION_HIGHER_QUERY_H_
#define TYPEASVALUE_SRC_LIST_OPERATION_HIGHER_QUERY_H_

#include "fold.h"
#include "map.h"
#include "operation/math.h"
#include "operation/logic.h"

namespace tav {

template <
	template<typename> class Predicate,
	typename                 List
>
using Any = Fold<
	Or,
	Boolean<false>,
	Map<Predicate, List>
>;

template <
	template<typename> class Predicate,
	typename                 List
>
using All = Fold<
	And,
	Boolean<true>,
	Map<Predicate, List>
>;

template <
	template<typename> class Predicate,
	typename                 List
>
using None = Not<Any<Predicate, List>>;

template <
	template<typename> class Predicate,
	typename                 List
>
using Count = Fold<
	Add,
	Size<0>,
	Map<Predicate, List>
>;

}

#endif  // TYPEASVALUE_SRC_LIST_OPERATION_HIGHER_QUERY_H_
