#ifndef TYPEASVALUE_SRC_LIST_DETAIL_FIND_VARIADIC_H_
#define TYPEASVALUE_SRC_LIST_DETAIL_FIND_VARIADIC_H_

#include "type.h"
#include "conditional/if.h"

namespace tav {

namespace detail {

template <
	template<typename> class Predicate,
	typename                 Head,
	typename...              Tail
>
struct find_variadic {
	typedef If<
		Eval<Predicate<Head>>,
		Head,
		Eval<find_variadic<Predicate, Tail...>>
	> type;
};

template <
	template<typename> class Predicate,
	typename                 Last
>
struct find_variadic<Predicate, Last> {
	typedef If<
		Eval<Predicate<Last>>,
		Last,
		void
	> type;
};

}

}

#endif  // TYPEASVALUE_SRC_LIST_DETAIL_FIND_VARIADIC_H_
