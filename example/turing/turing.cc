#include <iostream>

#include "list/generator/make_list.h"
#include "runtime/list/for_each.h"

#include "src/machine.h"

// (define mirror (list (list 1 1 0 2 'R') [...]))
using mirror = tav::List<
//            [state]       [read]       [write]      [next state]  [head movement]
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

// (define mirror_initial_tape (list 1 1 1 0 0 0 0))
using mirror_initial_tape = tav::ListOfType<int, 1, 1, 1, 0, 0, 0, 0>;

// (define mirror_final_tape
//   (run mirror
//        1
//        mirror_initial_tape
//        0))
using mirror_final_tape = machine::run<
	mirror,
	tav::Size<1>,
	mirror_initial_tape,
	tav::Size<0>
>;

// (define busy_beaver (list (list 'A' 0 1 'B' 'R') [...]))
using busy_beaver = tav::List<
//            [state]         [read]       [write]      [next state]    [head movement]
	tav::List<tav::Char<'A'>, tav::Int<0>, tav::Int<1>, tav::Char<'B'>, tav::Char<'R'>>,
	tav::List<tav::Char<'A'>, tav::Int<1>, tav::Int<1>, tav::Char<'C'>, tav::Char<'L'> >,
	tav::List<tav::Char<'B'>, tav::Int<0>, tav::Int<1>, tav::Char<'A'>, tav::Char<'L'> >,
	tav::List<tav::Char<'B'>, tav::Int<1>, tav::Int<1>, tav::Char<'B'>, tav::Char<'R'>>,
	tav::List<tav::Char<'C'>, tav::Int<0>, tav::Int<1>, tav::Char<'B'>, tav::Char<'L'> >,
	tav::List<tav::Char<'C'>, tav::Int<1>, tav::Int<1>, void,           tav::Char<'N'> >
>;

// (define busy_beaver_initial_tape (make-list 13 0))
using busy_beaver_initial_tape = tav::MakeList<tav::Size<13>, tav::Int<0>>;

// (define busy_beaver_final_tape
//   (run busy_beaver
//        'A'
//        busy_beaver_initial_tape
//        6))
using busy_beaver_final_tape = machine::run<
	busy_beaver,
	tav::Char<'A'>,
	busy_beaver_initial_tape,
	tav::Size<6>
>;

int main(int, char **) {
	const auto printField = [](const int x) {
		std::cout << x << " ";
	};

	std::cout << "1. Mirror"
	          << std::endl
	          << "   Initial: ";

	tav::runtime::for_each<mirror_initial_tape>(printField);

	std::cout << std::endl
	          << "   Final:   ";

	tav::runtime::for_each<mirror_final_tape>(printField);

	std::cout << std::endl
	          << std::endl
	          << "2. Busy Beaver"
	          << std::endl
	          << "   Initial: ";

	tav::runtime::for_each<busy_beaver_initial_tape>(printField);

	std::cout << std::endl
	          << "   Final:   ";

	tav::runtime::for_each<busy_beaver_final_tape>(printField);

	std::cout << std::endl;
}
