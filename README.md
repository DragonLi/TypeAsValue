# TypeAsValue

…is a template metaprogramming library intended for compile time computation written in C++. As its name implies it follows the overall concept of viewing types as values and templates as functions manipulating those values.

This library is a expanded reimplementation of my previous attempt at this problem: [ConstList](https://github.com/KnairdA/ConstList). As detailed in the appropriate [blog article](http://blog.kummerlaender.eu/article/a_look_at_compile_time_computation_in_cpp/) the mixed approach between generic lambda expressions, `constexpr` marked functions and template metaprogramming doesn't offer sufficient flexibility which led me to approach compile time computation in a slightly different manner via this new library. As one might notice this boils down to using _Scheme_ as a metaphor for C++ template metaprogramming. In fact all test cases and examples are documented by representing their logic in _Scheme_.

## Example

	// λ (length (filter odd? (list 1 2 3)))
	// 2
	
	const std::size_t count = tav::Length<
		tav::Filter<
			tav::Odd,
			tav::List<tav::Int<1>, tav::Int<2>, tav::Int<3>>
		>
	>::value;

More extensive examples are available in the form of implementations of the [Sieve of Eratosthenes](https://github.com/KnairdA/TypeAsValue/tree/master/example/prime) as well as of a [Turing machine](https://github.com/KnairdA/TypeAsValue/tree/master/example/turing).

## Current features

* guaranteed evaluation during compile time
* basic math and logic operations
* conditionals such as `If` and `Cond`
* `Cons` constructor for `Pair` type
* `List` function as helper for `Pair` based list construction
* basic list operators such as `Nth`, `Length`, `Take` and `Append`
* list generators such as `Iota` and `MakeList`
* higher order list operation `Fold`
* higher order list operations such as `Map` and `Filter` expressed in terms of `Fold`
* higher order list queries such as `Find`, `Any`, `All` and `None`
* higher order list generators such as `ListTabulate`
* higher order list operations such as `TakeWhile`, `Partition` and `Sort`
* basic partial function application support using `Apply`
* `static_assert` based test cases for all of the above
* MIT license

## Building

As _TypeAsValue_ is completely implemented via template metaprogramming it is a header only library and as such may only be built in conjunction with the code which is making use of it. This means that one may use a arbitrary build system in practice while the `static_assert` based test cases and example applications make use of _CMake_ and can be compiled as follows:

	git clone "https://github.com/KnairdA/TypeAsValue.git"
	cd TypeAsValue # respectively "cd TypeAsValue/example/{turing|prime}"
	mkdir build
	cd build
	cmake ..
	make

## Requirements

* C++ compiler with support for C++14
* [CMake](http://www.cmake.org/) for building test cases
