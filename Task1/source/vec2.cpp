#include "vec2.h"

vec2 vec2::operator-(const vec2& other) const {
	return { x - other.x, y - other.y };
}