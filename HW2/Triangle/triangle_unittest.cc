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

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
