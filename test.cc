#include "type.h"
#include "operation/math.h"
#include "operation/logic.h"
#include "conditional/if.h"

#include "list/cons.h"
#include "list/list.h"
#include "list/operation/reverse.h"
#include "list/operation/contains.h"
#include "list/operation/higher/map.h"
#include "list/operation/higher/filter.h"
#include "list/operation/higher/remove.h"
#include "list/operation/higher/partition.h"
#include "list/operation/higher/query.h"
#include "list/operation/higher/find.h"
#include "list/operation/higher/take_while.h"
#include "list/operation/higher/drop_while.h"
#include "list/operation/higher/sort.h"
#include "list/generator/iota.h"
#include "list/generator/make_list.h"
#include "list/generator/higher/list_tabulate.h"
#include "list/operation/delete.h"
#include "list/operation/delete_nth.h"

#include "function/apply.h"

int main(int, char **) { }

// equality

static_assert(
	std::is_same<
		tav::Boolean<true>,
		tav::IsEqualType<tav::Int<1>, tav::Int<2>>
	>::value,
	"(IsEqualType 1 2) != #t"
);

static_assert(
	std::is_same<
		tav::Boolean<false>,
		tav::IsEqualType<tav::Int<1>, tav::Size<1>>
	>::value,
	"(IsEqualType (int 1) (size 2)) != #f"
);

static_assert(
	std::is_same<
		tav::Boolean<true>,
		tav::IsEqualValue<tav::Int<1>, tav::Size<1>>
	>::value,
	"(equal? (int 1) (size 1)) != #t"
);

static_assert(
	std::is_same<
		tav::Boolean<false>,
		tav::IsEqualValue<tav::Int<1>, tav::Int<2>>
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

static_assert(
	std::is_same<
		tav::Int<1>,
		tav::Modulo<tav::Int<10>, tav::Int<3>>
	>::value,
	"(modulo 10 3) != 1"
);

static_assert(
	std::is_same<
		tav::Int<4096>,
		tav::Square<tav::Int<64>>
	>::value,
	"(square 64) != 4096"
);

static_assert(
	std::is_same<
		tav::Boolean<true>,
		tav::Odd<tav::Int<1>>
	>::value,
	"(odd? 1) != #t"
);

static_assert(
	std::is_same<
		tav::Boolean<false>,
		tav::Odd<tav::Int<2>>
	>::value,
	"(odd? 2) != #f"
);

static_assert(
	std::is_same<
		tav::Boolean<true>,
		tav::GreaterThan<tav::Int<2>, tav::Int<1>>
	>::value,
	"(> 2 1) != #f"
);

static_assert(
	std::is_same<
		tav::Boolean<false>,
		tav::GreaterThan<tav::Int<1>, tav::Int<2>>
	>::value,
	"(> 1 2) != #f"
);

static_assert(
	std::is_same<
		tav::Boolean<true>,
		tav::LowerThan<tav::Int<1>, tav::Int<2>>
	>::value,
	"(< 1 2) != #t"
);

static_assert(
	std::is_same<
		tav::Boolean<false>,
		tav::LowerThan<tav::Int<2>, tav::Int<1>>
	>::value,
	"(< 2 1) != #f"
);

// logic

static_assert(
	std::is_same<
		tav::Boolean<true>,
		tav::And<tav::Boolean<true>, tav::Boolean<true>>
	>::value,
	"(and #t #t) != #t"
);

static_assert(
	std::is_same<
		tav::Boolean<false>,
		tav::And<tav::Boolean<false>, tav::Boolean<true>>
	>::value,
	"(and #f #t) != #f"
);

static_assert(
	std::is_same<
		tav::Boolean<true>,
		tav::Or<tav::Boolean<true>, tav::Boolean<true>>
	>::value,
	"(or #t #t) != #t"
);

static_assert(
	std::is_same<
		tav::Boolean<true>,
		tav::Or<tav::Boolean<false>, tav::Boolean<true>>
	>::value,
	"(or #f #t) != #t"
);

static_assert(
	std::is_same<
		tav::Boolean<false>,
		tav::Or<tav::Boolean<false>, tav::Boolean<false>>
	>::value,
	"(or #f #f) != #f"
);

static_assert(
	std::is_same<
		tav::Boolean<true>,
		tav::Xor<tav::Boolean<false>, tav::Boolean<true>>
	>::value,
	"(xor #f #t) != #t"
);

static_assert(
	std::is_same<
		tav::Boolean<false>,
		tav::Xor<tav::Boolean<true>, tav::Boolean<true>>
	>::value,
	"(xor #t #t) != #f"
);

// conditionals

static_assert(
	std::is_same<
		tav::Int<1>,
		tav::If<tav::Boolean<true>, tav::Int<1>, tav::Int<2>>
	>::value,
	"(if #t 1 2) != 1"
);

static_assert(
	std::is_same<
		tav::Int<2>,
		tav::If<tav::Boolean<false>, tav::Int<1>, tav::Int<2>>
	>::value,
	"(if #f 1 2) != 2"
);

static_assert(
	std::is_same<
		tav::Int<2>,
		tav::Cond<
			tav::Pair<tav::IsEqualValue<tav::Int<1>, tav::Int<2>>, tav::Int<1>>,
			tav::Pair<tav::IsEqualValue<tav::Int<2>, tav::Int<2>>, tav::Int<2>>,
			tav::Pair<tav::IsEqualValue<tav::Int<3>, tav::Int<2>>, tav::Int<3>>
		>
	>::value,
	"(cond ((= 1 2) 1) ((= 2 2) 2) ((= 3 2) 3)) != 2"
);

static_assert(
	std::is_same<
		tav::Int<-1>,
		tav::Cond<
			tav::Pair<tav::IsEqualValue<tav::Int<1>, tav::Int<2>>, tav::Int< 1>>,
			tav::Pair<tav::IsEqualValue<tav::Int<2>, tav::Int<3>>, tav::Int< 2>>,
			tav::Pair<tav::IsEqualValue<tav::Int<3>, tav::Int<4>>, tav::Int< 3>>,
			tav::Pair<tav::Boolean<true>,                          tav::Int<-1>>
		>
	>::value,
	"(cond ((= 1 2) 1) ((= 2 3) 2) ((= 3 4) 3) (else -1)) != -1"
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
		tav::Pair<tav::Int<1>, void>,
		tav::List<tav::Int<1>>
	>::value,
	"(list 1) != '(1)"
);

static_assert(
	std::is_same<
		tav::Pair<tav::Int<1>, tav::Pair<tav::Int<2>, void>>,
		tav::List<tav::Int<1>, tav::Int<2>>
	>::value,
	"(list 1 2) != '(1 . 2)"
);

static_assert(
	std::is_same<
		tav::Int<1>,
		tav::Head<
			tav::List<tav::Int<1>, tav::Int<2>, tav::Int<3>>
		>
	>::value,
	"(head (list 1 2 3) != 1"
);

static_assert(
	std::is_same<
		tav::Pair<tav::Int<2>, tav::Pair<tav::Int<3>, void>>,
		tav::Tail<
			tav::List<tav::Int<1>, tav::Int<2>, tav::Int<3>>
		>
	>::value,
	"(tail (list 1 2 3) != '(2 . 3)"
);

// list of type

static_assert(
	std::is_same<
		tav::Pair<tav::Int<1>, void>,
		tav::ListOfType<int, 1>
	>::value,
	"(list 1) != (cons 1 void)"
);

static_assert(
	std::is_same<
		tav::Pair<tav::Int<1>, tav::Pair<tav::Int<2>, void>>,
		tav::ListOfType<int, 1, 2>
	>::value,
	"(list 1 2) != (cons 1 (cons 2 void))"
);

// list section

static_assert(
	std::is_same<
		tav::List<tav::Int<2>>,
		tav::Section<
			tav::Size<1>,
			tav::Size<1>,
			tav::List<tav::Int<1>, tav::Int<2>, tav::Int<3>>
		>
	>::value,
	"(section 1 1 (list 1 2 3)) != (list 1)"
);

static_assert(
	std::is_same<
		tav::List<tav::Int<2>, tav::Int<3>>,
		tav::Section<
			tav::Size<1>,
			tav::Size<2>,
			tav::List<tav::Int<1>, tav::Int<2>, tav::Int<3>>
		>
	>::value,
	"(section 1 2 (list 1 2 3)) != (list 1 2)"
);

static_assert(
	std::is_same<
		tav::List<tav::Int<1>, tav::Int<2>, tav::Int<3>>,
		tav::Section<
			tav::Size<0>,
			tav::Size<2>,
			tav::List<tav::Int<1>, tav::Int<2>, tav::Int<3>>
		>
	>::value,
	"(section 0 2 (list 1 2 3)) != (list 1 2 3)"
);

// list take

static_assert(
	std::is_same<
		tav::List<tav::Int<1>>,
		tav::Take<
			tav::Size<1>,
			tav::List<tav::Int<1>, tav::Int<2>>
		>
	>::value,
	"(take 1 (list 1 2)) != (list 1)"
);

static_assert(
	std::is_same<
		tav::List<tav::Int<1>, tav::Int<2>>,
		tav::Take<
			tav::Size<2>,
			tav::List<tav::Int<1>, tav::Int<2>>
		>
	>::value,
	"(take 2 (list 1 2)) != (list 1 2)"
);

static_assert(
	std::is_same<
		tav::List<tav::Int<1>, tav::Int<2>>,
		tav::Take<
			tav::Size<3>,
			tav::List<tav::Int<1>, tav::Int<2>>
		>
	>::value,
	"(take 3 (list 1 2)) != (list 1 2)"
);

// list drop

static_assert(
	std::is_same<
		tav::List<tav::Int<2>>,
		tav::Drop<
			tav::Size<1>,
			tav::List<tav::Int<1>, tav::Int<2>>
		>
	>::value,
	"(drop 1 (list 1 2)) != (list 2)"
);

static_assert(
	std::is_same<
		void,
		tav::Drop<
			tav::Size<2>,
			tav::List<tav::Int<1>, tav::Int<2>>
		>
	>::value,
	"(drop 2 (list 1 2)) != void"
);

static_assert(
	std::is_same<
		void,
		tav::Drop<
			tav::Size<3>,
			tav::List<tav::Int<1>, tav::Int<2>>
		>
	>::value,
	"(drop 3 (list 1 2)) != void"
);

// list length

static_assert(
	std::is_same<
		tav::Size<1>,
		tav::Length<
			tav::List<tav::Int<1>>
		>
	>::value,
	"(length (list 1)) != 1"
);

static_assert(
	std::is_same<
		tav::Size<2>,
		tav::Length<
			tav::List<tav::Int<1>, tav::Int<2>>
		>
	>::value,
	"(length (list 1 2)) != 2"
);

// list nth

static_assert(
	std::is_same<
		tav::Int<1>,
		tav::Nth<
			tav::Size<0>,
			tav::List<tav::Int<1>>
		>
	>::value,
	"(nth 0 (list 1)) != 1"
);

static_assert(
	std::is_same<
		tav::Int<1>,
		tav::Nth<
			tav::Size<0>,
			tav::List<tav::Int<1>, tav::Int<2>>
		>
	>::value,
	"(nth 0 (list 1 2)) != 1"
);

static_assert(
	std::is_same<
		tav::Int<2>,
		tav::Nth<
			tav::Size<1>,
			tav::List<tav::Int<1>, tav::Int<2>>
		>
	>::value,
	"(nth 1 (list 1 2)) != 2"
);

static_assert(
	std::is_same<
		tav::Int<1>,
		tav::First<tav::List<tav::Int<1>, tav::Int<2>, tav::Int<3>>>
	>::value,
	"(first (list 1 2 3)) != 1"
);

static_assert(
	std::is_same<
		tav::Int<2>,
		tav::Second<tav::List<tav::Int<1>, tav::Int<2>, tav::Int<3>>>
	>::value,
	"(second (list 1 2 3)) != 2"
);

static_assert(
	std::is_same<
		tav::Int<3>,
		tav::Third<tav::List<tav::Int<1>, tav::Int<2>, tav::Int<3>>>
	>::value,
	"(third (list 1 2 3)) != 3"
);

// list append

static_assert(
	std::is_same<
		tav::List<tav::Int<1>, tav::Int<2>>,
		tav::Append<
			tav::List<tav::Int<1>>,
			tav::List<tav::Int<2>>
		>
	>::value,
	"(append (list 1) (list 2)) != (list 1 2)"
);

static_assert(
	std::is_same<
		tav::List<tav::Int<1>, tav::Int<2>, tav::Int<3>, tav::Int<4>>,
		tav::Append<
			tav::List<tav::Int<1>, tav::Int<2>>,
			tav::List<tav::Int<3>, tav::Int<4>>
		>
	>::value,
	"(append (list 1 2) (list 3 4)) != (list 1 2 3 4)"
);

// list fold

static_assert(
	std::is_same<
		tav::Int<6>,
		tav::Fold<
			tav::Add,
			tav::Int<0>,
			tav::List<tav::Int<1>, tav::Int<2>, tav::Int<3>>
		>
	>::value,
	"(fold + 0 (list 1 2 3)) != 6"
);

// list map

template <typename Element>
using quadruple = tav::Multiply<tav::Int<4>, Element>;

static_assert(
	std::is_same<
		tav::List<tav::Int<4>, tav::Int<8>, tav::Int<12>>,
		tav::Map<
			quadruple,
			tav::List<tav::Int<1>, tav::Int<2>, tav::Int<3>>
		>
	>::value,
	"(map quadruple (list 1 2 3)) != (list 4 8 12)"
);

// list filter

static_assert(
	std::is_same<
		tav::List<tav::Int<1>, tav::Int<3>>,
		tav::Filter<
			tav::Odd,
			tav::List<tav::Int<1>, tav::Int<2>, tav::Int<3>>
		>
	>::value,
	"(filter odd? (list 1 2 3)) != (list 1 3)"
);

// list remove

static_assert(
	std::is_same<
		tav::List<tav::Int<1>, tav::Int<3>>,
		tav::Remove<
			tav::Even,
			tav::List<tav::Int<1>, tav::Int<2>, tav::Int<3>>
		>
	>::value,
	"(remove even? (list 1 2 3)) != (list 1 3)"
);

// list delete

static_assert(
	std::is_same<
		tav::List<tav::Int<1>, tav::Int<3>>,
		tav::Delete<
			tav::Int<2>,
			tav::List<tav::Int<1>, tav::Int<2>, tav::Int<3>>
		>
	>::value,
	"(delete 2 (list 1 2 3)) != (list 1 3)"
);

static_assert(
	std::is_same<
		tav::List<tav::Int<1>, tav::Int<2>, tav::Int<3>>,
		tav::Delete<
			tav::Int<4>,
			tav::List<tav::Int<1>, tav::Int<2>, tav::Int<3>>
		>
	>::value,
	"(delete 4 (list 1 2 3)) != (list 1 2 3)"
);

// list delete nth

static_assert(
	std::is_same<
		tav::List<tav::Int<1>, tav::Int<3>>,
		tav::DeleteNth<
			tav::Size<1>,
			tav::List<tav::Int<1>, tav::Int<2>, tav::Int<3>>
		>
	>::value,
	"(delete-nth 1 (list 1 2 3)) != (list 1 3)"
);

// list partition

static_assert(
	std::is_same<
		tav::Pair<
			tav::List<tav::Int<1>, tav::Int<3>>,
			tav::List<tav::Int<2>>
		>,
		tav::Partition<
			tav::Odd,
			tav::List<tav::Int<1>, tav::Int<2>, tav::Int<3>>
		>
	>::value,
	"(partition odd? (list 1 2 3)) != [(list 1 3) (list 2)]"
);

// list reverse

static_assert(
	std::is_same<
		tav::List<tav::Int<3>, tav::Int<2>, tav::Int<1>>,
		tav::Reverse<
			tav::List<tav::Int<1>, tav::Int<2>, tav::Int<3>>
		>
	>::value,
	"(reverse (list 1 2 3)) != (list 3 2 1)"
);

// list query

static_assert(
	std::is_same<
		tav::Boolean<true>,
		tav::Any<
			tav::Odd,
			tav::List<tav::Int<1>, tav::Int<2>, tav::Int<3>>
		>
	>::value,
	"(any odd? (list 1 2 3)) != #t"
);

static_assert(
	std::is_same<
		tav::Boolean<false>,
		tav::Any<
			tav::Odd,
			tav::List<tav::Int<2>, tav::Int<4>, tav::Int<6>>
		>
	>::value,
	"(any odd? (list 2 4 6)) != #f"
);

static_assert(
	std::is_same<
		tav::Boolean<true>,
		tav::All<
			tav::Even,
			tav::List<tav::Int<2>, tav::Int<4>, tav::Int<6>>
		>
	>::value,
	"(all even? (list 2 4 6)) != #t"
);

static_assert(
	std::is_same<
		tav::Boolean<false>,
		tav::All<
			tav::Odd,
			tav::List<tav::Int<1>, tav::Int<2>, tav::Int<3>>
		>
	>::value,
	"(all odd? (list 1 2 3)) != #f"
);

static_assert(
	std::is_same<
		tav::Boolean<true>,
		tav::None<
			tav::Even,
			tav::List<tav::Int<1>, tav::Int<3>, tav::Int<5>>
		>
	>::value,
	"(none even? (list 1 3 5)) != #t"
);

static_assert(
	std::is_same<
		tav::Boolean<false>,
		tav::None<
			tav::Even,
			tav::List<tav::Int<2>, tav::Int<3>, tav::Int<5>>
		>
	>::value,
	"(none even? (list 2 3 5)) != #f"
);

// list contains

static_assert(
	std::is_same<
		tav::Boolean<true>,
		tav::Contains<
			tav::Int<2>,
			tav::List<tav::Int<1>, tav::Int<2>, tav::Int<3>>
		>
	>::value,
	"(contains 2 (list 1 2 3)) != #t"
);

static_assert(
	std::is_same<
		tav::Boolean<false>,
		tav::Contains<
			tav::Int<0>,
			tav::List<tav::Int<1>, tav::Int<2>, tav::Int<3>>
		>
	>::value,
	"(contains 0 (list 1 2 3)) != #f"
);

// list concatenate

static_assert(
	std::is_same<
		tav::List<tav::Int<1>, tav::Int<2>, tav::Int<3>, tav::Int<4>, tav::Int<5>, tav::Int<6>>,
		tav::Concatenate<
			tav::List<
				tav::List<tav::Int<1>, tav::Int<2>>,
				tav::List<tav::Int<3>>,
				tav::List<tav::Int<4>, tav::Int<5>, tav::Int<6>>
			>
		>
	>::value,
	"(concatenate (list (list 1 2) (list 3) (list 4 5 6))) != (list 1 2 3 4 5 6)"
);

// list iota

static_assert(
	std::is_same<
		tav::List<tav::Int<1>>,
		tav::Iota<
			tav::Size<1>,
			tav::Int<1>,
			tav::Int<1>
		>
	>::value,
	"(iota 1 1 1) != (list 1)"
);

static_assert(
	std::is_same<
		tav::List<tav::Int<1>, tav::Int<2>, tav::Int<3>>,
		tav::Iota<
			tav::Size<3>,
			tav::Int<1>,
			tav::Int<1>
		>
	>::value,
	"(iota 3 1 1) != (list 1 2 3)"
);

static_assert(
	std::is_same<
		tav::List<tav::Int<0>, tav::Int<2>, tav::Int<4>, tav::Int<6>, tav::Int<8>>,
		tav::Iota<
			tav::Size<5>,
			tav::Int<0>,
			tav::Int<2>
		>
	>::value,
	"(iota 5 0 2) != (list 0 2 4 6 8)"
);

static_assert(
	std::is_same<
		tav::List<tav::Int<5>, tav::Int<4>, tav::Int<3>, tav::Int<2>, tav::Int<1>>,
		tav::Iota<
			tav::Size<5>,
			tav::Int<5>,
			tav::Int<-1>
		>
	>::value,
	"(iota 5 5 -1) != (list 5 4 3 2 1)"
);

// make list

static_assert(
	std::is_same<
		tav::List<tav::Int<42>>,
		tav::MakeList<tav::Size<1>, tav::Int<42>>
	>::value,
	"(make-list 1 42) != (list 42)"
);

static_assert(
	std::is_same<
		tav::List<tav::Int<42>, tav::Int<42>, tav::Int<42>>,
		tav::MakeList<tav::Size<3>, tav::Int<42>>
	>::value,
	"(make-list 3 42) != (list 42 42 42)"
);

// list tabulate

static_assert(
	std::is_same<
		tav::List<tav::Size<0>, tav::Size<1>, tav::Size<4>, tav::Size<9>>,
		tav::ListTabulate<
			tav::Size<4>,
			tav::Square
		>
	>::value,
	"(list-tabulate 4 square) != (list 0 1 4 9)"
);

// list count

static_assert(
	std::is_same<
		tav::Size<2>,
		tav::Count<
			tav::Odd,
			tav::List<tav::Int<1>, tav::Int<2>, tav::Int<3>>
		>
	>::value,
	"(count odd? (list 1 2 3)) != 2"
);

static_assert(
	std::is_same<
		tav::Size<0>,
		tav::Count<
			tav::Even,
			tav::List<tav::Int<1>, tav::Int<3>, tav::Int<5>>
		>
	>::value,
	"(count even? (list 1 3 5)) != 0"
);

// list find

static_assert(
	std::is_same<
		tav::Int<4>,
		tav::Find<
			tav::Even,
			tav::List<tav::Int<1>, tav::Int<3>, tav::Int<4>, tav::Int<6>>
		>
	>::value,
	"(find even? (list 1 3 4 6)) != 4"
);

static_assert(
	std::is_same<
		tav::Int<6>,
		tav::Find<
			tav::Even,
			tav::List<tav::Int<1>, tav::Int<3>, tav::Int<5>, tav::Int<6>>
		>
	>::value,
	"(find even? (list 1 3 5 6)) != 6"
);

static_assert(
	std::is_same<
		tav::Boolean<false>,
		tav::Find<
			tav::Even,
			tav::List<tav::Int<1>, tav::Int<3>, tav::Int<5>>
		>
	>::value,
	"(find even? (list 1 3 5)) != #f"
);

// list take while

static_assert(
	std::is_same<
		tav::List<tav::Int<2>, tav::Int<4>>,
		tav::TakeWhile<
			tav::Even,
			tav::List<tav::Int<2>, tav::Int<4>, tav::Int<5>, tav::Int<6>>
		>
	>::value,
	"(take-while even? (list 2 4 5 6)) != (list 2 4)"
);

static_assert(
	std::is_same<
		tav::List<tav::Int<2>, tav::Int<4>, tav::Int<6>>,
		tav::TakeWhile<
			tav::Even,
			tav::List<tav::Int<2>, tav::Int<4>, tav::Int<6>>
		>
	>::value,
	"(take-while even? (list 2 4 6)) != (list 2 4 6)"
);

static_assert(
	std::is_same<
		void,
		tav::TakeWhile<
			tav::Odd,
			tav::List<tav::Int<2>, tav::Int<4>, tav::Int<5>, tav::Int<6>>
		>
	>::value,
	"(take-while odd? (list 2 4 5 6)) != void"
);

// list drop while

static_assert(
	std::is_same<
		tav::List<tav::Int<5>, tav::Int<6>>,
		tav::DropWhile<
			tav::Even,
			tav::List<tav::Int<2>, tav::Int<4>, tav::Int<5>, tav::Int<6>>
		>
	>::value,
	"(drop-while even? (list 2 4 5 6)) != (list 5 6)"
);

static_assert(
	std::is_same<
		tav::List<tav::Int<2>, tav::Int<4>, tav::Int<6>>,
		tav::DropWhile<
			tav::Odd,
			tav::List<tav::Int<2>, tav::Int<4>, tav::Int<6>>
		>
	>::value,
	"(drop-while odd? (list 2 4 6)) != (list 2 4 6)"
);

static_assert(
	std::is_same<
		void,
		tav::DropWhile<
			tav::Even,
			tav::List<tav::Int<2>, tav::Int<4>, tav::Int<6>>
		>
	>::value,
	"(drop-while even? (list 2 4 6)) != void"
);

// list sort

static_assert(
	std::is_same<
		tav::List<tav::Int<1>, tav::Int<2>, tav::Int<3>>,
		tav::Sort<
			tav::GreaterThan,
			tav::List<tav::Int<3>, tav::Int<2>, tav::Int<1>>
		>
	>::value,
	"(sort > (list 3 2 1)) != (list 1 2 3)"
);

static_assert(
	std::is_same<
		tav::List<tav::Int<3>, tav::Int<2>, tav::Int<1>>,
		tav::Sort<
			tav::LowerThan,
			tav::List<tav::Int<1>, tav::Int<3>, tav::Int<2>>
		>
	>::value,
	"(sort < (list 1 3 2)) != (list 3 2 1)"
);

static_assert(
	std::is_same<
		tav::Iota<tav::Size<42>, tav::Int<1>, tav::Int<1>>,
		tav::Sort<
			tav::GreaterThan,
			tav::Iota<tav::Size<42>, tav::Int<42>, tav::Int<-1>>
		>
	>::value,
	"(sort > (iota 42 42 -1)) != (iota 42 1 1)"
);

// function apply

static_assert(
	std::is_same<
		tav::Int<42>,
		tav::Apply<
			tav::Multiply,
			tav::Int<21>,
			tav::_0
		>::function<
			tav::Int<2>
		>::type
	>::value,
	"((lambda (x) (* 21 x)) 2) != 42"
);

static_assert(
	std::is_same<
		tav::List<tav::Int<10>, tav::Int<12>, tav::Int<14>>,
		tav::Map<
			tav::Apply<
				tav::Add,
				tav::_0,
				tav::Int<10>
			>::function,
			tav::List<tav::Int<0>, tav::Int<2>, tav::Int<4>>
		>
	>::value,
	"(map (lambda (x) (+ x 10)) (list 0 2 4)) != (list 10 12 14)"
);

static_assert(
	std::is_same<
		tav::Int<42>,
		tav::Apply<
			tav::Multiply,
			tav::Int<21>,
			tav::Int<2>
		>::function::type
	>::value,
	"(* 21 2) != 42"
);
