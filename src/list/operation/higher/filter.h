#ifndef TYPEASVALUE_SRC_LIST_OPERATION_HIGHER_FILTER_H_
#define TYPEASVALUE_SRC_LIST_OPERATION_HIGHER_FILTER_H_

#include "fold.h"
#include "conditional/if.h"

namespace tav {

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
			Eval<Cons<Current, Previous>>,
			Previous
		>;

	public:
		typedef Eval<Fold<predicate_wrapper, void, List>> type;

};

template <
	template<typename> class Predicate,
	typename                 List
>
class Remove {
	private:
		template <typename Element>
		using predicate_negator = Not<Predicate<Element>>;

	public:
		typedef Eval<Filter<predicate_negator, List>> type;

};

}

#endif  // TYPEASVALUE_SRC_LIST_OPERATION_HIGHER_FILTER_H_
