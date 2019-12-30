# CMake configuration for libFuzzer testing
#
#	https://llvm.org/docs/LibFuzzer.html


cmake_minimum_required (VERSION 3.10)


# Use clang compiler

set(CMAKE_C_COMPILER clang)
set(CMAKE_CXX_COMPILER clang)


# Enable fuzzer for static libraries as well
# This also includes:
#	leak detection
#	address errors (e.g. reading past end of array, etc.)
#	undefined behavior detection
#
# Use compiler optimization so that fuzz behavior better matches production behavior
# (e.g. tail recursion optimization to prevent stack overflow in some circumstances)

set(CMAKE_C_FLAGS "-pg ${LIBFUZZER_FLAGS_BASE} -fsanitize=address,undefined,leak,fuzzer")
set(CMAKE_CXX_FLAGS "-pg -${LIBFUZZER_FLAGS_BASE} -fsanitize=address,undefined,leak,fuzzer")


# Force Debug build type to speed build time
set(CMAKE_BUILD_TYPE Debug)


project (Fuzzer)


include_directories(submodules/magnum/src)
add_subdirectory(submodules/magnum)

include_directories(submodules/c-title-case/src)
add_subdirectory(submodules/c-title-case)

include_directories(submodules/mmd-6/Sources)
include_directories(submodules/mmd-6/Sources/libMultiMarkdown)
include_directories(submodules/mmd-6/Sources/libMultiMarkdown/include)
add_subdirectory(submodules/mmd-6)


# libTitleCase Fuzzer

add_executable(fuzz_title-case
	fuzz_title-case.c
)

target_link_libraries(fuzz_title-case
	libTitleCase
)


# libMagnum

add_executable(fuzz_magnum
	fuzz_magnum.c
)

target_link_libraries(fuzz_magnum
	libMagnum
)


# libMultiMarkdown Fuzzer

add_executable(fuzz_mmd-6
	fuzz_mmd-6.c
)

target_link_libraries(fuzz_mmd-6
	libMultiMarkdown
)
