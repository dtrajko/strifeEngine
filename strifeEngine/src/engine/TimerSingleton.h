#pragma once

#include <stdio.h>
#include <time.h>


class TimerSingleton
{
private:
	double lastLoopTime;

public:
	static TimerSingleton* get();

public:
	TimerSingleton();

	void init();
	double getTime();
	float getElapsedTime();
	double getLastLoopTime();

	virtual ~TimerSingleton();

};
