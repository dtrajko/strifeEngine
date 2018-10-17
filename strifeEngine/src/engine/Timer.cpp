#include "Timer.h"

namespace engine
{
	Timer::Timer()
	{

	}

	void Timer::init()
	{
		lastLoopTime = getTime();
	}

	double Timer::getTime()
	{
		time_t seconds;
		seconds = time(NULL);
		return (double) seconds;
	}

	float Timer::getElapsedTime()
	{
		double time = getTime();
		float elapsedTime = (float) (time - lastLoopTime);
		lastLoopTime = time;
		return elapsedTime;
	}

	double Timer::getLastLoopTime()
	{
		return lastLoopTime;
	}

	Timer::~Timer()
	{

	}
}
