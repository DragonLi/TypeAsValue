#ifndef TYPEASVALUE_SRC_FUNCTION_DETAIL_PLACEHOLDER_H_
#define TYPEASVALUE_SRC_FUNCTION_DETAIL_PLACEHOLDER_H_

#include <type_traits>

#include "list/list.h"
#include "list/operation/nth.h"
#include "list/operation/higher/query.h"

namespace tav {

namespace detail {

struct placeholder_tag { };

template <std::size_t Index>
struct placeholder : placeholder_tag { };

template <typename Type>
using is_placeholder = Eval<std::is_base_of<placeholder_tag, Type>>;

template <typename... Arguments>
using count_placeholders = Count<is_placeholder, List<Arguments...>>;

template <typename, typename Argument>
struct resolve_placeholder {
	typedef Argument type;
};

template <
	typename    Partials,
	std::size_t Index
>
struct resolve_placeholder<Partials, placeholder<Index>> {
	typedef Nth<Size<Index>, Partials> type;
};

}

}

#endif  // TYPEASVALUE_SRC_FUNCTION_DETAIL_PLACEHOLDER_H_
