#ifndef TYPEASVALUE_SRC_LIST_OPERATION_DELETE_H_
#define TYPEASVALUE_SRC_LIST_OPERATION_DELETE_H_

#include "type.h"
#include "higher/filter.h"

namespace tav {

template <
	typename Element,
	typename List
>
class Delete {
	private:
		template <typename Current>
		using comparator = EqualValue<Current, Element>;

	public:
		typedef typename Remove<comparator, List>::type type;

};

}

#endif  // TYPEASVALUE_SRC_LIST_OPERATION_DELETE_H_
