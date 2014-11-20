#include "../../src/Triangle/triangle.h"
#include "gtest/gtest.h"

TEST(PathTest, C0)
{
    EXPECT_EQ("Equilateral", checkTriangleType(5, 5, 5));
    EXPECT_EQ("Isosceles", checkTriangleType(2, 2, 3));
    EXPECT_EQ("Scalene", checkTriangleType(3, 4, 5));
    EXPECT_EQ("Not a triangle", checkTriangleType(4, 1, 2));
    EXPECT_EQ("Invalid input", checkTriangleType(100, 202, 100));
}

TEST(PathTest, C1)
{
    EXPECT_EQ("Equilateral", checkTriangleType(5, 5, 5));
    EXPECT_EQ("Isosceles", checkTriangleType(2, 2, 3));
    EXPECT_EQ("Isosceles", checkTriangleType(2, 3, 2));
    EXPECT_EQ("Scalene", checkTriangleType(3, 4, 5));
    EXPECT_EQ("Not a triangle", checkTriangleType(4, 1, 2));
    EXPECT_EQ("Not a triangle", checkTriangleType(1, 4, 2));
    EXPECT_EQ("Not a triangle", checkTriangleType(2, 1, 4));
    EXPECT_EQ("Invalid input", checkTriangleType(0, 100, 100));
    EXPECT_EQ("Invalid input", checkTriangleType(100, 0, 100));
    EXPECT_EQ("Invalid input", checkTriangleType(100, 100, 0));
    EXPECT_EQ("Invalid input", checkTriangleType(201, 100, 100));
    EXPECT_EQ("Invalid input", checkTriangleType(100, 201, 100));
    EXPECT_EQ("Invalid input", checkTriangleType(100, 100, 201));
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
