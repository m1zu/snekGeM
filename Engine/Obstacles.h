#pragma once

#include "Board.h"
#include <random>

class Obstacles {

public:
	Obstacles();

	void spawnObstacle(const class Snake& snake);
	bool collidingWith(const class Snake& snake);
	void Draw(const Board& brd);

private:
	static constexpr int nMappedGrid = Board::width*Board::height;
	bool obstacleGrid[nMappedGrid] = { false };
	int maxObstacles = 30;
	int usedObstacles = 0;

	std::mt19937 rng;
	std::uniform_int_distribution<int> mappedGridTo1D;
};