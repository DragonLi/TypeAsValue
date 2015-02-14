#ifndef TYPEASVALUE_SRC_LIST_OPERATION_TAKE_H_
#define TYPEASVALUE_SRC_LIST_OPERATION_TAKE_H_

#include "operation/math.h"

namespace tav {

template <
	typename Count,
	typename Current
>
struct Take {
	typedef Eval<Cons<
		Head<Current>,
		Eval<Take<
			Substract<Count, Size<1>>,
			Tail<Current>
		>>
	>> type;
};

template <typename Current>
struct Take<Size<0>, Current> {
	typedef void type;
};

template <typename Count>
struct Take<Count, void> {
	typedef void type;
};

template <>
struct Take<Size<0>, void> {
	typedef void type;
};


}

#endif  // TYPEASVALUE_SRC_LIST_OPERATION_TAKE_H_
