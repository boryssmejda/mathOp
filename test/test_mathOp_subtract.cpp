#include "mathOp.h"

#include "gtest/gtest.h"

#include <limits>
#include <stdexcept>

TEST(MathOpSubtractTest, SubtractSmallNumbers)
{
    EXPECT_EQ(mathOp::subtract(0,0), 0);
    EXPECT_EQ(mathOp::subtract(0,1), -1);
    EXPECT_EQ(mathOp::subtract(1,1), 0);
    EXPECT_EQ(mathOp::subtract(2,1), 1);
    EXPECT_EQ(mathOp::subtract(3,1), 2);
}

TEST(MathOpSubtractTest, SubtractBigNumbers)
{
    EXPECT_EQ(mathOp::subtract(1150,850), 300);
    EXPECT_EQ(mathOp::subtract(9999,1), 9998);
    EXPECT_EQ(mathOp::subtract(100'001,1), 100'000);
    EXPECT_EQ(mathOp::subtract(500'000'015, 15), 500'000'000);

    const auto MAX_INT = std::numeric_limits<int>::max();
    EXPECT_EQ(mathOp::subtract(MAX_INT, 0), MAX_INT);
}

TEST(MathOpSubtractTest, DetectOverflow)
{
    const auto MAX_INT = std::numeric_limits<int>::max();
    EXPECT_THROW(mathOp::subtract(MAX_INT, -1), std::invalid_argument);
}

TEST(MathOpSubtractTest, DetectUnderflow)
{
    const auto MIN_INT = std::numeric_limits<int>::min();
    EXPECT_THROW(mathOp::subtract(MIN_INT, 1), std::invalid_argument);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}