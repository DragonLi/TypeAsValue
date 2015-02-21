#include <iostream>

#include "type.h"
#include "operation/math.h"
#include "function/apply.h"

#include "conditional/if.h"
#include "conditional/cond.h"

#include "list/operation/replace_nth.h"
#include "list/operation/higher/find.h"
#include "list/generator/make_list.h"

#include "runtime/list/for_each.h"

struct symbol {
	struct BLANK { };
};

struct movement {
	struct RIGHT { };
	struct LEFT  { };
	struct NONE  { };
};

// helper for easier state access
struct state_field {
	using ID    = tav::Size<0>;
	using READ  = tav::Size<1>;
	using WRITE = tav::Size<2>;
	using NEXT  = tav::Size<3>;
	using MOVE  = tav::Size<4>;
};

// (define (state_predicate id read)
//   (lambda (state)
//           (and (= id   (nth ID   state))
//                (= read (nth READ state)))))
template <
	typename Id,
	typename Read
>
struct state_predicate {
	template <typename State>
	using function = tav::And<
		tav::IsEqualValue<Id,   tav::Nth<state_field::ID,   State>>,
		tav::IsEqualValue<Read, tav::Nth<state_field::READ, State>>
	>;
};

// (define (findState id read states)
//   (find (state_predicate id read) states))
template <
	typename Id,
	typename Read,
	typename States
>
using findState = tav::Find<
	state_predicate<Id, Read>::template function,
	States
>;

// (define (readSymbolFromTape position tape)
//   (if (= (length tape) position)
//       BLANK
//       (nth position tape)))
template <
	typename Position,
	typename Tape
>
using readSymbolFromTape = tav::If<
	tav::IsEqualValue<tav::Length<Tape>, Position>,
	symbol::BLANK,
	tav::Nth<Position, Tape>
>;

// (define (writeSymbolToTape position symbol tape)
//   (if (= (length tape) position)
//       (append tape (list symbol))
//       (replace-nth position symbol tape)))
template <
	typename Position,
	typename Symbol,
	typename Tape
>
using writeSymbolToTape = tav::If<
	tav::IsEqualValue<tav::Length<Tape>, Position>,
	tav::Append<Tape, tav::List<Symbol>>,
	tav::ReplaceNth<Position, Symbol, Tape>
>;

// (define (transition states)
//   (lambda (state symbol)
//           (findState state symbol states)))
template <typename States>
struct transition {
	template <
		typename State,
		typename Symbol
	>
	using state = findState<State, Symbol, States>;
};

// (define (simulateTuringMachine transition tape state position)
//   (if (= state FINAL)
//     tape
//     (let* ((current_symbol (readSymbolFromTape position tape))
//            (current_state  (transition state current_symbol))
//            (direction      (nth MOVE  current_state))
//            (next_symbol    (nth WRITE current_state))
//            (next_state     (nth NEXT  current_state))
//            (next_position  (cond ((= direction RIGHT) (+ position 1))
//                                  ((= direction LEFT)  (- Position 1))
//                                  (else                position))))
//       (simulateTuringMachine transition
//                              (writeSymbolToTape position next_symbol tape)
//                              next_state,
//                              next_position)))
template <
	template<typename, typename> class Transition,
	typename                           Tape,
	typename                           State,
	typename                           Position
>
class simulateTuringMachine {
	private:
		using current_symbol = readSymbolFromTape<Position, Tape>;
		using current_state  = Transition<State, current_symbol>;

		using direction      = tav::Nth<state_field::MOVE,  current_state>;

		using next_symbol    = tav::Nth<state_field::WRITE, current_state>;
		using next_state     = tav::Nth<state_field::NEXT,  current_state>;
		using next_position  = tav::Cond<
			tav::Branch<
				std::is_same<direction, movement::RIGHT>,
				tav::Add<Position, tav::Size<1>>
			>,
			tav::Branch<
				std::is_same<direction, movement::LEFT>,
				tav::Substract<Position, tav::Size<1>>
			>,
			tav::Else<
				Position
			>
		>;

		static_assert(
			tav::Not<tav::LowerThan<next_position, tav::Size<0>>>::value,
			"next position out of bounds"
		);

	public:
		using type = tav::Eval<simulateTuringMachine<
			Transition,
			writeSymbolToTape<Position, next_symbol, Tape>,
			next_state,
			next_position
		>>;
};

template <
	template<typename, typename> class Transition,
	typename                           Tape,
	typename                           Position
>
struct simulateTuringMachine<Transition, Tape, void, Position> {
	typedef Tape type;
};

// (define mirror (list (list 1 1 0 2 RIGHT) [...]))
using mirror = tav::List<
//            [state]       [read]       [write]      [next state]  [head movement]
	tav::List<tav::Size<1>, tav::Int<1>, tav::Int<0>, tav::Size<2>, movement::RIGHT>,
	tav::List<tav::Size<1>, tav::Int<0>, tav::Int<0>, void,         movement::NONE >,
	tav::List<tav::Size<2>, tav::Int<1>, tav::Int<1>, tav::Size<2>, movement::RIGHT>,
	tav::List<tav::Size<2>, tav::Int<0>, tav::Int<0>, tav::Size<3>, movement::RIGHT>,
	tav::List<tav::Size<3>, tav::Int<1>, tav::Int<1>, tav::Size<3>, movement::RIGHT>,
	tav::List<tav::Size<3>, tav::Int<0>, tav::Int<1>, tav::Size<4>, movement::LEFT >,
	tav::List<tav::Size<4>, tav::Int<1>, tav::Int<1>, tav::Size<4>, movement::LEFT >,
	tav::List<tav::Size<4>, tav::Int<0>, tav::Int<0>, tav::Size<5>, movement::LEFT >,
	tav::List<tav::Size<5>, tav::Int<1>, tav::Int<1>, tav::Size<5>, movement::LEFT >,
	tav::List<tav::Size<5>, tav::Int<0>, tav::Int<1>, tav::Size<1>, movement::RIGHT>
>;

// (define mirror_initial_tape (list 1 1 1 0 0 0 0))
using mirror_initial_tape = tav::ListOfType<int, 1, 1, 1, 0, 0, 0, 0>;

// (define mirror_final_tape
//   (simulateTuringMachine (transition mirror)
//                          mirror_initial_tape
//                          1
//                          0))
using mirror_final_tape = tav::Eval<simulateTuringMachine<
	transition<mirror>::template state,
	mirror_initial_tape,
	tav::Size<1>,
	tav::Size<0>
>>;

// (define busy_beaver (list (list 'A' 0 1 'B' RIGHT) [...]))
using busy_beaver = tav::List<
//            [state]         [read]       [write]      [next state]    [head movement]
	tav::List<tav::Char<'A'>, tav::Int<0>, tav::Int<1>, tav::Char<'B'>, movement::RIGHT>,
	tav::List<tav::Char<'A'>, tav::Int<1>, tav::Int<1>, tav::Char<'C'>, movement::LEFT >,
	tav::List<tav::Char<'B'>, tav::Int<0>, tav::Int<1>, tav::Char<'A'>, movement::LEFT >,
	tav::List<tav::Char<'B'>, tav::Int<1>, tav::Int<1>, tav::Char<'B'>, movement::RIGHT>,
	tav::List<tav::Char<'C'>, tav::Int<0>, tav::Int<1>, tav::Char<'B'>, movement::LEFT >,
	tav::List<tav::Char<'C'>, tav::Int<1>, tav::Int<1>, void,           movement::NONE >
>;

// (define busy_beaver_initial_tape (make-list 13 0))
using busy_beaver_initial_tape = tav::MakeList<tav::Size<13>, tav::Int<0>>;

// (define busy_beaver_final_tape
//   (simulateTuringMachine (transition busy_beaver)
//                          busy_beaver_initial_tape
//                          'A'
//                          6))
using busy_beaver_final_tape = tav::Eval<simulateTuringMachine<
	transition<busy_beaver>::template state,
	busy_beaver_initial_tape,
	tav::Char<'A'>,
	tav::Size<6>
>>;

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
