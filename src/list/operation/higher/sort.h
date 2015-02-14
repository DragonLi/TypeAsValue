#ifndef TYPEASVALUE_SRC_LIST_OPERATION_HIGHER_SORT_H_
#define TYPEASVALUE_SRC_LIST_OPERATION_HIGHER_SORT_H_

#include "list/operation/concatenate.h"
#include "list/operation/delete_nth.h"
#include "list/operation/higher/partition.h"
#include "function/apply.h"

namespace tav {

template <
	template<typename, typename> class Comparator,
	typename                           Sequence
>
class Sort {
	private:
		using index = Divide<Eval<Length<Sequence>>, Size<2>>;
		using pivot = Eval<Nth<index, Sequence>>;

		using partitions = Eval<Partition<
			Apply<Comparator, pivot, _0>::template function,
			Eval<DeleteNth<index, Sequence>>
		>>;

		using lhs = Eval<Car<partitions>>;
		using rhs = Eval<Cdr<partitions>>;

	public:
		typedef Eval<Concatenate<
			Eval<List<
				Eval<Sort<Comparator, lhs>>,
				Eval<List<pivot>>,
				Eval<Sort<Comparator, rhs>>
			>>
		>> type;
};

template <template<typename, typename> class Comparator>
struct Sort<Comparator, void> {
	typedef void type;
};

}

#endif  // TYPEASVALUE_SRC_LIST_OPERATION_HIGHER_SORT_H_
