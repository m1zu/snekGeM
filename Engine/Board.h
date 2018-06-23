#pragma once

#include "Graphics.h"
#include "Location.h"
#include <random>

class Board
{
public:
	Board(Graphics& gfx);
	void DrawCell(const Location& loc, Color c) const;
	void DrawBorder() const;
	int GetRandom_1Dmapped_gridPos();

private:
	static constexpr int dimension = 20;
	static constexpr int borderWidth = 60;

public:
	static constexpr int width = (Graphics::ScreenWidth - 2 * borderWidth) / dimension;
	static constexpr int height = (Graphics::ScreenHeight - 2 * borderWidth) / dimension;

private:
	Graphics & gfx;

	std::mt19937 rng;
	std::uniform_int_distribution<int> oneDimMappedGridDist;
};

