#ifndef TYPEASVALUE_SRC_LIST_OPERATION_DROP_H_
#define TYPEASVALUE_SRC_LIST_OPERATION_DROP_H_

#include "operation/math.h"

namespace tav {

namespace detail {

template <
	typename Count,
	typename Current
>
struct Drop {
	typedef Eval<Drop<
		Substract<Count, Size<1>>,
		Tail<Current>
	>> type;
};

template <typename Current>
struct Drop<Size<0>, Current> {
	typedef Current type;
};

template <typename Count>
struct Drop<Count, void> {
	typedef void type;
};

template <>
struct Drop<Size<0>, void> {
	typedef void type;
};

}

template <
	typename Count,
	typename Current
>
using Drop = Eval<detail::Drop<Count, Current>>;

}

#endif  // TYPEASVALUE_SRC_LIST_OPERATION_DROP_H_
