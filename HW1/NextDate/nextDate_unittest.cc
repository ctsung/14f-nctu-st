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

TEST(EquivalenceClassTest, WeakNormal)
{
    EXPECT_EQ("6/15/2000", nextDate(6, 14, 2000));
    EXPECT_EQ("7/30/1996", nextDate(7, 29, 1996));
    EXPECT_EQ("Impossible date", nextDate(2, 30, 2002));
    EXPECT_EQ("Impossible date", nextDate(6, 31, 2000));
}

TEST(EquivalenceClassTest, WeakRobust)
{
    EXPECT_EQ("Invalid input", nextDate(1, 1, 1811));
    EXPECT_EQ("Invalid input", nextDate(1, 32, 1815));
    EXPECT_EQ("Invalid input", nextDate(13, 1, 2000));
    EXPECT_EQ("Invalid input", nextDate(0, 1, 2012));
}

TEST(EquivalenceClassTest, StrongNormal)
{
    EXPECT_EQ("6/15/2000", nextDate(6, 14, 2000));
    EXPECT_EQ("6/15/1996", nextDate(6, 14, 1996));
    EXPECT_EQ("6/15/2002", nextDate(6, 14, 2002));
    EXPECT_EQ("6/30/2000", nextDate(6, 29, 2000));
    EXPECT_EQ("6/30/1996", nextDate(6, 29, 1996));
    EXPECT_EQ("6/30/2002", nextDate(6, 29, 2002));
    EXPECT_EQ("7/1/2000", nextDate(6, 30, 2000));
    EXPECT_EQ("7/1/1996", nextDate(6, 30, 1996));
    EXPECT_EQ("7/1/2002", nextDate(6, 30, 2002));
    EXPECT_EQ("Impossible date", nextDate(6, 31, 2000));
    EXPECT_EQ("Impossible date", nextDate(6, 31, 1996));
    EXPECT_EQ("Impossible date", nextDate(6, 31, 2002));
}

TEST(EquivalenceClassTest, StrongRobust)
{
    EXPECT_EQ("Invalid input", nextDate(1, 0, 1811));
    EXPECT_EQ("Invalid input", nextDate(12, 32, 2013));
    EXPECT_EQ("Invalid input", nextDate(0, 1, 1818));
    EXPECT_EQ("Invalid input", nextDate(1, -1, 1999));
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
