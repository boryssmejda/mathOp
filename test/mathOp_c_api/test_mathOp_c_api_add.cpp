#include "mathOp_c_api.h"

#include "gtest/gtest.h"

#include <limits>

TEST(MathOpCApiAddTest, AddSmallNumbers)
{
    Status operationStatus;

    EXPECT_EQ(mathOp_arithmetic_add(0, 0, &operationStatus), 0);
    EXPECT_EQ(operationStatus, Status::SUCCESS);

    EXPECT_EQ(mathOp_arithmetic_add(0, 1, &operationStatus), 1);
    EXPECT_EQ(operationStatus, Status::SUCCESS);

    EXPECT_EQ(mathOp_arithmetic_add(1, 1, &operationStatus), 2);
    EXPECT_EQ(operationStatus, Status::SUCCESS);

    EXPECT_EQ(mathOp_arithmetic_add(2, 1, &operationStatus), 3);
    EXPECT_EQ(operationStatus, Status::SUCCESS);

    EXPECT_EQ(mathOp_arithmetic_add(3, 1, &operationStatus), 4);
    EXPECT_EQ(operationStatus, Status::SUCCESS);
}

TEST(MathOpCApiAddTest, AddSmallNumbersWithNullOperationStatus)
{
    EXPECT_EQ(mathOp_arithmetic_add(0, 0, nullptr), 0);

    EXPECT_EQ(mathOp_arithmetic_add(0, 1, nullptr), 1);

    EXPECT_EQ(mathOp_arithmetic_add(1, 1, nullptr), 2);

    EXPECT_EQ(mathOp_arithmetic_add(2, 1, nullptr), 3);

    EXPECT_EQ(mathOp_arithmetic_add(3, 1, nullptr), 4);
}

TEST(MathOpCApiAddTest, AddBigNumbers)
{
    Status operationStatus;

    EXPECT_EQ(mathOp_arithmetic_add(1150, 850, &operationStatus), 2000);
    EXPECT_EQ(operationStatus, Status::SUCCESS);

    EXPECT_EQ(mathOp_arithmetic_add(9999, 1, &operationStatus), 10000);
    EXPECT_EQ(operationStatus, Status::SUCCESS);

    EXPECT_EQ(mathOp_arithmetic_add(100'000, 1, &operationStatus), 100'001);
    EXPECT_EQ(operationStatus, Status::SUCCESS);

    EXPECT_EQ(mathOp_arithmetic_add(100'000'000, 15, &operationStatus), 100'000'015);
    EXPECT_EQ(operationStatus, Status::SUCCESS);

    const auto MAX_INT = std::numeric_limits<int>::max();
    EXPECT_EQ(mathOp_arithmetic_add(MAX_INT, 0, &operationStatus), MAX_INT);
    EXPECT_EQ(operationStatus, Status::SUCCESS);
}

TEST(MathOpCApiAddTest, AddBigNumbersWithNullOperationStatus)
{
    EXPECT_EQ(mathOp_arithmetic_add(1150, 850, nullptr), 2000);
    EXPECT_EQ(mathOp_arithmetic_add(9999, 1, nullptr), 10000);
    EXPECT_EQ(mathOp_arithmetic_add(100'000, 1, nullptr), 100'001);
    EXPECT_EQ(mathOp_arithmetic_add(100'000'000, 15, nullptr), 100'000'015);

    const auto MAX_INT = std::numeric_limits<int>::max();
    EXPECT_EQ(mathOp_arithmetic_add(MAX_INT, 0, nullptr), MAX_INT);
}

TEST(MathOpCApiAddTest, DetectOverflow)
{
    Status operationStatus;

    const auto MAX_INT = std::numeric_limits<int>::max();
    EXPECT_EQ(mathOp_arithmetic_add(MAX_INT, 1, &operationStatus), 0);
    EXPECT_EQ(operationStatus, Status::INVALID_ARGUMENT);
}

TEST(MathOpCApiAddTest, DetectOverflowWithNullOperationStatus)
{
    const auto MAX_INT = std::numeric_limits<int>::max();
    EXPECT_EQ(mathOp_arithmetic_add(MAX_INT, 1, nullptr), 0);
}

TEST(MathOpCApiAddTest, DetectUnderflow)
{
    Status operationStatus;

    const auto MIN_INT = std::numeric_limits<int>::min();
    EXPECT_EQ(mathOp_arithmetic_add(MIN_INT, -1, &operationStatus), 0);
    EXPECT_EQ(operationStatus, Status::INVALID_ARGUMENT);
}

TEST(MathOpCApiAddTest, DetectUnderflowWithNullOperationStatus)
{
    const auto MIN_INT = std::numeric_limits<int>::min();
    EXPECT_EQ(mathOp_arithmetic_add(MIN_INT, -1, nullptr), 0);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}