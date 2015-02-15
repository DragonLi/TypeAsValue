#ifndef TYPEASVALUE_SRC_CONDITIONAL_COND_H_
#define TYPEASVALUE_SRC_CONDITIONAL_COND_H_

#include <type_traits>

#include "list/list.h"
#include "list/operation/higher/find.h"

namespace tav {

namespace detail {

template <typename... Branches>
class Cond {
	private:
		template <typename Pair>
		using predicate = IsTrue<tav::Car<Pair>>;

	public:
		typedef tav::Cdr<
			tav::Find<
				predicate,
				tav::List<Branches...>
			>
		> type;

};

}

template <typename... Branches>
using Cond = Eval<detail::Cond<Branches...>>;

}

#endif  // TYPEASVALUE_SRC_CONDITIONAL_COND_H_
