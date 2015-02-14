#ifndef TYPEASVALUE_SRC_LIST_OPERATION_REVERSE_H_
#define TYPEASVALUE_SRC_LIST_OPERATION_REVERSE_H_

#include "append.h"
#include "higher/fold.h"

namespace tav {

template <typename Sequence>
class Reverse {
	private:
		template <
			typename Current,
			typename Previous
		>
		using reversed_append = Append<
			Previous,
			Eval<List<Current>>
		>;

	public:
		typedef Eval<Fold<reversed_append, void, Sequence>> type;

};

}

#endif  // TYPEASVALUE_SRC_LIST_OPERATION_REVERSE_H_
