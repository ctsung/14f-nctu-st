#include "Triangle.h"
#include "gtest/gtest.h"

TEST(BoundaryValueTest, Normal)
{
    EXPECT_STREQ("Isosceles", checkTriangleType(1, 100, 100));
    EXPECT_STREQ("Isosceles", checkTriangleType(2, 100, 100));
    EXPECT_STREQ("Isosceles", checkTriangleType(199, 100, 100));
    EXPECT_STREQ("Isosceles", checkTriangleType(100, 1, 100));
    EXPECT_STREQ("Isosceles", checkTriangleType(100, 2, 100));
    EXPECT_STREQ("Isosceles", checkTriangleType(100, 199, 100));
    EXPECT_STREQ("Isosceles", checkTriangleType(100, 100, 1));
    EXPECT_STREQ("Isosceles", checkTriangleType(100, 100, 2));
    EXPECT_STREQ("Isosceles", checkTriangleType(100, 100, 199));
    EXPECT_STREQ("Equilateral", checkTriangleType(100, 100, 100));
    EXPECT_STREQ("Not a triangle", checkTriangleType(100, 100, 200));
    EXPECT_STREQ("Not a triangle", checkTriangleType(100, 200, 100));
    EXPECT_STREQ("Not a triangle", checkTriangleType(200, 100, 100));
}

TEST(BoundaryValueTest, Robust)
{
    EXPECT_STREQ("Invalid input", checkTriangleType(0, 100, 100));
    EXPECT_STREQ("Invalid input", checkTriangleType(-1, 100, 100));
    EXPECT_STREQ("Invalid input", checkTriangleType(201, 100, 100));
    EXPECT_STREQ("Invalid input", checkTriangleType(202, 100, 100));
    EXPECT_STREQ("Invalid input", checkTriangleType(100, 0, 100));
    EXPECT_STREQ("Invalid input", checkTriangleType(100, -1, 100));
    EXPECT_STREQ("Invalid input", checkTriangleType(100, 201, 100));
    EXPECT_STREQ("Invalid input", checkTriangleType(100, 202, 100));
    EXPECT_STREQ("Invalid input", checkTriangleType(100, 100, 0));
    EXPECT_STREQ("Invalid input", checkTriangleType(100, 100, -1));
    EXPECT_STREQ("Invalid input", checkTriangleType(100, 100, 201));
    EXPECT_STREQ("Invalid input", checkTriangleType(100, 100, 202));
}

TEST(EquivalenceClassTest, WeakNormal)
{
    EXPECT_STREQ("Equilateral", checkTriangleType(5, 5, 5));
    EXPECT_STREQ("Isosceles", checkTriangleType(2, 2, 3));
    EXPECT_STREQ("Scalene", checkTriangleType(3, 4, 5));
    EXPECT_STREQ("Not a triangle", checkTriangleType(4, 1, 2));
}

TEST(EquivalenceClassTest, WeakRobust)
{
    EXPECT_STREQ("Invalid input", checkTriangleType(-1, 5, 5));
    EXPECT_STREQ("Invalid input", checkTriangleType(5, -1, 5));
    EXPECT_STREQ("Invalid input", checkTriangleType(5, 5, -1));
    EXPECT_STREQ("Invalid input", checkTriangleType(201, 5, 5));
    EXPECT_STREQ("Invalid input", checkTriangleType(5, 201, 5));
    EXPECT_STREQ("Invalid input", checkTriangleType(5, 5, 201));
}

TEST(EquivalenceClassTest, StrongNormal)
{
    EXPECT_STREQ("Equilateral", checkTriangleType(5, 5, 5));
    EXPECT_STREQ("Isosceles", checkTriangleType(2, 2, 3));
    EXPECT_STREQ("Scalene", checkTriangleType(3, 4, 5));
    EXPECT_STREQ("Not a triangle", checkTriangleType(4, 1, 2));
}

TEST(EquivalenceClassTest, StrongRobust)
{
    EXPECT_STREQ("Invalid input", checkTriangleType(-1, 5, 5));
    EXPECT_STREQ("Invalid input", checkTriangleType(5, -1, 5));
    EXPECT_STREQ("Invalid input", checkTriangleType(5, 5, -1));
    EXPECT_STREQ("Invalid input", checkTriangleType(-1, -1, 5));
    EXPECT_STREQ("Invalid input", checkTriangleType(-1, 5, -1));
    EXPECT_STREQ("Invalid input", checkTriangleType(5, -1, -1));
    EXPECT_STREQ("Invalid input", checkTriangleType(-1, -1, -1));
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
