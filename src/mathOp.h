#pragma once

#if defined(WIN32) || defined(_WIN32)
    #ifdef MATHOP_SHARED
        #define MATHOP_API __declspec(dllexport)
    #else
        #define MATHOP_API __declspec(dllimport)
    #endif
#else
    #define MATHOP_API
#endif

namespace mathOp
{
    MATHOP_API int add(int a, int b);
    MATHOP_API int subtract(int a, int b);
    MATHOP_API int multiply(int a, int b);
    MATHOP_API double divide(int a, int b);
}
