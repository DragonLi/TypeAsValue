#ifndef TYPEASVALUE_SRC_LIST_GENERATOR_IOTA_H_
#define TYPEASVALUE_SRC_LIST_GENERATOR_IOTA_H_

#include "pair.h"
#include "operation/math.h"
#include "function/apply.h"
#include "detail/generate_nested_structure.h"

namespace tav {

template <
	typename Count,
	typename Initial,
	typename Step
>
using Iota = Eval<detail::generate_nested_structure<
	Pair,
	Apply<Add, Step, _0>::template function,
	Initial,
	Count
>>;

}

#endif  // TYPEASVALUE_SRC_LIST_GENERATOR_IOTA_H_
