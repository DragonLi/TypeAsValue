#ifndef TYPEASVALUE_SRC_LIST_OPERATION_NTH_H_
#define TYPEASVALUE_SRC_LIST_OPERATION_NTH_H_

#include "operation/math.h"

namespace tav {

namespace detail {

template <
	typename Index,
	typename List
>
struct Nth {
	typedef Eval<Nth<
		Substract<Index, Size<1>>,
		Tail<List>
	>> type;
};

template <typename List>
struct Nth<Size<0>, List> {
	typedef Head<List> type;
};

template <typename Index>
struct Nth<Index, void> {
	typedef void type;
};

template <>
struct Nth<Size<0>, void> {
	typedef void type;
};

}

template <
	typename Index,
	typename List
>
using Nth = Eval<detail::Nth<Index, List>>;

template <typename List>
using First  = Nth<Size<0>, List>;

template <typename List>
using Second = Nth<Size<1>, List>;

template <typename List>
using Third  = Nth<Size<2>, List>;

}

#endif  // TYPEASVALUE_SRC_LIST_OPERATION_NTH_H_
