#include "triangle.h"

// calculation of the cross product
float crossProduct(const vec2& a, const vec2& b)
{
    return a.x * b.y - a.y * b.x;
}

// checking if the points are opposite sides of a triangle
bool sameSide(vec2 p1, vec2 p2, vec2 a, vec2 b)
{
    float c1 = crossProduct(b - a, p1 - a);
    float c2 = crossProduct(b - a, p2 - a);
    return c1 * c2 >= 0;
}

bool isColliding(const triangle& t1, const triangle& t2)
{
    std::array<vec2, 5> temp1 = { t1.points[0], t1.points[1], t1.points[2], t1.points[0], t1.points[1] };
    std::array<vec2, 5> temp2 = { t2.points[0], t2.points[1], t2.points[2], t2.points[0], t2.points[1] };

    for (int i = 0; i < 3; ++i)
    {
        if (!sameSide(temp1[i], temp2[0], temp1[i + 1], temp1[i + 2]) &&
            sameSide(temp2[0], temp2[1], temp1[i + 1], temp1[i + 2]) &&
            sameSide(temp2[1], temp2[2], temp1[i + 1], temp1[i + 2]))
        {
            return false;
        }
    }

    for (int i = 0; i < 3; ++i)
    {
        if (!sameSide(temp2[i], temp1[0], temp2[i + 1], temp2[i + 2]) &&
            sameSide(temp1[0], temp1[1], temp2[i + 1], temp2[i + 2]) &&
            sameSide(temp1[1], temp1[2], temp2[i + 1], temp2[i + 2]))
        {
            return false;
        }
    }

    return true;
}