#pragma once

#ifdef __cplusplus
extern "C"
{
#endif

#if defined(WIN32) || defined(_WIN32)
    #ifdef MATHOP_C_API_EXPORTS
        #define MATHOP_C_API __declspec(dllexport)
    #else
        #define MATHOP_C_API __declspec(dllimport)
    #endif
#else
    #define MATHOP_API __attribute__ ((visibility ("default")))
#endif

enum Status
{
        SUCCESS,
        INVALID_ARGUMENT
};

typedef enum Status Status;

MATHOP_C_API int mathOp_arithmetic_add(int a, int b, Status *operationStatus);
MATHOP_C_API int mathOp_arithmetic_subtract(int a, int b, Status *operationStatus);
MATHOP_C_API int mathOp_arithmetic_multiply(int a, int b, Status *operationStatus);
MATHOP_C_API double mathOp_arithmetic_divide(int a, int b, Status *operationStatus);

#ifdef __cplusplus
}
#endif