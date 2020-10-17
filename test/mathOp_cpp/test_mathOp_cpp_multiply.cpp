#include "mathOp.h"

#include "gtest/gtest.h"

#include <limits>
#include <stdexcept>

TEST(MathOpMultiplyTest, MultiplySmallNumbers)
{
    EXPECT_EQ(mathOp::Arithmetic::multiply(0,0), 0);
    EXPECT_EQ(mathOp::Arithmetic::multiply(0,1), 0);
    EXPECT_EQ(mathOp::Arithmetic::multiply(1,1), 1);
    EXPECT_EQ(mathOp::Arithmetic::multiply(2,1), 2);
    EXPECT_EQ(mathOp::Arithmetic::multiply(3,1), 3);
    EXPECT_EQ(mathOp::Arithmetic::multiply(9,2), 18);
}

TEST(MathOpMultiplyTest, MultiplyBigNumbers)
{
    EXPECT_EQ(mathOp::Arithmetic::multiply(1150,850), 977'500);
    EXPECT_EQ(mathOp::Arithmetic::multiply(9999,1), 9999);
    EXPECT_EQ(mathOp::Arithmetic::multiply(100'001,101), 10'100'101);
    EXPECT_EQ(mathOp::Arithmetic::multiply(500'000'015, 4), 2'000'000'060);

    const auto MAX_INT = std::numeric_limits<int>::max();
    EXPECT_EQ(mathOp::Arithmetic::multiply(MAX_INT, 1), MAX_INT);
}

TEST(MathOpMultiplyTest, DetectOverflow)
{
    const auto MIN_INT = std::numeric_limits<int>::max();
    EXPECT_THROW(mathOp::Arithmetic::multiply(MIN_INT, -1), std::invalid_argument);

    const auto billion = 1'000'000'000;
    EXPECT_THROW(mathOp::Arithmetic::multiply(billion, billion), std::invalid_argument);
}

TEST(MathOpMultiplyTest, DetectUnderflow)
{
    const auto MIN_INT = std::numeric_limits<int>::min();
    EXPECT_THROW(mathOp::Arithmetic::multiply(MIN_INT, 2), std::invalid_argument);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}