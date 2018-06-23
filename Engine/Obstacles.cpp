#include "Obstacles.h"
#include "Snake.h"
#include "Location.h"
#include "Colors.h"

Obstacles::Obstacles()
	:
	rng(std::random_device()()),
	mappedGridTo1D(0, nMappedGrid)
{
}

void Obstacles::spawnObstacle(const Snake& snake)
{
	if (usedObstacles < maxObstacles)
	{
		int newObstaclePosition;
		int snakeHeadPositionMapped = snake.GetSegmentLocation(0).y * Board::width + snake.GetSegmentLocation(0).x;
		do {
			newObstaclePosition = mappedGridTo1D(rng);
		} while (snakeHeadPositionMapped == newObstaclePosition);

		obstacleGrid[newObstaclePosition] = true;
		usedObstacles++;
	}
}

bool Obstacles::collidingWith(const Snake & snake)
{
	int snakeHeadPositionMapped = snake.GetSegmentLocation(0).y * Board::width + snake.GetSegmentLocation(0).x;
	return obstacleGrid[snakeHeadPositionMapped];
}

void Obstacles::Draw(const Board & brd)
{
	for (int i = 0; i < nMappedGrid; ++i)
		if (obstacleGrid[i])
			brd.DrawCell(Location(i%Board::width, i/Board::width), Colors::Gray);
}
