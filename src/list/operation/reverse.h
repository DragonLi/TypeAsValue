#ifndef TYPEASVALUE_SRC_LIST_OPERATION_REVERSE_H_
#define TYPEASVALUE_SRC_LIST_OPERATION_REVERSE_H_

#include "concatenate.h"
#include "higher/fold.h"

namespace tav {

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

#endif  // TYPEASVALUE_SRC_LIST_OPERATION_REVERSE_H_
