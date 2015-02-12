#ifndef TYPEASVALUE_SRC_LIST_OPERATION_DELETE_H_
#define TYPEASVALUE_SRC_LIST_OPERATION_DELETE_H_

#include "type.h"
#include "higher/filter.h"
#include "function/apply.h"

namespace tav {

template <
	typename Element,
	typename List
>
using Delete = Remove<
	Apply<IsEqualValue, _0, Element>::template type,
	List
>;

}

#endif  // TYPEASVALUE_SRC_LIST_OPERATION_DELETE_H_
