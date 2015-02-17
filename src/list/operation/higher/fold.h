#ifndef TYPEASVALUE_SRC_LIST_OPERATION_HIGHER_FOLD_H_
#define TYPEASVALUE_SRC_LIST_OPERATION_HIGHER_FOLD_H_

namespace tav {

namespace detail {

template <
	template<typename, typename> class Function,
	typename                           Initial,
	typename                           Pair
>
struct fold_pair {
	typedef Function<
		Car<Pair>,
		Eval<fold_pair<Function, Initial, Cdr<Pair>>>
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
	typename                           List
>
using Fold = Eval<detail::fold_pair<Function, Initial, List>>;

}

#endif  // TYPEASVALUE_SRC_LIST_OPERATION_HIGHER_FOLD_H_
