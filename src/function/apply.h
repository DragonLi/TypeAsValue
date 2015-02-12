#ifndef TYPEASVALUE_SRC_FUNCTION_APPLY_H_
#define TYPEASVALUE_SRC_FUNCTION_APPLY_H_

#include "conditional/if.h"

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
struct Apply : If<
	(detail::count_placeholders<Arguments...>::type::value > 2),
	detail::apply_variadic<Function, Arguments...>,
	typename If<
		detail::count_placeholders<Arguments...>::type::value == 2,
		detail::apply_pair<Function, Arguments...>,
		detail::apply_single<Function, Arguments...>
	>::type
>::type { };

}

#endif  // TYPEASVALUE_SRC_FUNCTION_APPLY_H_
