#ifndef TYPEASVALUE_SRC_FUNCTION_APPLY_H_
#define TYPEASVALUE_SRC_FUNCTION_APPLY_H_

#include "operation/math.h"
#include "conditional/cond.h"

#include "detail/apply.h"

namespace tav {

typedef detail::placeholder<0> _0;
typedef detail::placeholder<1> _1;
typedef detail::placeholder<2> _2;
typedef detail::placeholder<3> _3;

template <
	template<typename...> class Function,
	typename...                 Arguments
>
struct Apply : Cond<
	Pair<
		GreaterThan<typename detail::count_placeholders<Arguments...>::type,  Size<2>>,
		detail::apply_variadic<Function, Arguments...>
	>,
	Pair<
		IsEqualValue<typename detail::count_placeholders<Arguments...>::type, Size<2>>,
		detail::apply_pair<Function, Arguments...>
	>,
	Pair<
		IsEqualValue<typename detail::count_placeholders<Arguments...>::type, Size<1>>,
		detail::apply_single<Function, Arguments...>
	>,
	Pair<
		Boolean<true>,
		detail::apply_none<Function, Arguments...>
	>
>::type { };

}

#endif  // TYPEASVALUE_SRC_FUNCTION_APPLY_H_
