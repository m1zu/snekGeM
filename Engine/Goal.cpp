#include "Goal.h"
#include "Board.h"


Goal::Goal(const Snake& snake, Board& brd)
	:
	loc(0, 0),
	c(255, 0, 0),
	brd(brd)
{
	Placement(snake);
}

void Goal::Placement(const Snake & snake)
{
	bool  isPlacedOnSnake = false;
	do {
		bool isPlacedOnSnake = false;
		const int oneDimMappedLoc = brd.GetRandom_1Dmapped_gridPos();
		loc.x = oneDimMappedLoc%brd.width;
		loc.y = oneDimMappedLoc/brd.width;
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