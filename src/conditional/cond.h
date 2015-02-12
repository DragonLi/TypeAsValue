#ifndef TYPEASVALUE_SRC_CONDITIONAL_COND_H_
#define TYPEASVALUE_SRC_CONDITIONAL_COND_H_

#include <type_traits>

#include "list/list.h"
#include "list/operation/higher/find.h"

namespace tav {

template <typename... Branches>
class Cond {
	private:
		template <typename Pair>
		using predicate = IsTrue<typename Car<Pair>::type::type>;

	public:
		typedef typename Cdr<
			typename Find<
				predicate,
				typename List<Branches...>::type
			>::type
		>::type type;

};

}

#endif  // TYPEASVALUE_SRC_CONDITIONAL_COND_H_
