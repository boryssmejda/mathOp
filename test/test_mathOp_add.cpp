#include "mathOp.h"

#include "gtest/gtest.h"


TEST(MathOpAddTest, AddSmallNumbers)
{
    EXPECT_EQ(mathOp::add(0,0), 0);
    EXPECT_EQ(mathOp::add(0,1), 1);
    EXPECT_EQ(mathOp::add(1,1), 2);
    EXPECT_EQ(mathOp::add(2,1), 3);
    EXPECT_EQ(mathOp::add(3,1), 4);
}

TEST(MathOpAddTest, AddBigNumbers)
{
    EXPECT_EQ(mathOp::add(1150,850), 2000);
    EXPECT_EQ(mathOp::add(9999,1), 10000);
    EXPECT_EQ(mathOp::add(100000,1), 100001);
    EXPECT_EQ(mathOp::add(100'000'000, 15), 100'000'015);
}

TEST(MathOpAddTest, DetectOverflow)
{

}

TEST(MathOpAddTest, DetectUnderflow)
{

}


int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}