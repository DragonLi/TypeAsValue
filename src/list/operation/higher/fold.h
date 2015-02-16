#ifndef TYPEASVALUE_SRC_LIST_OPERATION_HIGHER_FOLD_H_
#define TYPEASVALUE_SRC_LIST_OPERATION_HIGHER_FOLD_H_

namespace tav {

namespace detail {

template <
	template<typename, typename> class Function,
	typename                           Initial,
	typename                           Current
>
struct fold_pair {
	typedef Function<
		Head<Current>,
		Eval<fold_pair<Function, Initial, Tail<Current>>>
	> type;
};

template <
	template<typename, typename> class Function,
	typename                           Initial
>
struct fold_pair<Function, Initial, void> {
	typedef Initial type;
};

}

template <
	template<typename, typename> class Function,
	typename                           Initial,
	typename                           Current
>
using Fold = Eval<detail::fold_pair<Function, Initial, Current>>;

}

#endif  // TYPEASVALUE_SRC_LIST_OPERATION_HIGHER_FOLD_H_
