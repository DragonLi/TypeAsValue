#ifndef TYPEASVALUE_SRC_LIST_GENERATOR_IOTA_H_
#define TYPEASVALUE_SRC_LIST_GENERATOR_IOTA_H_

#include "operation/math.h"

namespace tav {

template <
	typename Count,
	typename Initial,
	typename Step
>
struct Iota {
	typedef Cons<
		Initial,
		typename Iota<
			Substract<Count, Size<1>>,
			Add<Initial, Step>,
			Step
		>::type
	> type;
};

template <
	typename Initial,
	typename Step
>
struct Iota<Size<1>, Initial, Step> {
	typedef Cons<Initial, void> type;
};

}

#endif  // TYPEASVALUE_SRC_LIST_GENERATOR_IOTA_H_