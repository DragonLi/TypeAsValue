#ifndef TYPEASVALUE_SRC_LIST_OPERATION_CONCATENATE_H_
#define TYPEASVALUE_SRC_LIST_OPERATION_CONCATENATE_H_

#include "append.h"
#include "higher/fold.h"

namespace tav {

template <typename ListOfLists>
using Concatenate = Fold<
	Append,
	void,
	ListOfLists
>;

}

#endif // TYPEASVALUE_SRC_LIST_OPERATION_CONCATENATE_H_
