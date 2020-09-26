#pragma once

#if defined(_WIN32)
    #ifdef MATHLIBRARY_EXPORTS
        #define MATHLIBRARY_API __declspec(dllexport)
    #else
        #define MATHLIBRARY_API
    #endif
#else
    #define MATHLIBRARY_API
#endif

namespace mathOp
{
    MATHLIBRARY_API int add(int a, int b);
    MATHLIBRARY_API int subtract(int a, int b);
}