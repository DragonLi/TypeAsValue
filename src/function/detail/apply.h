#ifndef TYPEASVALUE_SRC_FUNCTION_DETAIL_APPLY_H_
#define TYPEASVALUE_SRC_FUNCTION_DETAIL_APPLY_H_

#include "placeholder.h"

namespace tav {

namespace detail {

template <
	template<typename...> class Function,
	typename...                 Arguments
>
struct apply_none {
	using type = Function<Arguments...>;
};

template <
	template<typename...> class Function,
	typename...                 Arguments
>
struct apply_variadic {
	template <typename... Partials>
	using function = Function<
		Eval<resolve_placeholder<
			List<Partials...>,
			Arguments
		>>...
	>;
};

template <
	template<typename...> class Function,
	typename...                 Arguments
>
struct apply_single {
	template <typename Partial0>
	using function = typename apply_variadic<
		Function,
		Arguments...
	>::template function<Partial0>;
};

template <
	template<typename...> class Function,
	typename...                 Arguments
>
struct apply_pair {
	template <typename Partial0, typename Partial1>
	using function = typename apply_variadic<
		Function,
		Arguments...
	>::template function<Partial0, Partial1>;
};

}

}

#endif  // TYPEASVALUE_SRC_FUNCTION_DETAIL_APPLY_H_
