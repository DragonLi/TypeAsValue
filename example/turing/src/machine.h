#ifndef TYPEASVALUE_EXAMPLE_TURING_SRC_MACHINE_H_
#define TYPEASVALUE_EXAMPLE_TURING_SRC_MACHINE_H_

#include "conditional/cond.h"

#include "state.h"
#include "tape.h"

namespace machine {

// (define (updatePosition direction position)
//   (cond ((= direction RIGHT) (+ position 1))
//         ((= direction LEFT)  (- Position 1))
//         (else                position)))
template <
	typename Direction,
	typename Position
>
using updatePosition = tav::Cond<
	tav::Branch<
		tav::IsEqualValue<Direction, tav::Char<'R'>>,
		tav::Add<Position, tav::Size<1>>
	>,
	tav::Branch<
		tav::IsEqualValue<Direction, tav::Char<'L'>>,
		tav::Substract<Position, tav::Size<1>>
	>,
	tav::Else<
		Position
	>
>;


// (define (simulate transition tape state position)
//   (if (= state FINAL)
//     tape
//     (let ((current_state (transition state
//                                      (readSymbol position tape))))
//       (simulate transition
//                 (current_state NEXT)
//                 (writeSymbol position
//                              (current_state WRITE)
//                              tape)
//                 (updatePosition (current_state MOVE)
//                                 position)))))
template <
	template<typename, typename> class Transition,
	typename                           State,
	typename                           Tape,
	typename                           Position
>
class simulate {
	static_assert(
		tav::Not<tav::LowerThan<Position, tav::Size<0>>>::value,
		"machine head position out of bounds"
	);

	private:
		template <typename Field>
		using current_state = typename Transition<
			State,
			tape::readSymbol<Position, Tape>
		>::template get<Field>;

	public:
		using type = tav::Eval<simulate<
			Transition,
			current_state<state::field::NEXT>,
			tape::writeSymbol<
				Position,
				current_state<state::field::WRITE>,
				Tape
			>,
			updatePosition<
				current_state<state::field::MOVE>,
				Position
			>
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
//             state
//             tape
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
