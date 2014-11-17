#include "triangle.h"
#include <string>
using std::string;

string checkTriangleType(int a, int b, int c) {
    string triangle_type;

    if ((a < 1 || a > 200) || (b < 1 || b > 200) || (c < 1 || c > 200)) {
        triangle_type = "Invalid input";
    } else if ((a + b <= c) || (a + c <= b) || (b + c <= a)) {
        triangle_type = "Not a triangle";
    } else if ((a == b) && (a == c)) {
        triangle_type = "Equilateral";
    } else if ((a != b) && (a != c) && (b != c)) {
        triangle_type = "Scalene";
    } else {
        triangle_type = "Isosceles";
    }

    return triangle_type.c_str();
}

