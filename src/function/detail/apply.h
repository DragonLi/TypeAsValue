#ifndef TYPEASVALUE_SRC_FUNCTION_DETAIL_APPLY_H_
#define TYPEASVALUE_SRC_FUNCTION_DETAIL_APPLY_H_

#include <type_traits>

#include "list/list.h"
#include "list/operation/nth.h"
#include "list/operation/higher/query.h"

namespace tav {
namespace detail {

struct placeholder_tag { };

template <typename Type>
using is_placeholder = tav::Boolean<
	std::is_base_of<placeholder_tag, Type>::value
>;

template <int Index>
struct placeholder : placeholder_tag { };

template <
	typename Partials,
	typename Argument
>
struct resolve_placeholder {
	typedef Argument type;
};

template <
	typename Partials,
	int      Index
>
struct resolve_placeholder<Partials, placeholder<Index>> {
	typedef Eval<Nth<Size<Index>, Partials>> type;
};

template <typename... Arguments>
using count_placeholders = Count<
	is_placeholder,
	Eval<List<Arguments...>>
>;

template <
	template<typename...> class Function,
	typename...                 Arguments
>
struct apply_none {
	using function = Function<Arguments...>;
};

template <
	template<typename...> class Function,
	typename...                 Arguments
>
struct apply_variadic {
	template <typename... Partials>
	using function = Function<
		Eval<resolve_placeholder<
			Eval<List<Partials...>>,
			Arguments
		>>...
	>;
};

template <
	template<typename...> class Function,
	typename...                 Arguments
>
struct apply_single : apply_variadic<Function, Arguments...> {
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
struct apply_pair : apply_variadic<Function, Arguments...> {
	template <typename Partial0, typename Partial1>
	using function = typename apply_variadic<
		Function,
		Arguments...
	>::template function<Partial0, Partial1>;
};

}
}

#endif  // TYPEASVALUE_SRC_FUNCTION_DETAIL_APPLY_H_
