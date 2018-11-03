#pragma once

#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "../loaders/Loader.h"
#include "../entities/Entity.h"
#include "../../interfaces/ICamera.h"
#include "../../graph/Window.h"
#include "../../graph/Input.h"
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
				const float cursorSensitivity = 0.2f;
				glm::vec3 m_Position = glm::vec3(0.0f, 0.0f, 0.0f);
				float pitch = 0;
				float yaw = 0;
				float roll = 0;
				glm::mat4 projectionMatrix;
				glm::mat4 viewMatrix;
				glm::vec3 cameraInc;
				glm::vec2 displVector;
				float speed;
			public:
				Camera();
				void move(Window * window);
				void setPosition(float x, float y, float z);
				void setRotation(float rx, float ry, float rz);
				glm::vec3 getPosition();
				glm::vec3 getRotation();
				glm::mat4 getViewMatrix();
				glm::mat4 updateViewMatrix();
				glm::vec3 calculateNewPosition(float offsetX, float offsetY, float offsetZ);
				float getPitch();
				float getYaw();
				float getRoll();
				~Camera();
			};
		}
	}
}
