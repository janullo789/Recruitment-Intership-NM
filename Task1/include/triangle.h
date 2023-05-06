#include <array>

#include "vec2.h"

struct triangle {
	std::array<vec2, 3> points;
};

float crossProduct(const vec2& a, const vec2& b);
bool sameSide(vec2 p1, vec2 p2, vec2 a, vec2 b);
bool isColliding(const triangle& t1, const triangle& t2);
