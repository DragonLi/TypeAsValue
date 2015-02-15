#ifndef TYPEASVALUE_SRC_LIST_OPERATION_HIGHER_MAP_H_
#define TYPEASVALUE_SRC_LIST_OPERATION_HIGHER_MAP_H_

#include "fold.h"

namespace tav {

namespace detail {

template <template<typename> class Function>
struct map_transformation {
	template <
		typename Current,
		typename Previous
	>
	using function = Cons<
		Eval<Function<Current>>,
		Previous
	>;
};

}

template <
	template<typename> class Function,
	typename                 List
>
using Map = Fold<
	detail::map_transformation<Function>::template function,
	void,
	List
>;

}

#endif  // TYPEASVALUE_SRC_LIST_OPERATION_HIGHER_MAP_H_
