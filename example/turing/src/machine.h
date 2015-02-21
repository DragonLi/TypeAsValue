#ifndef TYPEASVALUE_EXAMPLE_TURING_SRC_MACHINE_H_
#define TYPEASVALUE_EXAMPLE_TURING_SRC_MACHINE_H_

#include "conditional/cond.h"

#include "state.h"
#include "tape.h"

namespace machine {

// (define (simulate transition tape state position)
//   (if (= state FINAL)
//     tape
//     (let* ((current_symbol (readSymbol position tape))
//            (current_state  (transition state current_symbol))
//            (direction      (nth MOVE  current_state))
//            (next_symbol    (nth WRITE current_state))
//            (next_state     (nth NEXT  current_state))
//            (next_position  (cond ((= direction RIGHT) (+ position 1))
//                                  ((= direction LEFT)  (- Position 1))
//                                  (else                position))))
//       (simulate transition
//                 (writeSymbol position next_symbol tape)
//                 next_state,
//                 next_position)))
template <
	template<typename, typename> class Transition,
	typename                           State,
	typename                           Tape,
	typename                           Position
>
class simulate {
	private:
		using current_symbol = tape::readSymbol<Position, Tape>;
		using current_state  = Transition<State, current_symbol>;

		using direction      = tav::Nth<state::field::MOVE,  current_state>;

		using next_symbol    = tav::Nth<state::field::WRITE, current_state>;
		using next_state     = tav::Nth<state::field::NEXT,  current_state>;
		using next_position  = tav::Cond<
			tav::Branch<
				tav::IsEqualValue<direction, tav::Char<'R'>>,
				tav::Add<Position, tav::Size<1>>
			>,
			tav::Branch<
				tav::IsEqualValue<direction, tav::Char<'L'>>,
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
		using type = tav::Eval<simulate<
			Transition,
			next_state,
			tape::writeSymbol<Position, next_symbol, Tape>,
			next_position
		>>;
};

template <
	template<typename, typename> class Transition,
	typename                           Tape,
	typename                           Position
>
struct simulate<Transition, void, Tape, Position> {
	typedef Tape type;
};

// (define (run program state tape position)
//   (simulate (transition program)
//             tape
//             state
//             position))
template <
	typename Program,
	typename State,
	typename Tape,
	typename Position
>
using run = tav::Eval<simulate<
	state::transition<Program>::template state,
	State,
	Tape,
	Position
>>;

}

#endif // TYPEASVALUE_EXAMPLE_TURING_SRC_MACHINE_H_
