#ifndef TYPEASVALUE_SRC_LIST_OPERATION_APPEND_H_
#define TYPEASVALUE_SRC_LIST_OPERATION_APPEND_H_

namespace tav {

namespace detail {

template <
	typename Primary,
	typename Secondary
>
struct Append {
	typedef Cons<
		Head<Primary>,
		Eval<Append<
			Tail<Primary>,
			Secondary
		>>
	> type;
};

template <typename Secondary>
struct Append<void, Secondary> {
	typedef Secondary type;
};

}

template <
	typename Primary,
	typename Secondary
>
using Append = Eval<detail::Append<Primary, Secondary>>;

}

#endif  // TYPEASVALUE_SRC_LIST_OPERATION_APPEND_H_
