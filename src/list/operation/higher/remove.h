#ifndef TYPEASVALUE_SRC_LIST_OPERATION_HIGHER_REMOVE_H_
#define TYPEASVALUE_SRC_LIST_OPERATION_HIGHER_REMOVE_H_

#include "filter.h"
#include "utility/predicate.h"

namespace tav {

template <
	template<typename> class Predicate,
	typename                 List
>
using Remove = Filter<
	utility::predicate_negator<Predicate>::template function,
	List
>;

}

#endif  // TYPEASVALUE_SRC_LIST_OPERATION_HIGHER_REMOVE_H_
