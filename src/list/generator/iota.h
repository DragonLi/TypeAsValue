#ifndef TYPEASVALUE_SRC_LIST_GENERATOR_IOTA_H_
#define TYPEASVALUE_SRC_LIST_GENERATOR_IOTA_H_

#include "operation/math.h"

namespace tav {

namespace detail {

template <
	typename Count,
	typename Initial,
	typename Step
>
struct Iota {
	typedef Cons<
		Initial,
		Eval<Iota<
			Substract<Count, Size<1>>,
			Add<Initial, Step>,
			Step
		>>
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

template <
	typename Count,
	typename Initial,
	typename Step
>
using Iota = Eval<detail::Iota<Count, Initial, Step>>;

}

#endif  // TYPEASVALUE_SRC_LIST_GENERATOR_IOTA_H_
