#ifndef TYPEASVALUE_SRC_LIST_LIST_H_
#define TYPEASVALUE_SRC_LIST_LIST_H_

#include "cons.h"

namespace tav {

namespace detail {

template <
	typename    Head,
	typename... Tail
>
struct List {
	typedef Eval<Cons<
		Head,
		Eval<List<Tail...>>
	>> type;
};

template <typename Head>
struct List<Head> {
	typedef Eval<Cons<Head, void>> type;
};

template <typename Head>
struct List<Head, void> {
	typedef Eval<List<Head>> type;
};

template <typename... Tail>
struct List<void, Tail...> {
	typedef Eval<List<Tail...>> type;
};

template <>
struct List<void, void> {
	typedef void type;
};

}

template <typename... Elements>
using List = Eval<detail::List<Elements...>>;

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

#include "operation/basic.h"
#include "operation/nth.h"
#include "operation/take.h"
#include "operation/drop.h"
#include "operation/append.h"
#include "operation/concatenate.h"

#endif  // TYPEASVALUE_SRC_LIST_LIST_H_
