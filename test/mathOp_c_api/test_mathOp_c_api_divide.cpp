#include "mathOp_c_api.h"

#include "gtest/gtest.h"

#include <limits>

TEST(MathOpCApiDivideTest, DivideSmallNumbers)
{
    Status operationStatus;

    EXPECT_DOUBLE_EQ(mathOp_arithmetic_divide(0, 1, &operationStatus), 0);
    EXPECT_EQ(operationStatus, SUCCESS);

    EXPECT_DOUBLE_EQ(mathOp_arithmetic_divide(1, 1, &operationStatus), 1);
    EXPECT_EQ(operationStatus, SUCCESS);

    EXPECT_DOUBLE_EQ(mathOp_arithmetic_divide(2, 1, &operationStatus), 2);
    EXPECT_EQ(operationStatus, SUCCESS);

    EXPECT_DOUBLE_EQ(mathOp_arithmetic_divide(3, 1, &operationStatus), 3);
    EXPECT_EQ(operationStatus, SUCCESS);

    EXPECT_DOUBLE_EQ(mathOp_arithmetic_divide(9, 2, &operationStatus), 4.5);
    EXPECT_EQ(operationStatus, SUCCESS);
}

TEST(MathOpCApiDivideTest, DivideSmallNumbersWithNullOperationStatus)
{
    EXPECT_DOUBLE_EQ(mathOp_arithmetic_divide(0, 1, nullptr), 0);
    EXPECT_DOUBLE_EQ(mathOp_arithmetic_divide(1, 1, nullptr), 1);
    EXPECT_DOUBLE_EQ(mathOp_arithmetic_divide(2, 1, nullptr), 2);
    EXPECT_DOUBLE_EQ(mathOp_arithmetic_divide(3, 1, nullptr), 3);
    EXPECT_DOUBLE_EQ(mathOp_arithmetic_divide(9, 2, nullptr), 4.5);
}

TEST(MathOpCApiDivideTest, DivideBigNumbers)
{
    Status operationStatus;

    EXPECT_NEAR(mathOp_arithmetic_divide(1150, 850, &operationStatus), 1.35, 0.01);
    EXPECT_EQ(operationStatus, Status::SUCCESS);

    EXPECT_NEAR(mathOp_arithmetic_divide(100'001, 101, &operationStatus), 990.1, 0.1);
    EXPECT_EQ(operationStatus, Status::SUCCESS);

    EXPECT_DOUBLE_EQ(mathOp_arithmetic_divide(500'100'015, 4, &operationStatus), 125'025'003.75);
    EXPECT_EQ(operationStatus, Status::SUCCESS);

    const auto MAX_INT = std::numeric_limits<int>::max();
    EXPECT_DOUBLE_EQ(mathOp_arithmetic_divide(MAX_INT, 1, &operationStatus), MAX_INT);
    EXPECT_EQ(operationStatus, Status::SUCCESS);
}

TEST(MathOpCApiDivideTest, DivideBigNumbersWithNullOperationStatus)
{
    EXPECT_NEAR(mathOp_arithmetic_divide(1150, 850, nullptr), 1.35, 0.01);
    EXPECT_NEAR(mathOp_arithmetic_divide(100'001, 101, nullptr), 990.1, 0.1);
    EXPECT_DOUBLE_EQ(mathOp_arithmetic_divide(500'100'015, 4, nullptr), 125'025'003.75);

    const auto MAX_INT = std::numeric_limits<int>::max();
    EXPECT_DOUBLE_EQ(mathOp_arithmetic_divide(MAX_INT, 1, nullptr), MAX_INT);
}

TEST(MathOpCApiDivideTest, DivisionByZero)
{
    Status operationStatus;

    const auto MIN_INT = std::numeric_limits<int>::max();
    EXPECT_EQ(mathOp_arithmetic_divide(MIN_INT, 0, &operationStatus), 0);
    EXPECT_EQ(operationStatus, Status::INVALID_ARGUMENT);

    const auto billion = 1'000'000'000;
    EXPECT_EQ(mathOp_arithmetic_divide(billion, 0, &operationStatus), 0);
    EXPECT_EQ(operationStatus, Status::INVALID_ARGUMENT);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}