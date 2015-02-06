#ifndef TYPEASVALUE_SRC_LIST_OPERATION_REVERSE_H_
#define TYPEASVALUE_SRC_LIST_OPERATION_REVERSE_H_

#include "append.h"
#include "higher/fold.h"

namespace tav {

template <typename List>
class Reverse {
	private:
		template <
			typename Current,
			typename Previous
		>
		struct reversed_append {
			typedef typename Append<
				Previous,
				typename Cons<Current, void>::type
			>::type type;
		};

	public:
		typedef typename Fold<reversed_append, void, List>::type type;

};

}

#endif  // TYPEASVALUE_SRC_LIST_OPERATION_REVERSE_H_
