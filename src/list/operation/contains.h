#ifndef TYPEASVALUE_SRC_LIST_OPERATION_CONTAINS_H_
#define TYPEASVALUE_SRC_LIST_OPERATION_CONTAINS_H_

#include "type.h"
#include "higher/query.h"

namespace tav {

template <
	typename Element,
	typename List
>
class Contains {
	private:
		template <typename Current>
		using comparator = EqualValue<Current, Element>;

	public:
		typedef typename Any<comparator, List>::type type;

};

}

#endif  // TYPEASVALUE_SRC_LIST_OPERATION_CONTAINS_H_
