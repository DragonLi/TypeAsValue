#ifndef TYPEASVALUE_SRC_LIST_OPERATION_HIGHER_MAP_H_
#define TYPEASVALUE_SRC_LIST_OPERATION_HIGHER_MAP_H_

#include "fold.h"

namespace tav {

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
		typedef Eval<Fold<function_wrapper, void, List>> type;

};

}

#endif  // TYPEASVALUE_SRC_LIST_OPERATION_HIGHER_MAP_H_
