#ifndef TYPEASVALUE_SRC_LIST_GENERATOR_MAKE_LIST_H_
#define TYPEASVALUE_SRC_LIST_GENERATOR_MAKE_LIST_H_

#include "list/cons.h"
#include "operation/math.h"

namespace tav {

namespace detail {

template <
	typename Count,
	typename Element
>
struct MakeList {
	typedef Cons<
		Element,
		Eval<MakeList<
			Substract<Count, Size<1>>,
			Element
		>>
	> type;
};

template <typename Element>
struct MakeList<Size<1>, Element> {
	typedef Cons<Element, void> type;
};

}

template <
	typename Count,
	typename Element
>
using MakeList = Eval<detail::MakeList<Count, Element>>;

}

#endif  // TYPEASVALUE_SRC_LIST_GENERATOR_MAKE_LIST_H_
