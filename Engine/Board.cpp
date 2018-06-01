#include "Board.h"
#include <assert.h>

Board::Board(Graphics & gfx)
	:
	gfx(gfx)
{
	assert((Graphics::ScreenWidth - 2 * borderWidth) % dimension == 0);
	assert((Graphics::ScreenHeight - 2 * borderWidth) % dimension == 0);
}

void Board::DrawCell(const Location & loc, Color c) const
{
	assert(loc.x >= 0);
	assert(loc.x < width);
	assert(loc.y >= 0);
	assert(loc.y < height);
	gfx.DrawRectangleBorderless(loc.x*dimension + borderWidth, loc.y*dimension + borderWidth, dimension, dimension, c);
}

void Board::DrawBorder() const
{
	gfx.DrawRectanglePoints(borderWidth * 3 / 4, borderWidth * 3 / 4, gfx.ScreenWidth-borderWidth*3/4, borderWidth, Colors::MakeRGB(0,0,100));
	gfx.DrawRectanglePoints(borderWidth * 3 / 4, gfx.ScreenHeight-borderWidth, gfx.ScreenWidth - borderWidth * 3 / 4, gfx.ScreenHeight- borderWidth*3/4, Colors::MakeRGB(0, 0, 100));
	gfx.DrawRectanglePoints(borderWidth * 3 / 4, borderWidth, borderWidth, gfx.ScreenHeight - borderWidth, Colors::MakeRGB(0, 0, 100));
	gfx.DrawRectanglePoints(gfx.ScreenWidth - borderWidth, borderWidth, gfx.ScreenWidth - borderWidth*3/4, gfx.ScreenHeight - borderWidth, Colors::MakeRGB(0, 0, 100));
}

