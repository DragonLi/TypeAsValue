#ifndef TYPEASVALUE_SRC_LIST_OPERATION_BASIC_H_
#define TYPEASVALUE_SRC_LIST_OPERATION_BASIC_H_

#include "higher/fold.h"
#include "function/apply.h"
#include "operation/math.h"

namespace tav {

template <typename Pair>
using Length = Fold<
	Apply<Add, Size<1>, _1>::pair_type,
	Size<0>,
	Pair
>;

}

#endif  // TYPEASVALUE_SRC_LIST_OPERATION_BASIC_H_
