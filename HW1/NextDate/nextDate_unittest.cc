#include "nextDate.h"
#include "gtest/gtest.h"

TEST(BoundaryValueTest, Normal)
{
    EXPECT_EQ("1/2/1812", nextDate(1, 1, 1812));
    EXPECT_EQ("1/2/1912", nextDate(1, 1, 1912));
    EXPECT_EQ("1/2/2012", nextDate(1, 1, 2012));
    EXPECT_EQ("1/16/1812", nextDate(1, 15, 1812));
    EXPECT_EQ("1/31/1812", nextDate(1, 30, 1812));
    EXPECT_EQ("8/1/1812", nextDate(7, 31, 1812));
    EXPECT_EQ("12/2/1812", nextDate(12, 1, 1812));
    EXPECT_EQ("2012 is over.", nextDate(12, 31, 2012));
}

TEST(BoundaryValueTest, Robust)
{
    EXPECT_EQ("Invalid input", nextDate(1, 1, 1811));
    EXPECT_EQ("Invalid input", nextDate(1, 1, 2013));
    EXPECT_EQ("Invalid input", nextDate(1, 0, 1815));
    EXPECT_EQ("Invalid input", nextDate(1, 32, 1815));
    EXPECT_EQ("Invalid input", nextDate(0, 14, 1995));
    EXPECT_EQ("Invalid input", nextDate(13, 1, 2000));
}



int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
