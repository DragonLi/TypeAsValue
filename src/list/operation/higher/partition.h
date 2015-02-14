#ifndef TYPEASVALUE_SRC_LIST_OPERATION_HIGHER_PARTITION_H_
#define TYPEASVALUE_SRC_LIST_OPERATION_HIGHER_PARTITION_H_

#include "filter.h"

namespace tav {

template <
	template<typename> class Predicate,
	typename                 Elements
>
using Partition = Cons<
	Eval<Filter<Predicate, Elements>>,
	Eval<Remove<Predicate, Elements>>
>;

}

#endif  // TYPEASVALUE_SRC_LIST_OPERATION_HIGHER_PARTITION_H_
