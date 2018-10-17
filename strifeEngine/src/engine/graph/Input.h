#pragma once

#include "../Window.h"

namespace engine
{
	namespace graph
	{
		class Input
		{
		public:
			Input(Window * window);
			virtual ~Input();
		};
	}
}
