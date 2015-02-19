#ifndef TYPEASVALUE_SRC_LIST_OPERATION_HIGHER_FIND_H_
#define TYPEASVALUE_SRC_LIST_OPERATION_HIGHER_FIND_H_

#include "utility/predicate.h"
#include "function/apply.h"
#include "list/operation/nth.h"
#include "list_index.h"

namespace tav {

template <
	template<typename> class Predicate,
	typename                 List
>
using Find = typename utility::predicate_guard<
	IsSize,
	Apply<Nth, _0, List>::template function,
	Boolean<false>
>::template check<
	ListIndex<Predicate, List>
>;


}

#endif  // TYPEASVALUE_SRC_LIST_OPERATION_HIGHER_FIND_H_
