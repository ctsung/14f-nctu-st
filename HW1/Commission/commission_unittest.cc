#include "commission.h"
#include "gtest/gtest.h"

TEST(BoundaryValueTest, Normal)
{
    EXPECT_EQ(10, calculateCommission(1, 1, 1));
    EXPECT_EQ(12.5, calculateCommission(1, 1, 2));
    EXPECT_EQ(220, calculateCommission(18, 18, 18));
    EXPECT_EQ(820, calculateCommission(48, 48, 48));
    EXPECT_EQ(1411, calculateCommission(69, 80, 90));
    EXPECT_EQ(1420, calculateCommission(70, 80, 90));
}

TEST(BoundaryValueTest, Robust)
{
    EXPECT_EQ(-1, calculateCommission(0, 48, 48));
    EXPECT_EQ(-1, calculateCommission(48, 0, 48));
    EXPECT_EQ(-1, calculateCommission(48, 48, 0));
    EXPECT_EQ(-1, calculateCommission(71, 48, 48));
    EXPECT_EQ(-1, calculateCommission(48, 81, 48));
    EXPECT_EQ(-1, calculateCommission(48, 48, 91));
}

TEST(EquivalenceClassTest, WeakNormal)
{
    EXPECT_EQ(13, calculateCommission(1, 2, 1));
    EXPECT_EQ(97.5, calculateCommission(10, 10, 9));
    EXPECT_EQ(215.5, calculateCommission(18, 17, 18));
    EXPECT_EQ(1414, calculateCommission(70, 79, 90));
}

TEST(EquivalenceClassTest, WeakRobust)
{
    EXPECT_EQ(-1, calculateCommission(-2, 40, 45));
    EXPECT_EQ(-1, calculateCommission(71, 40, 45));
    EXPECT_EQ(-1, calculateCommission(35, -1, 45));
    EXPECT_EQ(-1, calculateCommission(35, 81, 45));
    EXPECT_EQ(-1, calculateCommission(35, 40, -1));
    EXPECT_EQ(-1, calculateCommission(35, 40, 91));
}

TEST(EquivalenceClassTest, StrongNormal)
{
    EXPECT_EQ(50, calculateCommission(5, 5, 5));
    EXPECT_EQ(106.75, calculateCommission(11, 10, 10));
    EXPECT_EQ(226, calculateCommission(18, 19, 18));
    EXPECT_EQ(1411, calculateCommission(69, 80, 90));
}

TEST(EquivalenceClassTest, StrongRobust)
{
    EXPECT_EQ(-1, calculateCommission(-2, -1, 45));
    EXPECT_EQ(-1, calculateCommission(-2, 45, -1));
    EXPECT_EQ(-1, calculateCommission(35, -1, -1));
    EXPECT_EQ(-1, calculateCommission(-2, -1, -1));
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
