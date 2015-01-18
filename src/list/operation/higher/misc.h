#ifndef TYPEASVALUE_SRC_LIST_OPERATION_HIGHER_MISC_H_
#define TYPEASVALUE_SRC_LIST_OPERATION_HIGHER_MISC_H_

#include "fold.h"
#include "list/operation/concatenate.h"

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
		struct FunctionWrapper {
			typedef Cons<Function<Current>, Previous> type;
		};

	public:
		typedef typename Fold<FunctionWrapper, void, List>::type type;

};

template <typename List>
class Reverse {
	private:
		template <
			typename Current,
			typename Previous
		>
		struct ReversedConcatenate {
			typedef typename Concatenate<
				Previous,
				Cons<Current, void>
			>::type type;
		};

	public:
		typedef typename Fold<ReversedConcatenate, void, List>::type type;

};

}

#endif  // TYPEASVALUE_SRC_LIST_OPERATION_HIGHER_MISC_H_
