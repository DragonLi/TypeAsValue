#ifndef TYPEASVALUE_SRC_LIST_CONS_H_
#define TYPEASVALUE_SRC_LIST_CONS_H_

#include "pair.h"

namespace tav {

namespace detail {

template <typename Pair>
struct Car {
	static_assert(
		IsPair<Pair>::value,
		"Pair type required"
	);

	typedef typename Pair::car type;
};

template <typename Pair>
struct Cdr {
	static_assert(
		IsPair<Pair>::value,
		"Pair type required"
	);

	typedef typename Pair::cdr type;
};

}

template <
	typename CAR,
	typename CDR
>
using Cons = Pair<CAR, CDR>;

template <typename Pair>
using Car = Eval<detail::Car<Pair>>;

template <typename Pair>
using Cdr = Eval<detail::Cdr<Pair>>;

}

#endif  // TYPEASVALUE_SRC_LIST_CONS_H_
