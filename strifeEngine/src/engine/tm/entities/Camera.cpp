#include "Camera.h"

namespace engine
{
	namespace tm
	{
		namespace entities
		{
			Camera::Camera()
			{
				speed = 0.005f;
			}

			void Camera::move(Window * window)
			{
				Input * input = window->getInput();

				cameraInc = glm::vec3();

				if (input->isKeyDown(GLFW_KEY_A) || input->isKeyDown(GLFW_KEY_LEFT)) {
					cameraInc.x += -speed;
				}
				if (input->isKeyDown(GLFW_KEY_D) || input->isKeyDown(GLFW_KEY_RIGHT)) {
					cameraInc.x += +speed;
				}
				if (input->isKeyDown(GLFW_KEY_W) || input->isKeyDown(GLFW_KEY_UP)) {
					cameraInc.z += -speed;
				}
				if (input->isKeyDown(GLFW_KEY_S) || input->isKeyDown(GLFW_KEY_DOWN)) {
					cameraInc.z += +speed;
				}

				glm::vec2 rotVec = input->getDisplayVector();
				pitch += rotVec.x * cursorSensitivity;
				yaw += rotVec.y * cursorSensitivity;

				glm::vec3 newPos = calculateNewPosition(cameraInc.x, cameraInc.y, cameraInc.z);
				position.x = newPos.x;
				position.y = newPos.y;
				position.z = newPos.z;

				updateViewMatrix();
			}

			glm::vec3 Camera::calculateNewPosition(float offsetX, float offsetY, float offsetZ) {
				glm::vec3 newPos = glm::vec3(position.x, position.y, position.z);
				if (offsetZ != 0) {
					newPos.x += (float) glm::sin(glm::radians(yaw)) * -1.0f * offsetZ;
					newPos.z += (float) glm::cos(glm::radians(yaw)) * offsetZ;
				}
				if (offsetX != 0) {
					newPos.x += (float) glm::sin(glm::radians(yaw - 90)) * -1.0f * offsetX;
					newPos.z += (float) glm::cos(glm::radians(yaw - 90)) * offsetX;
				}
				newPos.y += offsetY;
				return newPos;
			}

			glm::mat4 Camera::getViewMatrix()
			{
				return Maths::createViewMatrix(this);
			}

			glm::vec3 Camera::getPosition()
			{
				return position;
			}

			glm::vec3 Camera::getRotation()
			{
				return glm::vec3(pitch, yaw, roll);
			}

			glm::mat4 Camera::updateViewMatrix()
			{
				return Maths::createViewMatrix(this);
			}

			float Camera::getPitch()
			{
				return pitch;
			}

			float Camera::getYaw()
			{
				return yaw;
			}

			float Camera::getRoll()
			{
				return roll;
			}

			Camera::~Camera()
			{

			}
		}
	}
}
