
cmake_minimum_required(VERSION 3.16)

if("${CMAKE_SOURCE_DIR}" STREQUAL "${CMAKE_BINARY_DIR}")
    message(FATAL_ERROR "In source builds are not allowed!")
endif()

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

project(mathOp CXX)

option(BUILD_SHARED_LIBS OFF)
option(BUILD_TESTS "BUILD_TESTS" ON)

include(cmake/install_target.cmake)
include(cmake/copy_dll_for_unittests.cmake)
include(cmake/configure_unittests.cmake)
include(cmake/install_sharedLib_for_unittests.cmake)

    message(STATUS "MATHOP_BUILD_SHARED: ${MATHOP_BUILD_SHARED}")

    if(BUILD_TESTS)
        find_package(GTest CONFIG REQUIRED)
    endif()

    find_package(fmt CONFIG REQUIRED)
    find_package(pybind11 CONFIG REQUIRED)

    add_subdirectory(src)

    if(BUILD_TESTS)
        add_subdirectory(test)

        enable_testing()
        add_test(NAME test_mathOp_cpp_add COMMAND test_mathOp_cpp_add)
        add_test(NAME test_mathOp_cpp_subtract COMMAND test_mathOp_cpp_subtract)
        add_test(NAME test_mathOp_cpp_multiply COMMAND test_mathOp_cpp_multiply)
        add_test(NAME test_mathOp_cpp_divide COMMAND test_mathOp_cpp_divide)

        # tests should be created only when mathOp is built as static lib
        if(NOT MATHOP_BUILD_SHARED)
            add_test(NAME test_mathOp_c_api_add COMMAND test_mathOp_c_api_add)
            add_test(NAME test_mathOp_c_api_subtract COMMAND test_mathOp_c_api_subtract)
            add_test(NAME test_mathOp_c_api_multiply COMMAND test_mathOp_c_api_multiply)
            add_test(NAME test_mathOp_c_api_divide COMMAND test_mathOp_c_api_divide)
        endif()
    endif()
