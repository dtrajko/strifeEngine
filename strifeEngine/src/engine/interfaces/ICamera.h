#pragma once

#include "../../vendor/glm/glm.hpp"
#include "../../vendor/glm/gtc/matrix_transform.hpp"

namespace engine
{
	namespace interfaces
	{
		class ICamera
		{
		public:
			virtual glm::mat4 getViewMatrix() = 0;
			virtual glm::vec3 getPosition() = 0;
			virtual glm::vec3 getRotation() = 0;
			virtual glm::mat4 updateViewMatrix() = 0;
			virtual float getPitch() = 0;
			virtual float getYaw() = 0;
			virtual float getRoll() = 0;
		};
	}
}
