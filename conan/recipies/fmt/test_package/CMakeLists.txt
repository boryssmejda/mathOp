cmake_minimum_required(VERSION 3.18)
project(fmtTest CXX)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

add_executable(fmtTest test.cpp)

find_package(fmt CONFIG REQUIRED)
target_link_libraries(fmtTest fmt::fmt)
