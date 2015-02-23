#ifndef TYPEASVALUE_EXAMPLE_TURING_SRC_TAPE_H_
#define TYPEASVALUE_EXAMPLE_TURING_SRC_TAPE_H_

#include "type.h"
#include "list/list.h"
#include "list/operation/replace_nth.h"
#include "conditional/if.h"

namespace machine {

namespace tape {

struct BLANK {
	typedef BLANK type;

	static constexpr char value{'\0'};
};

// (define (readSymbol position tape)
//   (if (= (length tape) position)
//       '()
//       (nth position tape)))
template <
	typename Position,
	typename Tape
>
using readSymbol = tav::Eval<tav::If<
	tav::LowerThan<Position, tav::Length<Tape>>,
	tav::utility::defer_eval<tav::Nth, Position, Tape>,
	BLANK
>>;

// (define (writeSymbol position symbol tape)
//   (if (= (length tape) position)
//       (append tape (list symbol))
//       (replace-nth position symbol tape)))
template <
	typename Position,
	typename Symbol,
	typename Tape
>
using writeSymbol = tav::If<
	tav::IsEqualValue<tav::Length<Tape>, Position>,
	tav::Append<Tape, tav::List<Symbol>>,
	tav::ReplaceNth<Position, Symbol, Tape>
>;

}

}

#endif // TYPEASVALUE_EXAMPLE_TURING_SRC_TAPE_H_
