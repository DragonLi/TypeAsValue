#ifndef TYPEASVALUE_SRC_LIST_OPERATION_NTH_H_
#define TYPEASVALUE_SRC_LIST_OPERATION_NTH_H_

#include "drop.h"
#include "conditional/if.h"
#include "operation/math.h"

namespace tav {

template <
	typename Index,
	typename List
>
using Nth = If<
	IsPair<Drop<Index, List>>,
	Head<Drop<Index, List>>,
	void
>;

template <typename List>
using First  = Nth<Size<0>, List>;

template <typename List>
using Second = Nth<Size<1>, List>;

template <typename List>
using Third  = Nth<Size<2>, List>;

}

#endif  // TYPEASVALUE_SRC_LIST_OPERATION_NTH_H_
