#ifndef TYPEASVALUE_SRC_PAIR_H_
#define TYPEASVALUE_SRC_PAIR_H_

#include <type_traits>

namespace tav {

namespace detail { struct pair_tag { }; }

template <
	typename CAR,
	typename CDR
>
struct Pair : detail::pair_tag {
	typedef CAR car;
	typedef CDR cdr;

	typedef Pair<CAR, CDR> type;
};

template <typename Type>
using IsPair = std::is_base_of<detail::pair_tag, Type>;

}

#endif  // TYPEASVALUE_SRC_PAIR_H_
