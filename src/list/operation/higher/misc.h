#ifndef TYPEASVALUE_SRC_LIST_OPERATION_HIGHER_MISC_H_
#define TYPEASVALUE_SRC_LIST_OPERATION_HIGHER_MISC_H_

#include "fold.h"
#include "list/operation/concatenate.h"
#include "conditional/if.h"

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
			typedef Cons<Function<Current>, Previous> type;
		};

	public:
		typedef typename Fold<function_wrapper, void, List>::type type;

};

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

template <typename List>
class Reverse {
	private:
		template <
			typename Current,
			typename Previous
		>
		struct reversed_concatenate {
			typedef typename Concatenate<
				Previous,
				Cons<Current, void>
			>::type type;
		};

	public:
		typedef typename Fold<reversed_concatenate, void, List>::type type;

};

}

#endif  // TYPEASVALUE_SRC_LIST_OPERATION_HIGHER_MISC_H_
