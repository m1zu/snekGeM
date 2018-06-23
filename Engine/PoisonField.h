#pragma once

#include "Board.h"
#include <random>

class Poisionfield {
public:
	Poisionfield(Board& brd);

	bool collisionWith(const class Snake& snake);
	void Draw(const Board& brd);

private:
	Board& brd;
	int nPoisonGrids = 200;
	static constexpr int nMappedGrid = Board::width*Board::height;
	bool poisonField[nMappedGrid] = { false };
};