#ifndef TYPEASVALUE_SRC_LIST_OPERATION_HIGHER_LIST_INDEX_H_
#define TYPEASVALUE_SRC_LIST_OPERATION_HIGHER_LIST_INDEX_H_

#include "operation/math.h"

namespace tav {

namespace detail {

template <
	template<typename> class Predicate,
	typename                 List,
	typename                 Index = Size<0>
>
struct index_of_first {
	typedef If<
		Eval<Predicate<Head<List>>>,
		Index,
		Eval<index_of_first<
			Predicate,
			Tail<List>,
			Add<Index, Size<1>>
		>>
	> type;
};

template <
	template<typename> class Predicate,
	typename                 Index
>
struct index_of_first<Predicate, void, Index> {
	typedef Boolean<false> type;
};

}

template <
	template<typename> class Predicate,
	typename                 List
>
using ListIndex = Eval<detail::index_of_first<Predicate, List>>;

}

#endif  // TYPEASVALUE_SRC_LIST_OPERATION_HIGHER_LIST_INDEX_H_
