#ifndef TYPEASVALUE_SRC_FUNCTION_APPLY_H_
#define TYPEASVALUE_SRC_FUNCTION_APPLY_H_

#include <type_traits>

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
	typedef typename Nth<Size<Index>, Partials>::type type;
};

}

typedef detail::placeholder<0> _0;
typedef detail::placeholder<1> _1;
typedef detail::placeholder<2> _2;
typedef detail::placeholder<3> _3;

template <
	template<typename...> class Function,
	typename...                 Arguments
>
struct Apply {
	typedef typename tav::List<Arguments...>::type argument_list;

	template <typename... Partials>
	using variadic_type = Function<
		typename detail::resolve_placeholder<
			typename tav::List<Partials...>::type,
			Arguments
		>::type...
	>;

	template <typename Partial>
	using single_type = variadic_type<Partial>;

	template <typename Partial0, typename Partial1>
	using pair_type = variadic_type<Partial0, Partial1>;

	template <typename Partial0, typename Partial1, typename Partial2>
	using triple_type = variadic_type<Partial0, Partial1, Partial2>;
};

}

#endif  // TYPEASVALUE_SRC_FUNCTION_APPLY_H_
