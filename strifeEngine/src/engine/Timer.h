#pragma once

#include <stdio.h>
#include <time.h>

namespace engine
{
	class Timer
	{
	private:
		double lastLoopTime;

	public:
		Timer();
		void init();
		double getTime();
		float getElapsedTime();
		double getLastLoopTime();
		virtual ~Timer();
	};
}
