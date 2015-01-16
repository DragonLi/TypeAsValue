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

template <
	typename Primary,
	typename Secondary
>
struct Concatenate {
	typedef Cons<
		Head<Primary>,
		typename Concatenate<
			Tail<Primary>,
			Secondary
		>::type
	> type;
};

template <typename Secondary>
struct Concatenate<void, Secondary> {
	typedef Secondary type;
};

}

#endif  // TYPEASVALUE_SRC_LIST_LIST_H_
