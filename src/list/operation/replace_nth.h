#ifndef TYPEASVALUE_SRC_LIST_OPERATION_REPLACE_NTH_H_
#define TYPEASVALUE_SRC_LIST_OPERATION_REPLACE_NTH_H_

#include "list/operation/concatenate.h"
#include "list/operation/take.h"
#include "list/operation/drop.h"

namespace tav {

template <
	typename Index,
	typename Value,
	typename Sequence
>
using ReplaceNth = Concatenate<List<
	Take<Index, Sequence>,
	List<Value>,
	Drop<Add<Index, Size<1>>, Sequence>
>>;

}

#endif  // TYPEASVALUE_SRC_LIST_OPERATION_REPLACE_NTH_H_
