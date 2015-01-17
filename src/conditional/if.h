#ifndef TYPEASVALUE_SRC_CONDITIONAL_IF_H_
#define TYPEASVALUE_SRC_CONDITIONAL_IF_H_

#include <type_traits>

namespace tav {

template <
	bool     Condition,
	typename TrueBranch,
	typename FalseBranch
>
using If = typename std::conditional<
	Condition,
	TrueBranch,
	FalseBranch
>::type;

}

#endif  // TYPEASVALUE_SRC_CONDITIONAL_IF_H_
