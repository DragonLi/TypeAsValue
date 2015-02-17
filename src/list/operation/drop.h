#ifndef TYPEASVALUE_SRC_LIST_OPERATION_DROP_H_
#define TYPEASVALUE_SRC_LIST_OPERATION_DROP_H_

#include "length.h"
#include "section.h"

namespace tav {

template <
	typename Count,
	typename List
>
using Drop = Section<
	Count,
	Substract<Length<List>, Size<1>>,
	List
>;

}

#endif  // TYPEASVALUE_SRC_LIST_OPERATION_DROP_H_
