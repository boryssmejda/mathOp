#include "mathOp.h"

#include <stdexcept>

#define FMT_HEADER_ONLY
#include "fmt/format.h"

int mathOp::add(int a, int b)
{
    fmt::print("Addition for a = {} and b = {}", a, b);
    return a + b;
}

int mathOp::subtract(int a, int b)
{
    fmt::print("Subtraction for a = {} and b = {}", a, b);
    return a - b;
}

int mathOp::multiply(int a, int b)
{
    fmt::print("Multiplication for a = {} and b = {}", a, b);
    return a * b;
}

double mathOp::divide(int a, int b)
{
    fmt::print("Division for a = {} and b = {}", a, b);
    if(b == 0)
    {
        std::invalid_argument("Denominator cannot be 0 during division!");
    }

    return static_cast<double>(a)/static_cast<double>(b);
}
