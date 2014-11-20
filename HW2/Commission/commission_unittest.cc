#include "../../src/Commission/commission.h"
#include "gtest/gtest.h"

TEST(PathTest, C0)
{
    EXPECT_EQ(0, calculateCommission(-1, 1, 1));
    EXPECT_EQ(-1, calculateCommission(0, 48, 48));
    EXPECT_EQ(13, calculateCommission(1, 2, 1));
    EXPECT_EQ(106.75, calculateCommission(11, 10, 10));
    EXPECT_EQ(1411, calculateCommission(69, 80, 90));
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
