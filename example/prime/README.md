# prime

…is a small example of how _TypeAsValue_ may be used to perform compile time computations, in this case finding prime numbers using the _Sieve of Eratosthenes_.

Note that this implements a rather plain version of the sieve lacking any kind of optimization. Currently used features of _TypeAsValue_ are `Remove` as a higher order filter function, `Iota` for generating the candidate list, `runtime::for_each` to ease runtime representation of the selected primes as well as basic math and type operators.
