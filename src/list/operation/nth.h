#ifndef TYPEASVALUE_SRC_LIST_OPERATION_NTH_H_
#define TYPEASVALUE_SRC_LIST_OPERATION_NTH_H_

#include "operation/math.h"

namespace tav {

template <
	typename Index,
	typename Pair
>
struct Nth {
	typedef Eval<Nth<
		Substract<Index, Size<1>>,
		Tail<Pair>
	>> type;
};

template <typename Pair>
struct Nth<Size<0>, Pair> {
	typedef Head<Pair> type;
};

template <typename Index>
struct Nth<Index, void> {
	typedef void type;
};

template <>
struct Nth<Size<0>, void> {
	typedef void type;
};

template <typename List>
using First  = Eval<Nth<Size<0>, List>>;

template <typename List>
using Second = Eval<Nth<Size<1>, List>>;

template <typename List>
using Third  = Eval<Nth<Size<2>, List>>;

}

#endif  // TYPEASVALUE_SRC_LIST_OPERATION_NTH_H_
