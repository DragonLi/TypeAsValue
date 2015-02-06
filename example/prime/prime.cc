#include <iostream>

#include "type.h"
#include "operation/math.h"

#include "list/list.h"
#include "list/operation/higher/filter.h"
#include "list/generator/iota.h"

#include "runtime/list/for_each.h"

using candidates = tav::Iota<tav::Size<1000>, tav::Int<2>, tav::Int<1>>::type;

template <
	typename Candidate,
	typename Base
>
using isMultipleOf = tav::EqualValue<
	tav::Modulo<Candidate, Base>,
	tav::Int<0>
>;

template <
	typename Candidates,
	typename Base
>
using removeMultiplesOf = tav::Remove<
	tav::Apply<isMultipleOf, tav::_0, Base>::template single_type,
	Candidates
>;

template <typename Candidates>
struct Sieve {
	typedef typename tav::Cons<
		tav::Head<Candidates>,
		typename Sieve<
			typename removeMultiplesOf<
				tav::Tail<Candidates>,
				tav::Head<Candidates>
			>::type
		>::type
	>::type type;
};

template <>
struct Sieve<void> {
	typedef void type;
};

using primes = Sieve<candidates>::type;

int main(int, char **) {
	tav::runtime::for_each<primes>([](const int x) {
		std::cout << x << std::endl;
	});
}
