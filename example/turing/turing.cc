#include <iostream>

#include "list/generator/make_list.h"
#include "runtime/list/for_each.h"

#include "src/machine.h"

using BLANK = machine::tape::BLANK;

// (define mirror (list (list 1 1 0 2 'R') [...]))
using mirror = tav::List<
	//        [state]       [read]       [write]      [next state]  [head movement]
	tav::List<tav::Size<1>, tav::Int<1>, tav::Int<0>, tav::Size<2>, tav::Char<'R'>>,
	tav::List<tav::Size<1>, tav::Int<0>, tav::Int<0>, void,         tav::Char<'N'> >,
	tav::List<tav::Size<2>, tav::Int<1>, tav::Int<1>, tav::Size<2>, tav::Char<'R'>>,
	tav::List<tav::Size<2>, tav::Int<0>, tav::Int<0>, tav::Size<3>, tav::Char<'R'>>,
	tav::List<tav::Size<3>, tav::Int<1>, tav::Int<1>, tav::Size<3>, tav::Char<'R'>>,
	tav::List<tav::Size<3>, tav::Int<0>, tav::Int<1>, tav::Size<4>, tav::Char<'L'> >,
	tav::List<tav::Size<4>, tav::Int<1>, tav::Int<1>, tav::Size<4>, tav::Char<'L'> >,
	tav::List<tav::Size<4>, tav::Int<0>, tav::Int<0>, tav::Size<5>, tav::Char<'L'> >,
	tav::List<tav::Size<5>, tav::Int<1>, tav::Int<1>, tav::Size<5>, tav::Char<'L'> >,
	tav::List<tav::Size<5>, tav::Int<0>, tav::Int<1>, tav::Size<1>, tav::Char<'R'>>
>;

// (define busy_beaver (list (list 'A' 0 1 'B' 'R') [...]))
using busy_beaver = tav::List<
	//        [state]         [read]       [write]      [next state]    [head movement]
	tav::List<tav::Char<'A'>, tav::Int<0>, tav::Int<1>, tav::Char<'B'>, tav::Char<'R'>>,
	tav::List<tav::Char<'A'>, tav::Int<1>, tav::Int<1>, tav::Char<'C'>, tav::Char<'L'> >,
	tav::List<tav::Char<'B'>, tav::Int<0>, tav::Int<1>, tav::Char<'A'>, tav::Char<'L'> >,
	tav::List<tav::Char<'B'>, tav::Int<1>, tav::Int<1>, tav::Char<'B'>, tav::Char<'R'>>,
	tav::List<tav::Char<'C'>, tav::Int<0>, tav::Int<1>, tav::Char<'B'>, tav::Char<'L'> >,
	tav::List<tav::Char<'C'>, tav::Int<1>, tav::Int<1>, void,           tav::Char<'N'> >
>;

// (define binary_increment (list (list 0 '() '() 1 'L') [...]))
using binary_increment = tav::List<
	//        [state]       [read]               [write]              [next state]  [head movement]
	tav::List<tav::Size<0>, BLANK,               BLANK,               tav::Size<1>, tav::Char<'L'>>,
	tav::List<tav::Size<0>, tav::Boolean<false>, tav::Boolean<false>, tav::Size<0>, tav::Char<'R'>>,
	tav::List<tav::Size<0>, tav::Boolean<true>,  tav::Boolean<true>,  tav::Size<0>, tav::Char<'R'>>,
	tav::List<tav::Size<1>, BLANK,               tav::Boolean<true>,  tav::Size<2>, tav::Char<'R'>>,
	tav::List<tav::Size<1>, tav::Boolean<false>, tav::Boolean<true>,  tav::Size<2>, tav::Char<'L'>>,
	tav::List<tav::Size<1>, tav::Boolean<true>,  tav::Boolean<false>, tav::Size<1>, tav::Char<'L'>>,
	tav::List<tav::Size<2>, BLANK,               BLANK,               void,         tav::Char<'L'>>,
	tav::List<tav::Size<2>, tav::Boolean<false>, tav::Boolean<false>, tav::Size<2>, tav::Char<'R'>>,
	tav::List<tav::Size<2>, tav::Boolean<true>,  tav::Boolean<true>,  tav::Size<2>, tav::Char<'R'>>
>;

const auto printField = [](const auto x) {
	std::cout << x;
};

template <typename States>
void printStates() {
	using position = tav::Car<tav::Head<States>>;
	using tape     = tav::Cdr<tav::Head<States>>;
	using prefix   = tav::MakeList<tav::Size<3>, tav::Char<' '>>;

	tav::runtime::for_each<tav::Concatenate<prefix, tape>>(printField);

	std::cout << std::endl;

	tav::runtime::for_each<tav::Concatenate<
		prefix,
		tav::MakeList<position, tav::Char<' '>>,
		tav::List<tav::Char<'^'>>
	>>(printField);

	std::cout << std::endl;

	printStates<tav::Tail<States>>();
}

template <>
void printStates<void>() { }

int main(int, char **) {
	// (define mirror_tape (list 1 1 1 0 0 0 0))
	using mirror_tape = tav::ListOfType<int, 1, 1, 1, 0, 0, 0, 0>;

	std::cout << "1. Mirror"
	          << std::endl;

	printStates<
		machine::run<
			mirror,
			tav::Size<1>,
			mirror_tape,
			tav::Size<0>
		>
	>();

	// (define busy_beaver_tape (make-list 13 0))
	using busy_beaver_tape = tav::MakeList<tav::Size<13>, tav::Int<0>>;

	std::cout << "2. Busy Beaver"
	          << std::endl;

	printStates<
		machine::run<
			busy_beaver,
			tav::Char<'A'>,
			busy_beaver_tape,
			tav::Size<6>
		>
	>();

	// (define binary_increment_tape (list #t #f #t #f #t #f))
	using binary_increment_tape = tav::ListOfType<bool, 1, 0, 1, 0, 1, 0>;

	std::cout << "3. Binary Increment"
	          << std::endl;

	printStates<
		machine::run<
			binary_increment,
			tav::Size<0>,
			binary_increment_tape,
			tav::Size<0>
		>
	>();
}
