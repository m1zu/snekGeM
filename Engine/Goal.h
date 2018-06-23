#pragma once

#include "Location.h"
#include "Snake.h"
#include "Board.h"
#include <random>

class Goal
{
public:
	Goal(const Snake& snake, Board& brd);
	void Draw(const Board& brd) const;
	bool isEatenAndReposition(const Snake& snake);

private:
	void Placement(const Snake& snake);

private:
	Board& brd;
	Location loc;
	Color c;
};

