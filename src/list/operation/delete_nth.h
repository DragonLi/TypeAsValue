#ifndef TYPEASVALUE_SRC_LIST_OPERATION_DELETE_NTH_H_
#define TYPEASVALUE_SRC_LIST_OPERATION_DELETE_NTH_H_

#include "list/operation/append.h"
#include "list/operation/take.h"
#include "list/operation/drop.h"

namespace tav {

template <
	typename Index,
	typename List
>
using DeleteNth = Append<
	Take<Index, List>,
	Drop<Add<Index, Size<1>>, List>
>;

}

#endif  // TYPEASVALUE_SRC_LIST_OPERATION_DELETE_NTH_H_
