#ifndef TYPEASVALUE_SRC_LIST_OPERATION_HIGHER_FILTER_H_
#define TYPEASVALUE_SRC_LIST_OPERATION_HIGHER_FILTER_H_

#include "fold.h"
#include "conditional/if.h"

namespace tav {

template <
	template<typename> class Function,
	typename                 List
>
class Filter {
	private:
		template <
			typename Current,
			typename Previous
		>
		struct function_wrapper {
			typedef If<
				Function<Current>::type::value,
				Cons<Current, Previous>,
				Previous
			> type;
		};

	public:
		typedef typename Fold<function_wrapper, void, List>::type type;

};

}

#endif  // TYPEASVALUE_SRC_LIST_OPERATION_HIGHER_FILTER_H_
