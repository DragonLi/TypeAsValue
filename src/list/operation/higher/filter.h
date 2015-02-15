#ifndef TYPEASVALUE_SRC_LIST_OPERATION_HIGHER_FILTER_H_
#define TYPEASVALUE_SRC_LIST_OPERATION_HIGHER_FILTER_H_

#include "fold.h"
#include "conditional/if.h"

namespace tav {

namespace detail {

template <template<typename> class Predicate>
struct filter_predicate {
	template <
		typename Current,
		typename Previous
	>
	using function = If<
		Eval<Predicate<Current>>,
		Cons<Current, Previous>,
		Previous
	>;
};

}

template <
	template<typename> class Predicate,
	typename                 List
>
using Filter = Fold<
	detail::filter_predicate<Predicate>::template function,
	void,
	List
>;

}

#endif  // TYPEASVALUE_SRC_LIST_OPERATION_HIGHER_FILTER_H_
