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
			Predicate<Current>::type::value,
			Cons<Current, Previous>,
			Previous
		>;

	public:
		typedef typename Fold<predicate_wrapper, void, List>::type type;

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
		typedef typename Filter<predicate_negator, List>::type type;

};

}

#endif  // TYPEASVALUE_SRC_LIST_OPERATION_HIGHER_FILTER_H_
