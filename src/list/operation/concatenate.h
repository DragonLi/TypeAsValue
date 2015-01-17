#ifndef TYPEASVALUE_SRC_LIST_OPERATION_CONCATENATE_H_
#define TYPEASVALUE_SRC_LIST_OPERATION_CONCATENATE_H_

namespace tav {

template <
	typename Primary,
	typename Secondary
>
struct Concatenate {
	typedef Cons<
		Head<Primary>,
		typename Concatenate<
			Tail<Primary>,
			Secondary
		>::type
	> type;
};

template <typename Secondary>
struct Concatenate<void, Secondary> {
	typedef Secondary type;
};

}

#endif  // TYPEASVALUE_SRC_LIST_OPERATION_CONCATENATE_H_
