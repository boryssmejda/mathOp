#include "mathOp.h"

#include "gtest/gtest.h"

#include <limits>
#include <stdexcept>

TEST(MathOpAddTest, AddSmallNumbers)
{
    EXPECT_EQ(mathOp::Arithmetic::add(0,0), 0);
    EXPECT_EQ(mathOp::Arithmetic::add(0,1), 1);
    EXPECT_EQ(mathOp::Arithmetic::add(1,1), 2);
    EXPECT_EQ(mathOp::Arithmetic::add(2,1), 3);
    EXPECT_EQ(mathOp::Arithmetic::add(3,1), 4);
}

TEST(MathOpAddTest, AddBigNumbers)
{
    EXPECT_EQ(mathOp::Arithmetic::add(1150,850), 2000);
    EXPECT_EQ(mathOp::Arithmetic::add(9999,1), 10000);
    EXPECT_EQ(mathOp::Arithmetic::add(100'000,1), 100'001);
    EXPECT_EQ(mathOp::Arithmetic::add(100'000'000, 15), 100'000'015);

    const auto MAX_INT = std::numeric_limits<int>::max();
    EXPECT_EQ(mathOp::Arithmetic::add(MAX_INT, 0), MAX_INT);
}

TEST(MathOpAddTest, DetectOverflow)
{
    const auto MAX_INT = std::numeric_limits<int>::max();
    EXPECT_THROW(mathOp::Arithmetic::add(MAX_INT, 1), std::invalid_argument);
}

TEST(MathOpAddTest, DetectUnderflow)
{
    const auto MIN_INT = std::numeric_limits<int>::min();
    EXPECT_THROW(mathOp::Arithmetic::add(MIN_INT, -1), std::invalid_argument);
}


int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}