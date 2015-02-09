#ifndef TYPEASVALUE_SRC_LIST_OPERATION_HIGHER_PARTITION_H_
#define TYPEASVALUE_SRC_LIST_OPERATION_HIGHER_PARTITION_H_

#include "filter.h"

namespace tav {

template <
	template<typename> class Predicate,
	typename                 Elements
>
using Partition = Cons<
	typename Filter<Predicate, Elements>::type,
	typename Remove<Predicate, Elements>::type
>;

}

#endif  // TYPEASVALUE_SRC_LIST_OPERATION_HIGHER_PARTITION_H_
