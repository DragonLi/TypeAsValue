# TypeAsValue

…is a template metaprogramming library intended for compile time computation written in C++. As its name implies it follows the overall concept of viewing types as values and templates as functions manipulating those values. 

This library is currently primarily a reimplementation of my previous attempt at this problem: [ConstList](https://github.com/KnairdA/ConstList). As detailed in the appropriate [blog article](http://blog.kummerlaender.eu/article/a_look_at_compile_time_computation_in_cpp/) the mixed approach between generic lambda expressions, `constexpr` marked functions and template metaprogramming doesn't offer sufficient flexibility which led me to approach compile time computation in a slightly different manner via this new library.

## Example

```cpp
// λ (length (filter odd? (list 1 2 3)))
// 2

const std::size_t count = tav::Length<
	tav::Filter<
		tav::Odd,
		tav::List<tav::Int<1>, tav::Int<2>, tav::Int<3>>::type
	>::type
>::type::value;
```

## Current features

* guaranteed evaluation during compile time
* basic math and logic operations
* conditionals
* `Cons` structure
* `List` function as helper for `Cons` construction
* basic list operators such as `Nth`, `Length`, `Take` and `Concatenate`
* higher order list operation `Fold`
* higher order list operations such as `Map` and `Filter` expressed in terms of `Fold`
* higher order list queries such as `Any`, `All` and `None`
* `static_assert` based test cases for all of the above

## Requirements

* C++ compiler with support for C++14
* [CMake](http://www.cmake.org/) for building test cases
