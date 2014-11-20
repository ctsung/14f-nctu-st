#include "../../src/NextDate/nextDate.h"
#include "gtest/gtest.h"

TEST(PathTest, C0)
{
    EXPECT_EQ("Invalid input", nextDate(1, 0, 1811));
    EXPECT_EQ("Impossible date", nextDate(2, 30, 2002));
    EXPECT_EQ("Impossible date", nextDate(2, 29, 2005));
    EXPECT_EQ("Impossible date", nextDate(3, 31, 2005));
    EXPECT_EQ("3/1/2000", nextDate(2, 29, 2000));
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

TEST(PathTest, C1)
{
    EXPECT_EQ("Invalid input", nextDate(1, 2, 1811));
    EXPECT_EQ("Invalid input", nextDate(1, 1, 2013));
    EXPECT_EQ("Invalid input", nextDate(1, 0, 1814));
    EXPECT_EQ("Invalid input", nextDate(1, 32, 1888));
    EXPECT_EQ("Invalid input", nextDate(0, 10, 1810));
    EXPECT_EQ("Invalid input", nextDate(13, 5, 1999));
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
    EXPECT_EQ("4/23/2004", nextDate(4, 22, 2004));
    EXPECT_EQ("6/11/2004", nextDate(6, 10, 2004));
    EXPECT_EQ("9/15/2004", nextDate(9, 14, 2004));
    EXPECT_EQ("11/30/2004", nextDate(11, 29, 2004));
    EXPECT_EQ("2/1/2004", nextDate(1, 31, 2004));
    EXPECT_EQ("1/29/2004", nextDate(1, 28, 2004));
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
