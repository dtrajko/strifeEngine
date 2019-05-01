#pragma once

#include <stdio.h>
#include <time.h>

namespace engine
{
	class Timer
	{
	private:
		static double lastLoopTime;

	public:
		Timer();
		static float getElapsedTime();
		static double getTime();
		void init();
		double getLastLoopTime();
		virtual ~Timer();
	};
}
