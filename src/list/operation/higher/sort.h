#ifndef TYPEASVALUE_SRC_LIST_OPERATION_HIGHER_SORT_H_
#define TYPEASVALUE_SRC_LIST_OPERATION_HIGHER_SORT_H_

#include "list/operation/concatenate.h"
#include "list/operation/higher/partition.h"
#include "function/apply.h"

namespace tav {

template <
	template<typename, typename> class Comparator,
	typename                           Sequence
>
class Sort {
	private:
		using index = Divide<typename Length<Sequence>::type, Size<2>>;
		using pivot = typename Nth<index, Sequence>::type;

		using sequence_sans_pivot = typename Append<
			typename Take<index, Sequence>::type,
			typename Drop<Add<index, Size<1>>, Sequence>::type
		>::type;

		using partitions = typename Partition<
			Apply<Comparator, pivot, tav::_0>::template single_type,
			sequence_sans_pivot
		>::type;

		using lhs = typename Car<partitions>::type;
		using rhs = typename Cdr<partitions>::type;

	public:
		typedef typename Concatenate<
			typename List<
				typename Sort<Comparator, lhs>::type,
				typename List<pivot>::type,
				typename Sort<Comparator, rhs>::type
			>::type
		>::type type;
};

template <template<typename, typename> class Comparator>
struct Sort<Comparator, void> {
	typedef void type;
};

}

#endif  // TYPEASVALUE_SRC_LIST_OPERATION_HIGHER_SORT_H_
