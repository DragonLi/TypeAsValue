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

}

#endif  // TYPEASVALUE_SRC_LIST_LIST_H_
