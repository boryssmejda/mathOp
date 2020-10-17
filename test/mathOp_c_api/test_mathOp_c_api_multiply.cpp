#include "mathOp_c_api.h"

#include "gtest/gtest.h"

#include <limits>

TEST(MathOpCApiMultiplyTest, MultiplySmallNumbers)
{
    Status operationStatus;

    EXPECT_EQ(mathOp_arithmetic_multiply(0,0, &operationStatus), 0);
    EXPECT_EQ(operationStatus, Status::SUCCESS);

    EXPECT_EQ(mathOp_arithmetic_multiply(0,1, &operationStatus), 0);
    EXPECT_EQ(operationStatus, Status::SUCCESS);

    EXPECT_EQ(mathOp_arithmetic_multiply(1,1, &operationStatus), 1);
    EXPECT_EQ(operationStatus, Status::SUCCESS);

    EXPECT_EQ(mathOp_arithmetic_multiply(2,1, &operationStatus), 2);
    EXPECT_EQ(operationStatus, Status::SUCCESS);

    EXPECT_EQ(mathOp_arithmetic_multiply(3,1, &operationStatus), 3);
    EXPECT_EQ(operationStatus, Status::SUCCESS);

    EXPECT_EQ(mathOp_arithmetic_multiply(9,2, &operationStatus), 18);
    EXPECT_EQ(operationStatus, Status::SUCCESS);
}

TEST(MathOpCApiMultiplyTest, MultiplySmallNumbersWithNullOperationStatus)
{
    EXPECT_EQ(mathOp_arithmetic_multiply(0,0, nullptr), 0);
    EXPECT_EQ(mathOp_arithmetic_multiply(0,1, nullptr), 0);
    EXPECT_EQ(mathOp_arithmetic_multiply(1,1, nullptr), 1);
    EXPECT_EQ(mathOp_arithmetic_multiply(2,1, nullptr), 2);
    EXPECT_EQ(mathOp_arithmetic_multiply(3,1, nullptr), 3);
    EXPECT_EQ(mathOp_arithmetic_multiply(9,2, nullptr), 18);
}

TEST(MathOpCApiMultiplyTest, MultiplyBigNumbers)
{
    Status operationStatus;

    EXPECT_EQ(mathOp_arithmetic_multiply(1150, 850, &operationStatus), 977'500);
    EXPECT_EQ(mathOp_arithmetic_multiply(9999, 1, &operationStatus), 9999);
    EXPECT_EQ(mathOp_arithmetic_multiply(100'001, 101, &operationStatus), 10'100'101);
    EXPECT_EQ(mathOp_arithmetic_multiply(500'000'015, 4, &operationStatus), 2'000'000'060);

    const auto MAX_INT = std::numeric_limits<int>::max();
    EXPECT_EQ(mathOp_arithmetic_multiply(MAX_INT, 1, &operationStatus), MAX_INT);
}

TEST(MathOpCApiMultiplyTest, MultiplyBigNumbersWithNullOperationStatus)
{
    EXPECT_EQ(mathOp_arithmetic_multiply(1150, 850, nullptr), 977'500);
    EXPECT_EQ(mathOp_arithmetic_multiply(9999, 1, nullptr), 9999);
    EXPECT_EQ(mathOp_arithmetic_multiply(100'001, 101, nullptr), 10'100'101);
    EXPECT_EQ(mathOp_arithmetic_multiply(500'000'015, 4, nullptr), 2'000'000'060);

    const auto MAX_INT = std::numeric_limits<int>::max();
    EXPECT_EQ(mathOp_arithmetic_multiply(MAX_INT, 1, nullptr), MAX_INT);
}

TEST(MathOpCApiMultiplyTest, DetectOverflow)
{
    Status operationStatus;

    const auto MIN_INT = std::numeric_limits<int>::max();
    EXPECT_EQ(mathOp_arithmetic_multiply(MIN_INT, -1, &operationStatus), 0);
    EXPECT_EQ(operationStatus, Status::INVALID_ARGUMENT);

    const auto billion = 1'000'000'000;
    EXPECT_EQ(mathOp_arithmetic_multiply(billion, billion, &operationStatus), 0);
    EXPECT_EQ(operationStatus, Status::INVALID_ARGUMENT);
}

TEST(MathOpCApiMultiplyTest, DetectOverflowWithNullOperationStatus)
{
    const auto MIN_INT = std::numeric_limits<int>::max();
    EXPECT_EQ(mathOp_arithmetic_multiply(MIN_INT, -1, nullptr), 0);

    const auto billion = 1'000'000'000;
    EXPECT_EQ(mathOp_arithmetic_multiply(billion, billion, nullptr), 0);
}

TEST(MathOpCApiMultiplyTest, DetectUnderflow)
{
    Status operationStatus;

    const auto MIN_INT = std::numeric_limits<int>::min();
    EXPECT_EQ(mathOp_arithmetic_multiply(MIN_INT, 2, &operationStatus), 0);
    EXPECT_EQ(operationStatus, Status::INVALID_ARGUMENT);
}

TEST(MathOpCApiMultiplyTest, DetectUnderflowWithNullOperationStatus)
{
    const auto MIN_INT = std::numeric_limits<int>::min();
    EXPECT_EQ(mathOp_arithmetic_multiply(MIN_INT, 2, nullptr), 0);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}