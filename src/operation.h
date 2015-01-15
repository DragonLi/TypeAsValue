#ifndef TYPEASVALUE_SRC_OPERATION_H_
#define TYPEASVALUE_SRC_OPERATION_H_

#include "type.h"

namespace tav {

template <
	typename X,
	typename Y
>
struct add {
	static_assert(
		equal_type<X, Y>::value,
		"only values of the same type may be added"
	);

	typedef Int<X::value + Y::value> type;
};

template <
	typename X,
	typename Y
>
struct substract {
	static_assert(
		equal_type<X, Y>::value,
		"only values of the same type may be substracted"
	);

	typedef Int<X::value - Y::value> type;
};

}

#endif  // TYPEASVALUE_SRC_OPERATION_H_
