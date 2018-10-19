#pragma once

#include "IScene.h"
#include "../../engine/Window.h"
#include "../../vendor/glm/glm.hpp"
#include "../../vendor/glm/gtc/matrix_transform.hpp"

namespace engine
{
	namespace interfaces
	{
		class IMasterRenderer
		{
		protected:
			float FOV = 70; // field of view angle
			float NEAR_PLANE = 1.0f;
			float FAR_PLANE = 3000;
			float RED = 0.832f;
			float GREEN = 0.961f;
			float BLUE = 0.996f;

		public:
			virtual void init(IScene * scene) = 0;
			virtual glm::mat4 getProjectionMatrix(Window * window) = 0;
			virtual void prepare(Window * window) = 0;
			virtual void render(Window * window, IScene * scene) = 0;
			virtual void cleanUp() = 0;
		};
	}
}
