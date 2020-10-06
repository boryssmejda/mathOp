
cmake_minimum_required(VERSION 3.16)

if("${CMAKE_SOURCE_DIR}" STREQUAL "${CMAKE_BINARY_DIR}")
    message(FATAL_ERROR "In source builds are not allowed!")
endif()

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

project(Producer CXX)

option(BUILD_SHARED_LIBS OFF)
option(BUILD_TESTS "BUILD_TESTS" ON)

    add_subdirectory(src)
    if(BUILD_TESTS)
        add_subdirectory(test)

        enable_testing()
        add_test(NAME test_mathOp_add COMMAND test_mathOp_add)
        add_test(NAME test_mathOp_subtract COMMAND test_mathOp_subtract)
        add_test(NAME test_mathOp_multiply COMMAND test_mathOp_multiply)
        add_test(NAME test_mathOp_divide COMMAND test_mathOp_divide)
    endif()
