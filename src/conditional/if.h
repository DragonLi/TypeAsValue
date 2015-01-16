#ifndef TYPEASVALUE_SRC_CONDITIONAL_IF_H_
#define TYPEASVALUE_SRC_CONDITIONAL_IF_H_

#include <type_traits>

namespace tav {

template <
	bool     Condition,
	typename IfBranch,
	typename ElseBranch
>
using If = typename std::conditional<
	Condition,
	IfBranch,
	ElseBranch
>::type;

}

#endif  // TYPEASVALUE_SRC_CONDITIONAL_IF_H_
