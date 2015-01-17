#ifndef TYPEASVALUE_SRC_LIST_OPERATION_BASIC_H_
#define TYPEASVALUE_SRC_LIST_OPERATION_BASIC_H_

namespace tav {

template <typename Cons>
struct Length {
	typedef Add<
		Size<1>,
		typename Length<Tail<Cons>
	>::type> type;
};

template <>
struct Length<void> {
	typedef Size<0> type;
};

}

#endif  // TYPEASVALUE_SRC_LIST_OPERATION_BASIC_H_
