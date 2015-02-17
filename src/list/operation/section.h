#ifndef TYPEASVALUE_SRC_LIST_OPERATION_SECTION_H_
#define TYPEASVALUE_SRC_LIST_OPERATION_SECTION_H_

#include "operation/math.h"

namespace tav {

namespace detail {

template <
	typename Index,
	typename Count,
	typename List
>
struct take_count_at {
	typedef Eval<take_count_at<
		Substract<Index, Size<1>>,
		Count,
		Tail<List>
	>> type;
};

template <
	typename Count,
	typename List
>
struct take_count_at<Size<0>, Count, List> {
	typedef Cons<
		Head<List>,
		Eval<take_count_at<
			Size<0>,
			Substract<Count, Size<1>>,
			Tail<List>
		>>
	> type;
};

template <
	typename Index,
	typename Count
>
struct take_count_at<Index, Count, void> {
	typedef void type;
};

template <typename Count>
struct take_count_at<Size<0>, Count, void> {
	typedef void type;
};

template <typename List>
struct take_count_at<Size<0>, Size<0>, List> {
	typedef void type;
};

template <>
struct take_count_at<Size<0>, Size<0>, void> {
	typedef void type;
};

}

template <
	typename Start,
	typename End,
	typename List
>
using Section = Eval<detail::take_count_at<
	Start,
	Substract<Add<End, Size<1>>, Start>,
	List
>>;

}

#endif  // TYPEASVALUE_SRC_LIST_OPERATION_SECTION_H_
