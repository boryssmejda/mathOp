#include "mathOp_c_api.h"
#include "mathOp.h"

#include <stdexcept>
#include <iostream>

extern "C"
{
    int mathOp_arithmetic_add(int a, int b, Status *operationStatus)
    {
        if(operationStatus)
        {
            *operationStatus = Status::SUCCESS;
        }

        int result {0};
        try
        {
            result = mathOp::Arithmetic::add(a,b);
        }
        catch(std::invalid_argument& ia)
        {
            std::cout << ia.what() << std::endl;
            if(operationStatus)
            {
                *operationStatus = Status::INVALID_ARGUMENT;
            }
        }
        return result;
    }

    int mathOp_arithmetic_subtract(int a, int b, Status *operationStatus)
    {
        if(operationStatus)
        {
            *operationStatus = Status::SUCCESS;
        }

        int result {0};
        try
        {
            result = mathOp::Arithmetic::subtract(a,b);
        }
        catch(std::invalid_argument& ia)
        {
            std::cout << ia.what() << std::endl;
            if(operationStatus)
            {
                *operationStatus = Status::INVALID_ARGUMENT;
            }
        }
        return result;
    }

    int mathOp_arithmetic_multiply(int a, int b, Status *operationStatus)
    {
        if(operationStatus)
        {
            *operationStatus = Status::SUCCESS;
        }

        int result {0};
        try
        {
            result = mathOp::Arithmetic::multiply(a,b);
        }
        catch(std::invalid_argument& ia)
        {
            std::cout << ia.what() << std::endl;
            if(operationStatus)
            {
                *operationStatus = Status::INVALID_ARGUMENT;
            }
        }

        return result;
    }

    double mathOp_arithmetic_divide(int a, int b, Status *operationStatus)
    {
        if(operationStatus)
        {
            *operationStatus = Status::SUCCESS;
        }

        double result {0.0};
        try
        {
            result = mathOp::Arithmetic::divide(a,b);
        }
        catch(std::invalid_argument& ia)
        {
            std::cout << ia.what() << std::endl;
            if(operationStatus)
            {
                *operationStatus = Status::INVALID_ARGUMENT;
            }
        }

        return result;
    }
}
