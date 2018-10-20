#pragma once

#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
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
			class Camera : public ICamera
			{
			private:
				glm::vec3 position = glm::vec3(0.0f, 0.0f, 0.0f);
				float pitch = 0;
				float yaw = 0;
				float roll = 0;
				glm::mat4 projectionMatrix;
				glm::mat4 viewMatrix;
			public:
				Camera();
				void move(Window * window, Input * input);
				glm::vec3 getPosition();
				glm::vec3 getRotation();
				glm::mat4 getViewMatrix();
				glm::mat4 updateViewMatrix();
				float getPitch();
				float getYaw();
				float getRoll();
				~Camera();
			};
		}
	}
}
