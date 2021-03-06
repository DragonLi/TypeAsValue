#ifndef TYPEASVALUE_SRC_LIST_OPERATION_HIGHER_TAKE_WHILE_H_
#define TYPEASVALUE_SRC_LIST_OPERATION_HIGHER_TAKE_WHILE_H_

#include "list_index.h"
#include "list/operation/take.h"
#include "utility/predicate.h"

namespace tav {

template <
	template<typename> class Predicate,
	typename                 List
>
using TakeWhile = Take<
	typename utility::predicate_assurance<
		IsSize,
		Length<List>
	>::template assure<
		ListIndex<
			utility::predicate_negator<Predicate>::template function,
			List
		>
	>,
	List
>;

}

#endif  // TYPEASVALUE_SRC_LIST_OPERATION_HIGHER_TAKE_WHILE_H_
