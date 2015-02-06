#ifndef TYPEASVALUE_SRC_LIST_CONS_H_
#define TYPEASVALUE_SRC_LIST_CONS_H_

#include "pair.h"

namespace tav {

template <
	typename CAR,
	typename CDR
>
struct Cons {
	typedef Pair<CAR, CDR> type;
};

template <typename Pair>
struct Car {
	static_assert(
		IsPair<Pair>::type::value,
		"Pair type required"
	);

	typedef typename Pair::car type;
};

template <typename Pair>
struct Cdr {
	static_assert(
		IsPair<Pair>::type::value,
		"Pair type required"
	);

	typedef typename Pair::cdr type;
};

}

#endif  // TYPEASVALUE_SRC_LIST_CONS_H_
