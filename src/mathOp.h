#pragma once




#if defined(WIN32) || defined(_WIN32)
    #ifdef MATHOP_STATIC
        #define MATHOP_API
    #elif  defined(MATHOP_SHARED)
        #define MATHOP_API __declspec(dllexport)
    #else
        #define MATHOP_API __declspec(dllimport)
    #endif
#else
    #ifdef MATHOP_SHARED
        #define MATHOP_API __attribute__ ((visibility ("default")))
    #else
        #define MATHOP_API
    #endif
#endif

namespace mathOp
{
    MATHOP_API int add(int a, int b);
    MATHOP_API int subtract(int a, int b);
    MATHOP_API int multiply(int a, int b);
    MATHOP_API double divide(int a, int b);
}
