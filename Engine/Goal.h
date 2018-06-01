#pragma once

#include "Location.h"
#include "Snake.h"
#include <random>

class Goal
{
public:
	Goal(const Snake& snake);
	void Draw(const Board& brd) const;
	bool isEatenAndReposition(const Snake& snake);

private:
	void Placement(const Snake& snake);

private:
	Location loc;
	Color c;
	std::mt19937 rng;
	std::uniform_int_distribution<int> xDist;
	std::uniform_int_distribution<int> yDist;
};

