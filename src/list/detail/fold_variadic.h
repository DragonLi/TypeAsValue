#ifndef TYPEASVALUE_SRC_LIST_DETAIL_FOLD_VARIADIC_H_
#define TYPEASVALUE_SRC_LIST_DETAIL_FOLD_VARIADIC_H_

#include "type.h"

namespace tav {

namespace detail {

template <
	template <typename, typename> class Function,
	typename                            Head,
	typename...                         Tail
>
struct fold_variadic {
	typedef Function<
		Head,
		Eval<fold_variadic<Function, Tail...>>
	> type;
};

template <
	template <typename, typename> class Function,
	typename                            Head
>
struct fold_variadic<Function, Head> {
	typedef Function<Head, void> type;
};

}

}

#endif  // TYPEASVALUE_SRC_LIST_DETAIL_FOLD_VARIADIC_H_
