#ifndef TYPEASVALUE_SRC_LIST_OPERATION_HIGHER_REMOVE_H_
#define TYPEASVALUE_SRC_LIST_OPERATION_HIGHER_REMOVE_H_

#include "filter.h"

namespace tav {

namespace detail {

template <template<typename> class Predicate>
struct predicate_negator {
	template <typename Element>
	using function = Not<Predicate<Element>>;
};

}

template <
	template<typename> class Predicate,
	typename                 List
>
using Remove = Filter<
	detail::predicate_negator<Predicate>::template function,
	List
>;

}

#endif  // TYPEASVALUE_SRC_LIST_OPERATION_HIGHER_REMOVE_H_
