#pragma once

#include "Graphics.h"
#include "Location.h"

class Board
{
public:
	Board(Graphics& gfx);
	void DrawCell(const Location& loc, Color c) const;
	void DrawBorder() const;

	static int GetWidth() { return width; };
	static int GetHeight() { return height; };
private:
	Graphics & gfx;
	static constexpr int dimension = 20;
	static constexpr int borderWidth = 60;
	static constexpr int width = (Graphics::ScreenWidth-2*borderWidth) / dimension;
	static constexpr int height = (Graphics::ScreenHeight-2*borderWidth) / dimension;
};

