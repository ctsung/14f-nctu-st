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

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
