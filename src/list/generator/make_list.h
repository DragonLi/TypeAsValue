#ifndef TYPEASVALUE_SRC_LIST_GENERATOR_MAKE_LIST_H_
#define TYPEASVALUE_SRC_LIST_GENERATOR_MAKE_LIST_H_

#include "list/cons.h"
#include "operation/math.h"

namespace tav {

template <
	typename Count,
	typename Element
>
struct MakeList {
	typedef Eval<Cons<
		Element,
		Eval<MakeList<
			Substract<Count, Size<1>>,
			Element
		>>
	>> type;
};

template <typename Element>
struct MakeList<Size<1>, Element> {
	typedef Eval<Cons<Element, void>> type;
};

}

#endif  // TYPEASVALUE_SRC_LIST_GENERATOR_MAKE_LIST_H_
