#ifndef TYPEASVALUE_SRC_LIST_OPERATION_CONCATENATE_H_
#define TYPEASVALUE_SRC_LIST_OPERATION_CONCATENATE_H_

#include "append.h"
#include "higher/fold.h"
#include "conditional/if.h"

namespace tav {

template <
	typename    Head,
	typename... Tail
>
using Concatenate = Fold<
	Append,
	void,
	If<
		Boolean<sizeof...(Tail) == 0>,
		Head,
		List<Head, Tail...>
	>
>;

}

#endif // TYPEASVALUE_SRC_LIST_OPERATION_CONCATENATE_H_
