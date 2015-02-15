#ifndef TYPEASVALUE_SRC_CONDITIONAL_IF_H_
#define TYPEASVALUE_SRC_CONDITIONAL_IF_H_

#include <type_traits>

namespace tav {

template <
	typename Condition,
	typename TrueBranch,
	typename FalseBranch
>
using If = Eval<std::conditional<
	Condition::value,
	TrueBranch,
	FalseBranch
>>;

}

#endif  // TYPEASVALUE_SRC_CONDITIONAL_IF_H_
