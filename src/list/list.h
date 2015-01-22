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

template <typename Cons>
using Head = Car<Cons>;

template <typename Cons>
using Tail = Cdr<Cons>;

}

#include "operation/basic.h"
#include "operation/append.h"

#endif  // TYPEASVALUE_SRC_LIST_LIST_H_
