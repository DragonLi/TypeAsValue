#ifndef TYPEASVALUE_SRC_LIST_OPERATION_HIGHER_QUERY_H_
#define TYPEASVALUE_SRC_LIST_OPERATION_HIGHER_QUERY_H_

#include "fold.h"
#include "misc.h"
#include "operation/math.h"
#include "operation/logic.h"

namespace tav {

template <
	template<typename> class Function,
	typename                 List
>
using Any = Fold<
	Or,
	Boolean<false>,
	typename Map<Function, List>::type
>;

template <
	template<typename> class Function,
	typename                 List
>
using All = Fold<
	And,
	Boolean<true>,
	typename Map<Function, List>::type
>;

template <
	template<typename> class Function,
	typename                 List
>
using None = Not<
	typename Any<Function, List>::type
>;

template <
	template<typename> class Function,
	typename                 List
>
using Count = Fold<
	Add,
	tav::Size<0>,
	typename Map<Function, List>::type
>;

}

#endif  // TYPEASVALUE_SRC_LIST_OPERATION_HIGHER_QUERY_H_
