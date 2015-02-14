#ifndef TYPEASVALUE_SRC_LIST_OPERATION_APPEND_H_
#define TYPEASVALUE_SRC_LIST_OPERATION_APPEND_H_

namespace tav {

template <
	typename Primary,
	typename Secondary
>
struct Append {
	typedef Eval<Cons<
		Head<Primary>,
		Eval<Append<
			Tail<Primary>,
			Secondary
		>>
	>> type;
};

template <typename Secondary>
struct Append<void, Secondary> {
	typedef Secondary type;
};

}

#endif  // TYPEASVALUE_SRC_LIST_OPERATION_APPEND_H_
