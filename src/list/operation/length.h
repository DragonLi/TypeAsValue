#ifndef TYPEASVALUE_SRC_LIST_OPERATION_LENGTH_H_
#define TYPEASVALUE_SRC_LIST_OPERATION_LENGTH_H_

#include "higher/fold.h"
#include "operation/math.h"

namespace tav {

namespace detail {

template <typename, typename Accumulated>
using length_accumulate = Add<Size<1>, Accumulated>;

}

template <typename List>
using Length = Fold<detail::length_accumulate, Size<0>, List>;

}

#endif  // TYPEASVALUE_SRC_LIST_OPERATION_LENGTH_H_
