#ifndef TYPEASVALUE_SRC_LIST_CONS_H_
#define TYPEASVALUE_SRC_LIST_CONS_H_

namespace tav {

template <
	typename CAR,
	typename CDR
>
struct Cons {
	typedef CAR car;
	typedef CDR cdr;
};

template <typename Cons>
using Car = typename Cons::car;

template <typename Cons>
using Cdr = typename Cons::cdr;

}

#endif  // TYPEASVALUE_SRC_LIST_CONS_H_
