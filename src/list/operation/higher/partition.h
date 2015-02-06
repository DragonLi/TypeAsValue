#ifndef TYPEASVALUE_SRC_LIST_OPERATION_HIGHER_PARTITION_H_
#define TYPEASVALUE_SRC_LIST_OPERATION_HIGHER_PARTITION_H_

#include "filter.h"

namespace tav {

template <
	template<typename> class Predicate,
	typename                 List
>
using Partition = Cons<
	typename Filter<Predicate, List>::type,
	typename Remove<Predicate, List>::type
>;

}

#endif  // TYPEASVALUE_SRC_LIST_OPERATION_HIGHER_PARTITION_H_
