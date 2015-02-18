#ifndef TYPEASVALUE_SRC_LIST_OPERATION_APPEND_H_
#define TYPEASVALUE_SRC_LIST_OPERATION_APPEND_H_

#include "higher/fold.h"

namespace tav {

namespace detail {

template <typename Replacement>
struct replace_void_cdr {
	template <typename CAR, typename CDR>
	using function = Cons<
		CAR,
		If<
			Eval<std::is_void<CDR>>,
			Replacement,
			CDR
		>
	>;
};

}

template <
	typename Primary,
	typename Secondary
>
using Append = If<
	Eval<std::is_void<Primary>>,
	Secondary,
	Fold<
		detail::replace_void_cdr<Secondary>::template function,
		void,
		Primary
	>
>;

}

#endif  // TYPEASVALUE_SRC_LIST_OPERATION_APPEND_H_
