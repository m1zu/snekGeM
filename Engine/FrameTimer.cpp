#include "FrameTimer.h"

FrameTimer::FrameTimer()
{
	timePoint = std::chrono::steady_clock::now();
}

const float FrameTimer::Mark()
{
	using namespace std::chrono;
	auto last = timePoint;
	timePoint = std::chrono::steady_clock::now();
	duration<float> time = timePoint - last;
	return time.count();
}
