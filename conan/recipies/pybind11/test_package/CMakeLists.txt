cmake_minimum_required(VERSION 3.18)
project(Pybind11Test CXX)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

find_package(pybind11 CONFIG REQUIRED)
pybind11_add_module(example SHARED example.cpp)
