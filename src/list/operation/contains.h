#ifndef TYPEASVALUE_SRC_LIST_OPERATION_CONTAINS_H_
#define TYPEASVALUE_SRC_LIST_OPERATION_CONTAINS_H_

#include "type.h"
#include "higher/query.h"
#include "function/apply.h"

namespace tav {

template <
	typename Element,
	typename List
>
using Contains = Any<
	Apply<IsEqualValue, _0, Element>::template function,
	List
>;

}

#endif  // TYPEASVALUE_SRC_LIST_OPERATION_CONTAINS_H_
