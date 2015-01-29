#ifndef TYPEASVALUE_SRC_LIST_LIST_H_
#define TYPEASVALUE_SRC_LIST_LIST_H_

#include "cons.h"

namespace tav {

template <
	typename    Head,
	typename... Tail
>
struct List {
	typedef Cons<
		Head,
		typename List<Tail...>::type
	> type;
};

template <typename Head>
struct List<Head> {
	typedef Cons<Head, void> type;
};

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
#include "operation/append.h"
#include "operation/concatenate.h"

#endif  // TYPEASVALUE_SRC_LIST_LIST_H_
