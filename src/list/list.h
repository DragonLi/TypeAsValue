#ifndef TYPEASVALUE_SRC_LIST_LIST_H_
#define TYPEASVALUE_SRC_LIST_LIST_H_

#include "type.h"
#include "cons.h"
#include "detail/fold_variadic.h"

namespace tav {

template <typename... Elements>
using List = Eval<detail::fold_variadic<Pair, Elements...>>;

template <
	typename Type,
	Type...  Values
>
using ListOfType = List<
	std::integral_constant<Type, Values>...
>;

template <typename Cons>
using Head = Car<Cons>;

template <typename Cons>
using Tail = Cdr<Cons>;

}

#include "operation/length.h"
#include "operation/nth.h"
#include "operation/take.h"
#include "operation/drop.h"
#include "operation/append.h"
#include "operation/concatenate.h"

#endif  // TYPEASVALUE_SRC_LIST_LIST_H_
