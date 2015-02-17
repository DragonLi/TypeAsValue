#ifndef TYPEASVALUE_SRC_LIST_OPERATION_TAKE_H_
#define TYPEASVALUE_SRC_LIST_OPERATION_TAKE_H_

#include "section.h"

namespace tav {

template <
	typename Count,
	typename List
>
using Take = Section<
	Size<0>,
	Substract<Count, Size<1>>,
	List
>;

}

#endif  // TYPEASVALUE_SRC_LIST_OPERATION_TAKE_H_
