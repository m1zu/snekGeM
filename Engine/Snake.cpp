#include "Snake.h"
#include "assert.h"

Snake::Snake()
	:
	delta_stored(1,0)
{
}

void Snake::Init(const Location & in_loc, int nStartSegments)
{
	assert(!initialized);
	initialized = true;
	assert(nStartSegments < 11);
	assert(in_loc.x >= nSegmentsUsed-1);

	colorSequence[0] = Colors::MakeRGB(0, 220, 0);
	colorSequence[1] = Colors::MakeRGB(0, 130, 0);
	colorSequence[2] = Colors::MakeRGB(0, 80, 0);
	colorSequence[3] = Colors::MakeRGB(0, 130, 0);
 	nSegmentsUsed = nStartSegments;

	Location temp = in_loc;
	Location degrade(-1, 0);
	segment[0].Init(temp, Colors::MakeRGB(255, 255, 0));
	temp.Add(degrade);
	for (int i = 1; i < nSegmentsUsed; ++i) {
		segment[i].Init(temp, colorSequence[i%4]);
		temp.Add(degrade);
	}
}

void Snake::Draw(Board & brd)
{
	assert(initialized);
	for (int i = 0; i < nSegmentsUsed; ++i) {
		segment[i].Draw(brd);
	}
}

void Snake::Update(bool up, bool down, bool left, bool right)
{
	assert(initialized);
	Location delta(0, 0);
	if (up) {
		delta.x = 0;
		delta.y = -1;
	}
	if (down) {
		delta.x = 0;
		delta.y = 1;
	}
	if (left) {
		delta.x = -1;
		delta.y = 0;
	}
	if (right) {
		delta.x = 1;
		delta.y = 0;
	}

	for (int i = nSegmentsUsed -1; i > 0; --i)
		segment[i].Follow(segment[i - 1].GetLocation());

	if (!delta.isZero() && !delta.isReverseDirection(delta_stored))
		delta_stored = delta;
	segment[0].MoveBy(delta_stored);
	segment[0].GridBorderTransition();
}

bool Snake::IsSelfColliding() const
{
	assert(initialized);
	bool collision = false;
	for (int i = 1; i < nSegmentsUsed; ++i)
		collision = collision || segment[0].GetLocation() == segment[i].GetLocation();
	return collision;
}

Location Snake::GetMovementDirection() const
{
	assert(initialized);
	return delta_stored;
}

void Snake::Grow()
{
	assert(initialized);
	if (nSegmentsUsed < nSegmentsMax) {
		nSegmentsUsed++;
		segment[nSegmentsUsed - 1].Init(Location(0, 0), colorSequence[(nSegmentsUsed - 1) % 4]);
	}
}

int Snake::GetnSegmentsUsed() const
{
	return nSegmentsUsed;
}

Location Snake::GetSegmentLocation(int i) const
{
	return segment[i].GetLocation();
}


void Snake::Segment::Init(const Location & in_loc, const Color in_c)
{
	loc = in_loc;
	c = in_c;
}

void Snake::Segment::Draw(Board & brd)
{
	brd.DrawCell(loc, c);
}

Location Snake::Segment::GetLocation() const
{
	return loc;
}

void Snake::Segment::MoveBy(const Location & in_loc)
{
	loc.Add(in_loc);
}

void Snake::Segment::Follow(const Location & destination)
{
	loc = destination;
}

void Snake::Segment::GridBorderTransition()
{
	if (loc.x < 0)
		loc.x = Board::width - 1;

	if (loc.x >= Board::width)
		loc.x = 0;

	if (loc.y < 0)
		loc.y = Board::height - 1;

	if (loc.y >= Board::height)
		loc.y = 0;
}
