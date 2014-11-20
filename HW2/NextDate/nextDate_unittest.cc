#include "../../src/NextDate/nextDate.h"
#include "gtest/gtest.h"

TEST(PathTest, C0)
{
    EXPECT_EQ("Invalid input", nextDate(1, 0, 1811));
    EXPECT_EQ("Impossible date", nextDate(2, 30, 2002));
    EXPECT_EQ("Impossible date", nextDate(2, 29, 2005));
    EXPECT_EQ("Impossible date", nextDate(3, 31, 2005));
    EXPECT_EQ("3/1/2004", nextDate(2, 29, 2004));
    EXPECT_EQ("2/29/2004", nextDate(2, 28, 2004));
    EXPECT_EQ("3/1/2005", nextDate(2, 28, 2005));
    EXPECT_EQ("2/21/2004", nextDate(2, 20, 2004));
    EXPECT_EQ("12/30/2004", nextDate(12, 29, 2004));
    EXPECT_EQ("2012 is over.", nextDate(12, 31, 2012));
    EXPECT_EQ("1/1/2005", nextDate(12, 31, 2004));
    EXPECT_EQ("4/1/2004", nextDate(3, 30, 2004));
    EXPECT_EQ("3/29/2004", nextDate(3, 28, 2004));
    EXPECT_EQ("2/1/2004", nextDate(1, 31, 2004));
    EXPECT_EQ("1/29/2004", nextDate(1, 28, 2004));
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
