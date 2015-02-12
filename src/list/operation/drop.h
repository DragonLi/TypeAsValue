#ifndef TYPEASVALUE_SRC_LIST_OPERATION_DROP_H_
#define TYPEASVALUE_SRC_LIST_OPERATION_DROP_H_

#include "operation/math.h"

namespace tav {

template <
	typename Count,
	typename Current
>
struct Drop {
	typedef typename Drop<
		Substract<Count, Size<1>>,
		Tail<Current>
	>::type type;
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

#endif  // TYPEASVALUE_SRC_LIST_OPERATION_DROP_H_
