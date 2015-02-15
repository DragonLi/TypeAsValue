#ifndef TYPEASVALUE_SRC_LIST_OPERATION_BASIC_H_
#define TYPEASVALUE_SRC_LIST_OPERATION_BASIC_H_

#include "higher/fold.h"
#include "operation/math.h"

namespace tav {

namespace detail {

template <typename List>
class Length {
	private:
		template <typename, typename Accumulated>
		using accumulate = Add<Size<1>, Accumulated>;

	public:
		typedef tav::Fold<accumulate, Size<0>, List> type;

};

}

template <typename List>
using Length = Eval<detail::Length<List>>;

}

#endif  // TYPEASVALUE_SRC_LIST_OPERATION_BASIC_H_
