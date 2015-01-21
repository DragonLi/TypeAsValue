#ifndef TYPEASVALUE_SRC_LIST_OPERATION_CONTAINS_H_
#define TYPEASVALUE_SRC_LIST_OPERATION_CONTAINS_H_

#include "higher/query.h"

namespace tav {

template <
	typename Element,
	typename List
>
class Contains {
	private:
		template <typename Current>
		struct comparator {
			typedef std::is_same<Current, Element> type;
		};

	public:
		typedef typename Any<comparator, List>::type type;

};

}

#endif  // TYPEASVALUE_SRC_LIST_OPERATION_CONTAINS_H_
