#ifndef TYPEASVALUE_SRC_LIST_OPERATION_HIGHER_FOLD_H_
#define TYPEASVALUE_SRC_LIST_OPERATION_HIGHER_FOLD_H_

namespace tav {

template <
	template<typename, typename> class Function,
	typename                           Initial,
	typename                           Current
>
struct Fold {
	typedef typename Function<
		Head<Current>,
		typename Fold<Function, Initial, Tail<Current>>::type
	>::type type;
};

template <
	template<typename, typename> class Function,
	typename                           Initial
>
struct Fold<Function, Initial, void> {
	typedef Initial type;
};

}

#endif  // TYPEASVALUE_SRC_LIST_OPERATION_HIGHER_FOLD_H_
