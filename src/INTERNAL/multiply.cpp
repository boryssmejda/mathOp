#include "mathOp.h"

#include <stdexcept>
#include <limits>

#define FMT_HEADER_ONLY
#include "fmt/format.h"

namespace
{
    bool wouldOverflow(int a, int b)
    {
        const int MAX_INT = std::numeric_limits<int>::max();
        const int MIN_INT = std::numeric_limits<int>::min();

        if(a == -1 && b == MIN_INT)
        {
            return true;
        }
        else if(a == MIN_INT && b == -1)
        {
            return true;
        }

        if((b > 0) && (a > static_cast<double>(MAX_INT)/b))
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    bool wouldUnderflow(int a, int b)
    {
        const int MIN_INT = std::numeric_limits<int>::min();

        if((b < 0) && (a < static_cast<double>(MIN_INT)/b))
        {
            return true;
        }
        else
        {
            return false;
        }
    }
}

int mathOp::multiply(int a, int b)
{
    fmt::print("Multiplication for a = {} and b = {}", a, b);
    if(wouldOverflow(a, b))
    {
        throw std::invalid_argument("Multiplication would result in integer overflow!");
    }
    else if(wouldUnderflow(a, b))
    {
        throw std::invalid_argument("Multiplication would result in integer underflow!");
    }
    else
    {
        return a * b;
    }
}