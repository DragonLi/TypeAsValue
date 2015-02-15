#ifndef TYPEASVALUE_SRC_LIST_OPERATION_HIGHER_FILTER_H_
#define TYPEASVALUE_SRC_LIST_OPERATION_HIGHER_FILTER_H_

#include "fold.h"
#include "conditional/if.h"

namespace tav {

namespace detail {

template <
	template<typename> class Predicate,
	typename                 List
>
class Filter {
	private:
		template <
			typename Current,
			typename Previous
		>
		using predicate_wrapper = If<
			Eval<Predicate<Current>>,
			Cons<Current, Previous>,
			Previous
		>;

	public:
		typedef tav::Fold<predicate_wrapper, void, List> type;

};

}

template <
	template<typename> class Predicate,
	typename                 List
>
using Filter = Eval<detail::Filter<Predicate, List>>;

}

#endif  // TYPEASVALUE_SRC_LIST_OPERATION_HIGHER_FILTER_H_
