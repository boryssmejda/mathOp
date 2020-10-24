#include "pybind11/pybind11.h"
#include "mathOp.h"

#include <iostream>

namespace py = pybind11;
using namespace pybind11::literals;


PYBIND11_MODULE(mathOp_cpp, m)
{
    py::class_<mathOp::Arithmetic>(m,"Arithmetic")
                    .def_static("add", &mathOp::Arithmetic::add, "a"_a, "b"_a)
                    .def_static("subtract", &mathOp::Arithmetic::subtract, "a"_a, "b"_a)
                    .def_static("multiply", &mathOp::Arithmetic::multiply, "a"_a, "b"_a)
                    .def_static("divide", &mathOp::Arithmetic::divide, "a"_a, "b"_a);
}
