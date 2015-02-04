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
class removeMultiplesOf {
	private:
		template <typename Element>
		using predicate_wrapper = isMultipleOf<Element, Base>;

	public:
		typedef typename tav::Remove<
			predicate_wrapper,
			Candidates
		>::type type;
};

template <typename Candidates>
struct Sieve {
	typedef tav::Cons<
		tav::Head<Candidates>,
		typename Sieve<
			typename removeMultiplesOf<
				tav::Tail<Candidates>,
				tav::Head<Candidates>
			>::type
		>::type
	> type;
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
