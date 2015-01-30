#ifndef TYPEASVALUE_SRC_LIST_OPERATION_HIGHER_PARTITION_H_
#define TYPEASVALUE_SRC_LIST_OPERATION_HIGHER_PARTITION_H_

#include "filter.h"

namespace tav {

template <
	template<typename> class Predicate,
	typename                 List
>
struct Partition {
	typedef Cons<
		typename Filter<Predicate, List>::type,
		typename Remove<Predicate, List>::type
	> type;
};

}

#endif  // TYPEASVALUE_SRC_LIST_OPERATION_HIGHER_PARTITION_H_
