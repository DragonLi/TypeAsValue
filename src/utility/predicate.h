#ifndef TYPEASVALUE_SRC_UTILITY_PREDICATE_H_
#define TYPEASVALUE_SRC_UTILITY_PREDICATE_H_

#include "conditional/if.h"
#include "operation/logic.h"

namespace tav {

namespace utility {

template <
	template<typename> class Predicate,
	typename                 Surrogate
>
struct predicate_assurance {
	template <typename Value>
	using assure = If<
		Eval<Predicate<Value>>,
		Value,
		Surrogate
	>;
};

template <template<typename> class Predicate>
struct predicate_negator {
	template <typename Element>
	using function = Not<Predicate<Element>>;
};

}

}

#endif  // TYPEASVALUE_SRC_UTILITY_PREDICATE_H_
