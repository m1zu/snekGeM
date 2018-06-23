#include "PoisonField.h"
#include "Snake.h"

Poisionfield::Poisionfield(Board& brd)
	:
	brd(brd)
{
	for(int i=0; i< nPoisonGrids; ++i)
		poisonField[brd.GetRandom_1Dmapped_gridPos()]=true;
}

bool Poisionfield::collisionWith(const Snake & snake)
{
	const int snake1DmappedPos = snake.GetSegmentLocation(0).y*brd.width + snake.GetSegmentLocation(0).x;
	return poisonField[snake1DmappedPos];
}

void Poisionfield::Draw(const Board & brd)
{
	for (int i = 0; i < nMappedGrid; ++i)
		if(poisonField[i])
			brd.DrawCell(Location(i%brd.width, i / brd.width), Colors::MakeRGB(100, 20, 100));
}
