#pragma once

// #include "IScene.h"
#include "../../engine/Window.h"
#include "../../vendor/glm/glm.hpp"
#include "../../vendor/glm/gtc/matrix_transform.hpp"

namespace engine
{
	namespace interfaces
	{
		class IMasterRenderer
		{
		public:
			// virtual void init(IScene * scene) = 0;
			virtual glm::mat4 getProjectionMatrix() = 0;
			virtual void prepare() = 0;
			// virtual void render(Window * window, engine::interfaces::IScene * scene) = 0;
			virtual void cleanUp() = 0;
		};
	}
}
