#pragma once

#include "Graphics.h"
#include "Location.h"

class Board
{
public:
	Board(Graphics& gfx);
	void DrawCell(const Location& loc, Color c) const;
	void DrawBorder() const;

private:
	static constexpr int dimension = 20;
	static constexpr int borderWidth = 60;

public:
	static constexpr int width = (Graphics::ScreenWidth - 2 * borderWidth) / dimension;
	static constexpr int height = (Graphics::ScreenHeight - 2 * borderWidth) / dimension;

private:
	Graphics & gfx;
};

