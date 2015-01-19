#include "type.h"
#include "operation/math.h"
#include "conditional/if.h"

#include "list/cons.h"
#include "list/list.h"
#include "list/operation/higher/fold.h"
#include "list/operation/higher/misc.h"

int main(int, char **) { }

// equality

static_assert(
	std::is_same<
		tav::Boolean<true>,
		tav::EqualType<tav::Int<1>, tav::Int<2>>
	>::value,
	"(EqualType 1 2) != #t"
);

static_assert(
	std::is_same<
		tav::Boolean<false>,
		tav::EqualType<tav::Int<1>, tav::Size<1>>
	>::value,
	"(EqualType (int 1) (size 2)) != #f"
);

static_assert(
	std::is_same<
		tav::Boolean<true>,
		tav::EqualValue<tav::Int<1>, tav::Size<1>>
	>::value,
	"(equal? (int 1) (size 1)) != #t"
);

static_assert(
	std::is_same<
		tav::Boolean<false>,
		tav::EqualValue<tav::Int<1>, tav::Int<2>>
	>::value,
	"(equal? 1 2) != #f"
);

// basic math operations

static_assert(
	std::is_same<
		tav::Int<3>,
		tav::Add<tav::Int<1>, tav::Int<2>>
	>::value,
	"(+ 1 2) != 3"
);

static_assert(
	std::is_same<
		tav::Int<4>,
		tav::Substract<tav::Int<10>, tav::Int<6>>
	>::value,
	"(- 10 6) != 4"
);

static_assert(
	std::is_same<
		tav::Int<42>,
		tav::Multiply<tav::Int<2>, tav::Int<21>>
	>::value,
	"(* 2 21) != 42"
);

static_assert(
	std::is_same<
		tav::Int<5>,
		tav::Divide<tav::Int<10>, tav::Int<2>>
	>::value,
	"(/ 10 2) != 42"
);

// conditionals

static_assert(
	std::is_same<
		tav::Int<1>,
		tav::If<true, tav::Int<1>, tav::Int<2>>::type
	>::value,
	"(if #t 1 2) != 1"
);

static_assert(
	std::is_same<
		tav::Int<2>,
		tav::If<false, tav::Int<1>, tav::Int<2>>::type
	>::value,
	"(if #f 1 2) != 2"
);

// cons

static_assert(
	std::is_same<
		tav::Int<1>,
		tav::Car<
			tav::Cons<tav::Int<1>, void>
		>
	>::value,
	"(car (cons 1 void)) != 1"
);

static_assert(
	std::is_same<
		tav::Int<1>,
		tav::Car<
			tav::Cons<tav::Int<1>, tav::Int<2>>
		>
	>::value,
	"(car (cons 1 2)) != 1"
);

static_assert(
	std::is_same<
		tav::Int<2>,
		tav::Cdr<
			tav::Cons<tav::Int<1>, tav::Int<2>>
		>
	>::value,
	"(cdr (cons 1 2)) != 2"
);

static_assert(
	std::is_same<
		tav::Int<2>,
		tav::Car<
			tav::Cdr<
				tav::Cons<tav::Int<1>, tav::Cons<tav::Int<2>, tav::Int<3>>>
			>
		>
	>::value,
	"(car (cdr (cons 1 (cons 2 3)))) != 2"
);

// list

static_assert(
	std::is_same<
		tav::Cons<tav::Int<1>, void>,
		tav::List<tav::Int<1>>::type
	>::value,
	"(list 1) != (cons 1 void)"
);

static_assert(
	std::is_same<
		tav::Cons<tav::Int<1>, tav::Cons<tav::Int<2>, void>>,
		tav::List<tav::Int<1>, tav::Int<2>>::type
	>::value,
	"(list 1 2) != (cons 1 (cons 2 void))"
);

// list length

static_assert(
	std::is_same<
		tav::Size<1>,
		tav::Length<
			tav::List<tav::Int<1>>::type
		>::type
	>::value,
	"(length (list 1)) != 1"
);

static_assert(
	std::is_same<
		tav::Size<2>,
		tav::Length<
			tav::List<tav::Int<1>, tav::Int<2>>::type
		>::type
	>::value,
	"(length (list 1 2)) != 2"
);

// list nth

static_assert(
	std::is_same<
		tav::Int<1>,
		tav::Nth<
			tav::Size<0>,
			tav::List<tav::Int<1>>::type
		>::type
	>::value,
	"(nth 0 (list 1)) != 1"
);

static_assert(
	std::is_same<
		tav::Int<1>,
		tav::Nth<
			tav::Size<0>,
			tav::List<tav::Int<1>, tav::Int<2>>::type
		>::type
	>::value,
	"(nth 0 (list 1 2)) != 1"
);

static_assert(
	std::is_same<
		tav::Int<2>,
		tav::Nth<
			tav::Size<1>,
			tav::List<tav::Int<1>, tav::Int<2>>::type
		>::type
	>::value,
	"(nth 1 (list 1 2)) != 2"
);

// list take

static_assert(
	std::is_same<
		tav::Size<1>,
		tav::Length<
			tav::Take<
				tav::Size<1>,
				tav::List<tav::Int<1>, tav::Int<2>>::type
			>::type
		>::type
	>::value,
	"(length (take 1 (list 1 2))) != 1"
);

static_assert(
	std::is_same<
		tav::Size<2>,
		tav::Length<
			tav::Take<
				tav::Size<2>,
				tav::List<tav::Int<1>, tav::Int<2>>::type
			>::type
		>::type
	>::value,
	"(length (take 2 (list 1 2))) != 2"
);

static_assert(
	std::is_same<
		tav::Size<2>,
		tav::Length<
			tav::Take<
				tav::Size<3>,
				tav::List<tav::Int<1>, tav::Int<2>>::type
			>::type
		>::type
	>::value,
	"(length (take 3 (list 1 2))) != 2"
);

// list concatenate

static_assert(
	std::is_same<
		tav::Size<2>,
		tav::Length<
			tav::Concatenate<
				tav::List<tav::Int<1>>::type,
				tav::List<tav::Int<2>>::type
			>::type
		>::type
	>::value,
	"(length (concatenate (list 1) (list 2))) != 2"
);

static_assert(
	std::is_same<
		tav::Size<4>,
		tav::Length<
			tav::Concatenate<
				tav::List<tav::Int<1>, tav::Int<2>>::type,
				tav::List<tav::Int<3>, tav::Int<4>>::type
			>::type
		>::type
	>::value,
	"(length (concatenate (list 1 2) (list 3 4))) != 4"
);

// list fold

static_assert(
	std::is_same<
		tav::Int<6>,
		tav::Fold<
			tav::Add,
			tav::Int<0>,
			tav::List<tav::Int<1>, tav::Int<2>, tav::Int<3>>::type
		>::type
	>::value,
	"(fold + 0 (list 1 2 3)) != 6"
);

// list map

template <typename Element>
using quadruple = tav::Multiply<tav::Int<4>, Element>;

static_assert(
	std::is_same<
		tav::List<tav::Int<4>, tav::Int<8>, tav::Int<12>>::type,
		tav::Map<
			quadruple,
			tav::List<tav::Int<1>, tav::Int<2>, tav::Int<3>>::type
		>::type
	>::value,
	"(map quadruple (list 1 2 3)) != (list 4 8 12)"
);

// list filter

static_assert(
	std::is_same<
		tav::List<tav::Int<1>, tav::Int<3>>::type,
		tav::Filter<
			tav::Odd,
			tav::List<tav::Int<1>, tav::Int<2>, tav::Int<3>>::type
		>::type
	>::value,
	"(filter odd (list 1 2 3)) != (list 1 3)"
);

// list reverse

static_assert(
	std::is_same<
		tav::List<tav::Int<3>, tav::Int<2>, tav::Int<1>>::type,
		tav::Reverse<
			tav::List<tav::Int<1>, tav::Int<2>, tav::Int<3>>::type
		>::type
	>::value,
	"(reverse (list 1 2 3)) != (list 3 2 1)"
);
