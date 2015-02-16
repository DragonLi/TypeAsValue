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
class Sort {
	private:
		using index = Divide<tav::Length<Sequence>, Size<2>>;
		using pivot = tav::Nth<index, Sequence>;

		using partitions = Partition<
			Apply<Comparator, pivot, _0>::template function,
			DeleteNth<index, Sequence>
		>;

		using lhs = tav::Car<partitions>;
		using rhs = tav::Cdr<partitions>;

	public:
		using type = Concatenate<
			List<
				Eval<Sort<Comparator, lhs>>,
				List<pivot>,
				Eval<Sort<Comparator, rhs>>
			>
		>;
};

template <template<typename, typename> class Comparator>
struct Sort<Comparator, void> {
	typedef void type;
};

}

template <
	template<typename, typename> class Comparator,
	typename                           Sequence
>
using Sort = Eval<detail::Sort<Comparator, Sequence>>;

}

#endif  // TYPEASVALUE_SRC_LIST_OPERATION_HIGHER_SORT_H_
