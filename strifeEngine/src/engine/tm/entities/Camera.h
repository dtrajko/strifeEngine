#pragma once

#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "../../../engine/interfaces/ICamera.h"
#include "../../../engine/graph/Window.h"
#include "../../../engine/graph/Input.h"
#include "../../../engine/tm/loaders/Loader.h"
#include "../../../engine/tm/entities/Entity.h"
#include "../../../engine/tm/toolbox/Maths.h"
#include "../../../engine/tm/entities/Player.h"

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
				Player * m_Player = nullptr;
				float m_DistanceFromPlayer = -60.0f;
				float m_AngleAroundPlayer = 0.0f;
				float m_OffsetY = 20.0f;

				const float cursorSensitivity = 0.2f;
				glm::vec3 m_Position = glm::vec3(0.0f, 0.0f, 0.0f);
				float m_Pitch = 10;
				float m_Yaw = 0;
				float m_Roll = 0;
				glm::mat4 m_ProjectionMatrix;
				glm::mat4 m_ViewMatrix;
				glm::vec3 m_CameraInc;
				glm::vec2 m_DisplayVector;
				float m_Speed = 0.4f;
			public:
				Camera();
				void setPlayer(Player * player);
				void move(Window* window);
				void setPosition(float x, float y, float z);
				void setRotation(float rx, float ry, float rz);
				glm::vec3 getPosition();
				glm::vec3 getRotation();
				glm::mat4 getViewMatrix();
				glm::mat4 updateViewMatrix();
				float getPitch();
				float getYaw();
				float getRoll();
				void invertPitch();
				void invertRoll();
				~Camera();
			private:
				void moveWithPlayer(Window* window);
				void moveStandalone(Window* window);
				void calculateZoom(Input * input);
				void calculatePitch(Input * input);
				void calculateAngleAroundPlayer(Input * input);
				float calculateDistanceHorizontal();
				float calculateDistanceVertical();
				void calculateCameraPosition(float distanceHorizontal, float distanceVertical);
			};
		}
	}
}
