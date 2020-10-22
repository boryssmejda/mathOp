import ctypes
import os.path


class Arithmetic:

    class OperationStatus:
        SUCCESS = 0
        INVALID_ARGUMENT = 1
        UNKNOWN = 2

    def __init__(self, mathOp_shared_object_location: str):

        assert os.path.isfile, "{} does not exist! Aborting ...".format(mathOp_shared_object_location)

        self.__MATHOP_C_API_LOCAITON = ctypes.CDLL(mathOp_shared_object_location)

        self.__MATHOP_C_API_LOCAITON.mathOp_arithmetic_add.restype = ctypes.c_int
        self.__MATHOP_C_API_LOCAITON.mathOp_arithmetic_add.argtypes = [ctypes.c_int, ctypes.c_int, ctypes.POINTER(ctypes.c_int)]

        self.__MATHOP_C_API_LOCAITON.mathOp_arithmetic_subtract.restype = ctypes.c_int
        self.__MATHOP_C_API_LOCAITON.mathOp_arithmetic_add.argtypes = [ctypes.c_int, ctypes.c_int, ctypes.POINTER(ctypes.c_int)]

        self.__MATHOP_C_API_LOCAITON.mathOp_arithmetic_multiply.restype = ctypes.c_int
        self.__MATHOP_C_API_LOCAITON.mathOp_arithmetic_add.argtypes = [ctypes.c_int, ctypes.c_int, ctypes.POINTER(ctypes.c_int)]

        self.__MATHOP_C_API_LOCAITON.mathOp_arithmetic_divide.restype = ctypes.c_double
        self.__MATHOP_C_API_LOCAITON.mathOp_arithmetic_add.argtypes = [ctypes.c_int, ctypes.c_int, ctypes.POINTER(ctypes.c_int)]

    def __function_caller(self, func, a: int, b: int) -> int:
        opStatus = ctypes.c_int(Arithmetic.OperationStatus.UNKNOWN)
        result = func(a,b, ctypes.byref(opStatus))

        if opStatus.value != Arithmetic.OperationStatus.SUCCESS:
            raise ValueError("Operation would result in overflow/underflow!")

        return result

    def add(self, a: int, b: int) -> int:
        return self.__function_caller(self.__MATHOP_C_API_LOCAITON.mathOp_arithmetic_add, a, b)

    def subtract(self, a: int, b: int) -> int:
        return self.__function_caller(self.__MATHOP_C_API_LOCAITON.mathOp_arithmetic_subtract, a, b)

    def multiply(self, a: int, b: int) -> int:
        return self.__function_caller(self.__MATHOP_C_API_LOCAITON.mathOp_arithmetic_multiply, a, b)

    def divide(self, a: int, b: int) -> int:
        return self.__function_caller(self.__MATHOP_C_API_LOCAITON.mathOp_arithmetic_divide, a, b)
