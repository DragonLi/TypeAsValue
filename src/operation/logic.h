#ifndef TYPEASVALUE_SRC_OPERATION_LOGIC_H_
#define TYPEASVALUE_SRC_OPERATION_LOGIC_H_

#include "type.h"

namespace tav {

template <
	typename X,
	typename Y
>
using And = Boolean<X::value && Y::value>;

template <
	typename X,
	typename Y
>
using Or = Boolean<X::value || Y::value>;

template <
	typename X,
	typename Y
>
using Xor = Boolean<X::value ^ Y::value>;

template <typename X>
using Not = Boolean<!X::value>;

}

#endif // TYPEASVALUE_SRC_OPERATION_LOGIC_H_
