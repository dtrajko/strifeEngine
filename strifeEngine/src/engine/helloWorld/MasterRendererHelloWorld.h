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
			// void init(IScene * scene);
			glm::mat4 getProjectionMatrix();
			void prepare();
			// void render(Window * window, IScene * scene);
			void cleanUp();
			virtual ~MasterRendererHelloWorld();
		};
	}
}
