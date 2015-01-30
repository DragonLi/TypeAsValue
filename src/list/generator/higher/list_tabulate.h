#ifndef TYPEASVALUE_SRC_LIST_GENERATOR_HIGHER_LIST_TABULATE_H_
#define TYPEASVALUE_SRC_LIST_GENERATOR_HIGHER_LIST_TABULATE_H_

#include "list/generator/iota.h"
#include "list/operation/higher/map.h"

namespace tav {

template <
	typename                 Count,
	template<typename> class Initializer
>
using ListTabulate = Map<
	Initializer,
	typename Iota<Count, Size<0>, Size<1>>::type
>;

}

#endif  // TYPEASVALUE_SRC_LIST_GENERATOR_HIGHER_LIST_TABULATE_H_
