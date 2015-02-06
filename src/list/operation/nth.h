#ifndef TYPEASVALUE_SRC_LIST_OPERATION_NTH_H_
#define TYPEASVALUE_SRC_LIST_OPERATION_NTH_H_

#include "operation/math.h"

namespace tav {

template <
	typename Index,
	typename Pair
>
struct Nth {
	typedef typename Nth<
		Substract<Index, Size<1>>,
		Tail<Pair>
	>::type type;
};

template <typename Pair>
struct Nth<Size<0>, Pair> {
	typedef Head<Pair> type;
};

template <typename Index>
struct Nth<Index, void> {
	typedef void type;
};

}

#endif  // TYPEASVALUE_SRC_LIST_OPERATION_NTH_H_
