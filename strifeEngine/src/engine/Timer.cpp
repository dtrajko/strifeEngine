#include "Timer.h"

using namespace engine;

double Timer::lastLoopTime;

namespace engine
{
	Timer::Timer()
	{
		lastLoopTime = getTime();
	}

	void Timer::init()
	{
		// lastLoopTime = getTime();
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
