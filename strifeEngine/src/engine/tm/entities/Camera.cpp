#include "Camera.h"

namespace engine
{
	namespace tm
	{
		namespace entities
		{
			Camera::Camera()
			{
				speed = 0.4f;
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

				if (input->isKeyDown(GLFW_KEY_E) || input->isKeyDown(GLFW_KEY_SPACE)) {
				    m_Position.y += 0.1f;
				}
				if (input->isKeyDown(GLFW_KEY_LEFT_SHIFT)) {
					m_Position.y += -0.1f;
				}

				glm::vec2 rotVec = input->getDisplayVector();
				m_Pitch += rotVec.x * cursorSensitivity;
				m_Yaw += rotVec.y * cursorSensitivity;

				glm::vec3 newPos = calculateNewPosition(cameraInc.x, cameraInc.y, cameraInc.z);
				m_Position.x = newPos.x;
				m_Position.y = newPos.y;
				m_Position.z = newPos.z;

				updateViewMatrix();
			}

			glm::vec3 Camera::calculateNewPosition(float offsetX, float offsetY, float offsetZ) {
				glm::vec3 newPos = glm::vec3(m_Position.x, m_Position.y, m_Position.z);
				if (offsetZ != 0) {
					newPos.x += (float) glm::sin(glm::radians(m_Yaw)) * -1.0f * offsetZ;
					newPos.z += (float) glm::cos(glm::radians(m_Yaw)) * offsetZ;
				}
				if (offsetX != 0) {
					newPos.x += (float) glm::sin(glm::radians(m_Yaw - 90)) * -1.0f * offsetX;
					newPos.z += (float) glm::cos(glm::radians(m_Yaw - 90)) * offsetX;
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
				return m_Position;
			}

			void Camera::setPosition(float x, float y, float z)
			{
				m_Position.x = x;
				m_Position.y = y;
				m_Position.z = z;
			}

			void Camera::setRotation(float rx, float ry, float rz)
			{
				m_Pitch = rx;
				m_Yaw   = ry;
				m_Roll  = rz;
			}

			glm::vec3 Camera::getRotation()
			{
				return glm::vec3(m_Pitch, m_Yaw, m_Roll);
			}

			glm::mat4 Camera::updateViewMatrix()
			{
				return Maths::createViewMatrix(this);
			}

			float Camera::getPitch()
			{
				return m_Pitch;
			}

			float Camera::getYaw()
			{
				return m_Yaw;
			}

			float Camera::getRoll()
			{
				return m_Roll;
			}

			void Camera::invertPitch()
			{
				m_Pitch = -m_Pitch;
			}

			void Camera::invertRoll()
			{
				m_Roll = -m_Roll;
			}

			Camera::~Camera()
			{

			}
		}
	}
}
