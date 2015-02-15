#ifndef TYPEASVALUE_SRC_LIST_OPERATION_REVERSE_H_
#define TYPEASVALUE_SRC_LIST_OPERATION_REVERSE_H_

#include "append.h"
#include "higher/fold.h"

namespace tav {

namespace detail {

template <typename Sequence>
class Reverse {
	private:
		template <
			typename Current,
			typename Previous
		>
		using reversed_append = tav::Append<
			Previous,
			tav::List<Current>
		>;

	public:
		typedef tav::Fold<reversed_append, void, Sequence> type;

};

}

template <typename Sequence>
using Reverse = Eval<detail::Reverse<Sequence>>;

}

#endif  // TYPEASVALUE_SRC_LIST_OPERATION_REVERSE_H_
