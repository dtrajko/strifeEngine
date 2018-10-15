#pragma once

#include "../../engine/interfaces/IMasterRenderer.h"

using namespace engine::interfaces;

namespace engine
{
	namespace helloWorld
	{
		class MasterRendererHelloWorld : public IMasterRenderer
		{
		public:
			MasterRendererHelloWorld();
			virtual ~MasterRendererHelloWorld();
		};
	}
}
