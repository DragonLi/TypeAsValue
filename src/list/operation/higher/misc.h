#ifndef TYPEASVALUE_SRC_LIST_OPERATION_HIGHER_MISC_H_
#define TYPEASVALUE_SRC_LIST_OPERATION_HIGHER_MISC_H_

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
		struct FunctionWrapper {
			typedef Cons<Function<Current>, Previous> type;
		};

	public:
		typedef typename Fold<FunctionWrapper, void, List>::type type;

};

}

#endif  // TYPEASVALUE_SRC_LIST_OPERATION_HIGHER_MISC_H_
