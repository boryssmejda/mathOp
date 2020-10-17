#include "mathOp.h"

#include "gtest/gtest.h"

#include <limits>
#include <stdexcept>

TEST(MathOpDivideTest, DivideSmallNumbers)
{
    EXPECT_DOUBLE_EQ(mathOp::Arithmetic::divide(0,1), 0);
    EXPECT_DOUBLE_EQ(mathOp::Arithmetic::divide(1,1), 1);
    EXPECT_DOUBLE_EQ(mathOp::Arithmetic::divide(2,1), 2);
    EXPECT_DOUBLE_EQ(mathOp::Arithmetic::divide(3,1), 3);
    EXPECT_DOUBLE_EQ(mathOp::Arithmetic::divide(9,2), 4.5);
}

TEST(MathOpDivideTest, DivideBigNumbers)
{
    EXPECT_NEAR(mathOp::Arithmetic::divide(1150,850), 1.35, 0.01);
    EXPECT_NEAR(mathOp::Arithmetic::divide(100'001,101), 990.1, 0.1);
    EXPECT_DOUBLE_EQ(mathOp::Arithmetic::divide(500'100'015, 4), 125'025'003.75);

    const auto MAX_INT = std::numeric_limits<int>::max();
    EXPECT_DOUBLE_EQ(mathOp::Arithmetic::divide(MAX_INT, 1), MAX_INT);
}

TEST(MathOpDivideTest, DivisionByZero)
{
    const auto MIN_INT = std::numeric_limits<int>::max();
    EXPECT_THROW(mathOp::Arithmetic::divide(MIN_INT, 0), std::invalid_argument);

    const auto billion = 1'000'000'000;
    EXPECT_THROW(mathOp::Arithmetic::divide(billion, 0), std::invalid_argument);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}