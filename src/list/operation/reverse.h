#ifndef TYPEASVALUE_SRC_LIST_OPERATION_REVERSE_H_
#define TYPEASVALUE_SRC_LIST_OPERATION_REVERSE_H_

#include "append.h"
#include "higher/fold.h"

namespace tav {

namespace detail {

template <
	typename Current,
	typename Previous
>
using reversed_append = Append<Previous, List<Current>>;

}

template <typename Sequence>
using Reverse = Fold<detail::reversed_append, void, Sequence>;

}

#endif  // TYPEASVALUE_SRC_LIST_OPERATION_REVERSE_H_
