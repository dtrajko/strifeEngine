#pragma once

#include "../../engine/Window.h"
#include "../../engine/graph/Input.h"
#include "../../vendor/glm/glm.hpp"
#include "../../vendor/glm/gtc/matrix_transform.hpp"

using namespace engine;
using namespace engine::graph;

namespace engine
{
	namespace interfaces
	{
		class ICamera
		{
		public:
			virtual void move(Window * window, Input * input) = 0;
			virtual glm::vec3 getPosition() = 0;
			virtual glm::vec3 getRotation() = 0;
			virtual glm::mat4 getViewMatrix() = 0;
			virtual glm::mat4 updateViewMatrix() = 0;
			virtual float getPitch() = 0;
			virtual float getYaw() = 0;
			virtual float getRoll() = 0;
		};
	}
}
