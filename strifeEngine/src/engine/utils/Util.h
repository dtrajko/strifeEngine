#pragma once
#pragma warning(disable : 4996) //_CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <ctime>

namespace engine
{
	namespace utils
	{
		class Util
		{
		public:
			inline static char * printTime()
			{
				// Declaring argument for time() 
				time_t tt;

				// Declaring variable to store return value of 
				// localtime() 
				struct tm * ti;

				// Applying time() 
				time(&tt);

				// Using localtime() 
				ti = localtime(&tt);

				return asctime(ti);
			}
		};
	}
}
