#ifndef TYPEASVALUE_SRC_LIST_OPERATION_BASIC_H_
#define TYPEASVALUE_SRC_LIST_OPERATION_BASIC_H_

#include "operation/math.h"

namespace tav {

template <typename Cons>
struct Length {
	typedef Add<
		Size<1>,
		typename Length<Tail<Cons>
	>::type> type;
};

template <>
struct Length<void> {
	typedef Size<0> type;
};

template <
	typename Index,
	typename Cons
>
struct Nth {
	typedef If<
		equal_value<Index, Size<0>>::value,
		Head<Cons>,
		typename Nth<Substract<Index, Size<1>>, Tail<Cons>>::type
	> type;
};

template <typename Index>
struct Nth<Index, void> {
	typedef void type;
};

}

#endif  // TYPEASVALUE_SRC_LIST_OPERATION_BASIC_H_
