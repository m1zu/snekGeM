#include "Goal.h"
#include "Board.h"


Goal::Goal(const Snake& snake)
	:
	loc(0, 0),
	c(255, 0, 0),
	rng(std::random_device()()),
	xDist(0, Board::GetWidth()-1),
	yDist(0, Board::GetHeight()-1)
{
	Placement(snake);
}

void Goal::Placement(const Snake & snake)
{
	bool  isPlacedOnSnake = false;
	do {
		bool isPlacedOnSnake = false;
		loc.x = xDist(rng);
		loc.y = yDist(rng);
		for (int i = 0; i < snake.GetnSegmentsUsed(); ++i) {
			if (loc == snake.GetSegmentLocation(i))
				isPlacedOnSnake = true;
		}
	} while (isPlacedOnSnake);
}

void Goal::Draw(const Board& brd) const
{
	brd.DrawCell(loc, c);
}

bool Goal::isEatenAndReposition(const Snake & snake)
{
	bool isEaten = false;
	for (int i = 0; i < snake.GetnSegmentsUsed(); ++i) {
		if (loc == snake.GetSegmentLocation(i))
		{
			isEaten = true;
			Placement(snake);
			break;
		}
	}
	return isEaten;
}