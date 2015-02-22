#ifndef TYPEASVALUE_EXAMPLE_TURING_SRC_STATE_H_
#define TYPEASVALUE_EXAMPLE_TURING_SRC_STATE_H_

#include "type.h"
#include "list/list.h"
#include "list/operation/higher/find.h"

namespace machine {

namespace state {

namespace field {
	using ID    = tav::Size<0>;
	using READ  = tav::Size<1>;
	using WRITE = tav::Size<2>;
	using NEXT  = tav::Size<3>;
	using MOVE  = tav::Size<4>;
}

// (define (state_accessor state)
//   (lambda (field)
//           (nth field state)))
template <typename State>
struct state_accessor {
	static_assert(
		tav::IsPair<State>::value,
		"machine state is invalid"
	);

	template <typename Field>
	using get = tav::Nth<Field, State>;
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
		tav::IsEqualValue<Id,   tav::Nth<field::ID,   State>>,
		tav::IsEqualValue<Read, tav::Nth<field::READ, State>>
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

// (define (transition states)
//   (lambda (state symbol)
//           (findState state symbol states)))
template <typename States>
struct transition {
	template <
		typename State,
		typename Symbol
	>
	using state = state_accessor<
		findState<State, Symbol, States>
	>;
};

}

}

#endif // TYPEASVALUE_EXAMPLE_TURING_SRC_STATE_H_
