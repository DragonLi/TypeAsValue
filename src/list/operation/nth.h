#ifndef TYPEASVALUE_SRC_LIST_OPERATION_NTH_H_
#define TYPEASVALUE_SRC_LIST_OPERATION_NTH_H_

#include "operation/math.h"

namespace tav {

template <
	typename Index,
	typename Cons
>
struct Nth {
	typedef typename Nth<
		Substract<Index, Size<1>>,
		Tail<Cons>
	>::type type;
};

template <typename Cons>
struct Nth<Size<0>, Cons> {
	typedef Head<Cons> type;
};

template <typename Index>
struct Nth<Index, void> {
	typedef void type;
};

}

#endif  // TYPEASVALUE_SRC_LIST_OPERATION_NTH_H_
