#ifndef TYPEASVALUE_SRC_LIST_OPERATION_HIGHER_REMOVE_H_
#define TYPEASVALUE_SRC_LIST_OPERATION_HIGHER_REMOVE_H_

#include "filter.h"

namespace tav {

namespace detail {

template <
	template<typename> class Predicate,
	typename                 List
>
class Remove {
	private:
		template <typename Element>
		using predicate_negator = Not<Predicate<Element>>;

	public:
		typedef tav::Filter<predicate_negator, List> type;

};

}

template <
	template<typename> class Predicate,
	typename                 List
>
using Remove = Eval<detail::Remove<Predicate, List>>;

}

#endif  // TYPEASVALUE_SRC_LIST_OPERATION_HIGHER_REMOVE_H_
