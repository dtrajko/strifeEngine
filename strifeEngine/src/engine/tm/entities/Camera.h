#pragma once

#include "../../interfaces/ICamera.h"
#include "../../Window.h"
#include "../../graph/Input.h"
#include "../loaders/Loader.h"
#include "../entities/Entity.h"
#include "../../../engine/tm/toolbox/Maths.h"

using namespace engine;
using namespace engine::graph;
using namespace engine::interfaces;
using namespace engine::tm::loaders;
using namespace engine::tm::toolbox;

namespace engine
{
	namespace tm
	{
		namespace entities
		{
			class Camera : ICamera
			{
			private:
				glm::vec3 position;
				float pitch;
				float yaw;
				float roll;
				glm::mat4 projectionMatrix;
				glm::mat4 viewMatrix;
			public:
				Camera();
				glm::mat4 getViewMatrix();
				glm::vec3 getPosition();
				glm::vec3 getRotation();
				glm::mat4 updateViewMatrix();
				glm::mat4 getProjectionViewMatrix();
				float getPitch();
				~Camera();
			};
		}
	}
}
