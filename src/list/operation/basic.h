#ifndef TYPEASVALUE_SRC_LIST_OPERATION_BASIC_H_
#define TYPEASVALUE_SRC_LIST_OPERATION_BASIC_H_

#include "operation/math.h"
#include "higher/fold.h"

namespace tav {

template <typename Cons>
class Length {
	private:
		template <
			typename,
			typename Previous
		>
		struct Count {
			typedef Add<Size<1>, Previous> type;
		};

	public:
		typedef typename Fold<Count, Size<0>, Cons>::type type;

};

template <
	typename Index,
	typename Cons
>
struct Nth {
	typedef typename Nth<
		Substract<Index, Size<1>>,
		Tail<Cons>
	>::type type;
};

template <typename Index>
struct Nth<Index, void> {
	typedef void type;
};

template <typename Cons>
struct Nth<Size<0>, Cons> {
	typedef Head<Cons> type;
};

template <
	typename Count,
	typename Current
>
struct Take {
	typedef Cons<
		Head<Current>,
		typename Take<
			Substract<Count, Size<1>>,
			Tail<Current>
		>::type
	> type;
};

template <typename Current>
struct Take<Size<0>, Current> {
	typedef void type;
};

template <typename Count>
struct Take<Count, void> {
	typedef void type;
};

template <>
struct Take<Size<0>, void> {
	typedef void type;
};

}

#endif  // TYPEASVALUE_SRC_LIST_OPERATION_BASIC_H_
