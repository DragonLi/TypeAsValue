#ifndef TYPEASVALUE_SRC_LIST_OPERATION_HIGHER_MAP_H_
#define TYPEASVALUE_SRC_LIST_OPERATION_HIGHER_MAP_H_

#include "fold.h"

namespace tav {

namespace detail {

template <
	template<typename> class Function,
	typename                 List
>
class Map {
	private:
		template <
			typename Current,
			typename Previous
		>
		using function_wrapper = Cons<
			Eval<Function<Current>>,
			Previous
		>;

	public:
		using type = tav::Fold<function_wrapper, void, List>;

};

}

template <
	template<typename> class Function,
	typename                 List
>
using Map = Eval<detail::Map<Function, List>>;

}

#endif  // TYPEASVALUE_SRC_LIST_OPERATION_HIGHER_MAP_H_
