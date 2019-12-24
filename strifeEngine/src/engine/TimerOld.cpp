#include "TimerOld.h"

using namespace engine;

double TimerOld::lastLoopTime;

namespace engine
{
	TimerOld::TimerOld()
	{
		lastLoopTime = getTime();
	}

	void TimerOld::init()
	{
		// lastLoopTime = getTime();
	}

	double TimerOld::getTime()
	{
		time_t seconds;
		seconds = time(NULL);
		return (double) seconds;
	}

	float TimerOld::getElapsedTime()
	{
		double time = getTime();
		float elapsedTime = (float) (time - lastLoopTime);
		lastLoopTime = time;
		return elapsedTime;
	}

	double TimerOld::getLastLoopTime()
	{
		return lastLoopTime;
	}

	TimerOld::~TimerOld()
	{

	}
}
