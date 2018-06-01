#pragma once
class Location
{
public:
	Location();
	Location(int in_x, int in_y);
	bool operator==(const Location& rhs);

	void Add(const Location& in_loc);
	bool isZero() const;
	bool isReverseDirection(const Location& inital_delta) const;

public:
	int x;
	int y;
};

