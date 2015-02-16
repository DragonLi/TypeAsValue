#ifndef TYPEASVALUE_SRC_LIST_GENERATOR_MAKE_LIST_H_
#define TYPEASVALUE_SRC_LIST_GENERATOR_MAKE_LIST_H_

#include "pair.h"
#include "detail/generate_nested_structure.h"

namespace tav {

template <
	typename Count,
	typename Element
>
using MakeList = Eval<detail::generate_nested_structure<
	Pair,
	Eval,
	Element,
	Count
>>;

}

#endif  // TYPEASVALUE_SRC_LIST_GENERATOR_MAKE_LIST_H_
