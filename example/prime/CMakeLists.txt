cmake_minimum_required(VERSION 2.8)
project(prime)

set(
	CMAKE_CXX_FLAGS
	"-std=c++14 -W -Wall -Wextra -Winline -pedantic -ftemplate-depth-1024"
)

include_directories(
	../../src/
)

add_executable(
	prime
	prime.cc
)
