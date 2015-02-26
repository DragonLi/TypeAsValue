#ifndef TYPEASVALUE_SRC_LIST_OPERATION_HIGHER_SORT_H_
#define TYPEASVALUE_SRC_LIST_OPERATION_HIGHER_SORT_H_

#include "list/operation/concatenate.h"
#include "list/operation/delete_nth.h"
#include "list/operation/higher/partition.h"
#include "function/apply.h"

namespace tav {

namespace detail {

template <
	template<typename, typename> class Comparator,
	typename                           Sequence
>
class quick_sort {
	private:
		using index = Divide<Length<Sequence>, Size<2>>;
		using pivot = Nth<index, Sequence>;

		using partitions = Partition<
			Apply<Comparator, pivot, _0>::template function,
			DeleteNth<index, Sequence>
		>;

		using lhs = Car<partitions>;
		using rhs = Cdr<partitions>;

	public:
		using type = Concatenate<
			Eval<quick_sort<Comparator, lhs>>,
			List<pivot>,
			Eval<quick_sort<Comparator, rhs>>
		>;
};

template <template<typename, typename> class Comparator>
struct quick_sort<Comparator, void> {
	typedef void type;
};

}

template <
	template<typename, typename> class Comparator,
	typename                           Sequence
>
using Sort = Eval<detail::quick_sort<Comparator, Sequence>>;

}

#endif  // TYPEASVALUE_SRC_LIST_OPERATION_HIGHER_SORT_H_
