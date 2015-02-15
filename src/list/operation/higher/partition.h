#ifndef TYPEASVALUE_SRC_LIST_OPERATION_HIGHER_PARTITION_H_
#define TYPEASVALUE_SRC_LIST_OPERATION_HIGHER_PARTITION_H_

#include "filter.h"
#include "remove.h"

namespace tav {

template <
	template<typename> class Predicate,
	typename                 Elements
>
using Partition = Cons<
	Filter<Predicate, Elements>,
	Remove<Predicate, Elements>
>;

}

#endif  // TYPEASVALUE_SRC_LIST_OPERATION_HIGHER_PARTITION_H_
