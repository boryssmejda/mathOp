#include "mathOp.h"

#include <stdexcept>
#include <limits>

#define FMT_HEADER_ONLY
#include "fmt/format.h"

namespace
{
    bool wouldOverflow(int a, int b) noexcept
    {
        const int MAX_INT = std::numeric_limits<int>::max();
        if ((b > 0) && (a > MAX_INT - b))
        {
            return true;
        }
        else
        {
             return false;
        }
    }

    bool wouldUnderFlow(int a, int b)
    {
        const int MIN_INT = std::numeric_limits<int>::min();
        if((b < 0) && (a < MIN_INT - b))
        {
            return true;
        }
        else
        {
            return false;
        }
    }
}

int mathOp::add(int a, int b)
{
    fmt::print("Addition for a = {} and b = {}", a, b);
    if(wouldOverflow(a, b))
    {
        throw std::invalid_argument("Addition would result in integer overflow!");
    }
    else if (wouldUnderFlow(a, b))
    {
        throw std::invalid_argument("Addition would result in integer underflow!");
    }
    else
    {
        return a + b;
    }
}