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
		using predicate = IsTrue<Eval<Eval<Car<Pair>>>>;

	public:
		typedef Eval<Cdr<
			Eval<Find<
				predicate,
				Eval<List<Branches...>>
			>>
		>> type;

};

}

#endif  // TYPEASVALUE_SRC_CONDITIONAL_COND_H_
