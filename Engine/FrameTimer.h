#pragma once

#include <chrono>

class FrameTimer {
	
public:
	FrameTimer();

	const float Mark();

private:
	std::chrono::steady_clock::time_point timePoint;
};