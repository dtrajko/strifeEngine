#include "TimerSingleton.h"

TimerSingleton::TimerSingleton()
{
	lastLoopTime = getTime();
}

TimerSingleton* TimerSingleton::get()
{
	static TimerSingleton timer;
	return &timer;
}

void TimerSingleton::init()
{
}

double TimerSingleton::getTime()
{
	time_t seconds;
	seconds = time(NULL);
	return (double)seconds;
}

float TimerSingleton::getElapsedTime()
{
	double time = getTime();
	float elapsedTime = (float)(time - lastLoopTime);
	lastLoopTime = time;
	return elapsedTime;
}

double TimerSingleton::getLastLoopTime()
{
	return lastLoopTime;
}

TimerSingleton::~TimerSingleton()
{

}
