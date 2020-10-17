#include "mathOp_c_api.h"

#include "gtest/gtest.h"

#include <limits>

TEST(MathOpCApiSubtractTest, SubtractSmallNumbers)
{
    Status operationStatus;

    EXPECT_EQ(mathOp_arithmetic_subtract(0, 0, &operationStatus), 0);
    EXPECT_EQ(operationStatus, Status::SUCCESS);

    EXPECT_EQ(mathOp_arithmetic_subtract(0, 1, &operationStatus), -1);
    EXPECT_EQ(operationStatus, Status::SUCCESS);

    EXPECT_EQ(mathOp_arithmetic_subtract(1, 1, &operationStatus), 0);
    EXPECT_EQ(operationStatus, Status::SUCCESS);

    EXPECT_EQ(mathOp_arithmetic_subtract(2, 1, &operationStatus), 1);
    EXPECT_EQ(operationStatus, Status::SUCCESS);

    EXPECT_EQ(mathOp_arithmetic_subtract(3, 1, &operationStatus), 2);
    EXPECT_EQ(operationStatus, Status::SUCCESS);
}

TEST(MathOpCApiSubtractTest, SubtractSmallNumbersWithNullOperationStatus)
{
    EXPECT_EQ(mathOp_arithmetic_subtract(0,0, nullptr), 0);
    EXPECT_EQ(mathOp_arithmetic_subtract(0,1, nullptr), -1);
    EXPECT_EQ(mathOp_arithmetic_subtract(1,1, nullptr), 0);
    EXPECT_EQ(mathOp_arithmetic_subtract(2,1, nullptr), 1);
    EXPECT_EQ(mathOp_arithmetic_subtract(3,1, nullptr), 2);
}

TEST(MathOpCApiSubtractTest, SubtractBigNumbers)
{
    Status operationStatus;

    EXPECT_EQ(mathOp_arithmetic_subtract(1150, 850, &operationStatus), 300);
    EXPECT_EQ(operationStatus, Status::SUCCESS);

    EXPECT_EQ(mathOp_arithmetic_subtract(9999, 1, &operationStatus), 9998);
    EXPECT_EQ(operationStatus, Status::SUCCESS);

    EXPECT_EQ(mathOp_arithmetic_subtract(100'001, 1, &operationStatus), 100'000);
    EXPECT_EQ(operationStatus, Status::SUCCESS);

    EXPECT_EQ(mathOp_arithmetic_subtract(500'000'015, 15, &operationStatus), 500'000'000);
    EXPECT_EQ(operationStatus, Status::SUCCESS);

    const auto MAX_INT = std::numeric_limits<int>::max();
    EXPECT_EQ(mathOp_arithmetic_subtract(MAX_INT, 0, &operationStatus), MAX_INT);
    EXPECT_EQ(operationStatus, Status::SUCCESS);
}

TEST(MathOpCApiSubtractTest, SubtractBigNumbersWithNullOperationStatus)
{
    EXPECT_EQ(mathOp_arithmetic_subtract(1150, 850, nullptr), 300);
    EXPECT_EQ(mathOp_arithmetic_subtract(9999, 1, nullptr), 9998);
    EXPECT_EQ(mathOp_arithmetic_subtract(100'001, 1, nullptr), 100'000);
    EXPECT_EQ(mathOp_arithmetic_subtract(500'000'015, 15, nullptr), 500'000'000);

    const auto MAX_INT = std::numeric_limits<int>::max();
    EXPECT_EQ(mathOp_arithmetic_subtract(MAX_INT, 0, nullptr), MAX_INT);
}

TEST(MathOpCApiSubtractTest, DetectOverflow)
{
    Status operationStatus;

    const auto MAX_INT = std::numeric_limits<int>::max();
    EXPECT_EQ(mathOp_arithmetic_subtract(MAX_INT, -1, &operationStatus), 0);
    EXPECT_EQ(operationStatus, Status::INVALID_ARGUMENT);
}

TEST(MathOpCApiSubtractTest, DetectOverflowWithNullOperationStatus)
{
    const auto MAX_INT = std::numeric_limits<int>::max();
    EXPECT_EQ(mathOp_arithmetic_subtract(MAX_INT, -1, nullptr), 0);
}

TEST(MathOpCApiSubtractTest, DetectUnderflow)
{
    Status operationStatus;

    const auto MIN_INT = std::numeric_limits<int>::min();
    EXPECT_EQ(mathOp_arithmetic_subtract(MIN_INT, 1, &operationStatus), 0);
    EXPECT_EQ(operationStatus, Status::INVALID_ARGUMENT);
}

TEST(MathOpCApiSubtractTest, DetectUnderflowWithNullOperationStatus)
{
    const auto MIN_INT = std::numeric_limits<int>::min();
    EXPECT_EQ(mathOp_arithmetic_subtract(MIN_INT, 1, nullptr), 0);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}