#pragma once

#include "Location.h"
#include "Colors.h"
#include "Board.h"

class Snake
{
public:
	Snake();
	void Init(const Location& in_loc, int nStartSegments);
	void Draw(Board& brd);
	void Update(bool up, bool down, bool left, bool right);
	bool IsSelfColliding() const;
	Location GetMovementDirection() const;
	void Grow();
	
	int GetnSegmentsUsed() const;
	Location GetSegmentLocation(int i) const;

private:
	class Segment
	{
	public:
		void Init(const Location& in_loc,const Color c);
		void Draw(Board& brd);
		Location GetLocation() const;
		void MoveBy(const Location& in_loc);
		void Follow(const Location& destination);
		void GridBorderTransition();
	private:
		Location loc;
		Color c;
	};

private:
	bool initialized = false;
	static constexpr int nSegmentsMax = 100;
	Segment segment[nSegmentsMax];
	int nSegmentsUsed;
	Location delta_stored;
	Color colorSequence[4];
};

