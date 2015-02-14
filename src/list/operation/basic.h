#ifndef TYPEASVALUE_SRC_LIST_OPERATION_BASIC_H_
#define TYPEASVALUE_SRC_LIST_OPERATION_BASIC_H_

#include "higher/fold.h"
#include "operation/math.h"

namespace tav {

template <typename Cons>
class Length {
	private:
		template <typename, typename Accumulated>
		using accumulate = Add<Size<1>, Accumulated>;

	public:
		typedef Eval<Fold<
			accumulate,
			Size<0>,
			Cons
		>> type;

};

}

#endif  // TYPEASVALUE_SRC_LIST_OPERATION_BASIC_H_
