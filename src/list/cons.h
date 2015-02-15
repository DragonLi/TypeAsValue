#ifndef TYPEASVALUE_SRC_LIST_CONS_H_
#define TYPEASVALUE_SRC_LIST_CONS_H_

#include "pair.h"

namespace tav {

template <
	typename CAR,
	typename CDR
>
using Cons = Pair<CAR, CDR>;

template <typename Pair>
using Car = typename Pair::car;

template <typename Pair>
using Cdr = typename Pair::cdr;

}

#endif  // TYPEASVALUE_SRC_LIST_CONS_H_
