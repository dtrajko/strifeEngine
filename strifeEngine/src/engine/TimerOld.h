#pragma once

#include <stdio.h>
#include <time.h>

namespace engine
{
	class TimerOld
	{
	private:
		static double lastLoopTime;

	public:
		TimerOld();
		static float getElapsedTime();
		static double getTime();
		void init();
		double getLastLoopTime();
		virtual ~TimerOld();
	};
}
