#pragma once

#include "../interfaces/IGameLogic.h"

namespace engine
{
	namespace helloWorld
	{
		class HelloWorld : public engine::interfaces::IGameLogic
		{
		public:
			HelloWorld();
			virtual ~HelloWorld();
		};
	}
}
