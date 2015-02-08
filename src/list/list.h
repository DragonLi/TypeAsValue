#ifndef TYPEASVALUE_SRC_LIST_LIST_H_
#define TYPEASVALUE_SRC_LIST_LIST_H_

#include "cons.h"

namespace tav {

template <
	typename    Head,
	typename... Tail
>
struct List {
	typedef typename Cons<
		Head,
		typename List<Tail...>::type
	>::type type;
};

template <typename Head>
struct List<Head> {
	typedef typename Cons<Head, void>::type type;
};

template <typename Head>
struct List<Head, void> {
	typedef typename List<Head>::type type;
};

template <typename... Tail>
struct List<void, Tail...> {
	typedef typename List<Tail...>::type type;
};

template <
	typename Type,
	Type...  Values
>
using ListOfType = List<
	std::integral_constant<Type, Values>...
>;

template <typename Cons>
using Head = typename Car<Cons>::type;

template <typename Cons>
using Tail = typename Cdr<Cons>::type;

}

#include "operation/basic.h"
#include "operation/nth.h"
#include "operation/take.h"
#include "operation/drop.h"
#include "operation/append.h"
#include "operation/concatenate.h"

#endif  // TYPEASVALUE_SRC_LIST_LIST_H_
