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
		struct function_wrapper {
			typedef Cons<
				typename Function<Current>::type,
				Previous
			> type;
		};

	public:
		typedef typename Fold<function_wrapper, void, List>::type type;

};

}

#endif  // TYPEASVALUE_SRC_LIST_OPERATION_HIGHER_MAP_H_