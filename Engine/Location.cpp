#include "Location.h"
#include <assert.h>
#include <cmath>


Location::Location()
{
}

Location::Location(int in_x, int in_y)
{
	x = in_x;
	y = in_y;
}

bool Location::operator==(const Location & rhs)
{
	return x==rhs.x && y==rhs.y;
}

void Location::Add(const Location& in_loc)
{
	assert(std::abs(in_loc.x) + std::abs(in_loc.y) == 1);
	this->x += in_loc.x;
	this->y += in_loc.y;
}

bool Location::isZero() const
{
	return x==0 && y==0;
}

bool Location::isReverseDirection(const Location& inital_delta) const
{
	return x == (-1)*inital_delta.x || y == (-1)*inital_delta.y;
}