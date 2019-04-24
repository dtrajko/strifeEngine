#include "CameraStandalone.h"

namespace engine
{
	namespace tm
	{
		namespace entities
		{
			CameraStandalone::CameraStandalone()
			{
				speed = 0.4f;
			}

			void CameraStandalone::move(Window * window)
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

			glm::vec3 CameraStandalone::calculateNewPosition(float offsetX, float offsetY, float offsetZ) {
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

			glm::mat4 CameraStandalone::getViewMatrix()
			{
				return Maths::createViewMatrix(this);
			}

			glm::vec3 CameraStandalone::getPosition()
			{
				return m_Position;
			}

			void CameraStandalone::setPosition(float x, float y, float z)
			{
				m_Position.x = x;
				m_Position.y = y;
				m_Position.z = z;
			}

			void CameraStandalone::setRotation(float rx, float ry, float rz)
			{
				m_Pitch = rx;
				m_Yaw   = ry;
				m_Roll  = rz;
			}

			glm::vec3 CameraStandalone::getRotation()
			{
				return glm::vec3(m_Pitch, m_Yaw, m_Roll);
			}

			glm::mat4 CameraStandalone::updateViewMatrix()
			{
				return Maths::createViewMatrix(this);
			}

			float CameraStandalone::getPitch()
			{
				return m_Pitch;
			}

			float CameraStandalone::getYaw()
			{
				return m_Yaw;
			}

			float CameraStandalone::getRoll()
			{
				return m_Roll;
			}

			void CameraStandalone::invertPitch()
			{
				m_Pitch = -m_Pitch;
			}

			void CameraStandalone::invertRoll()
			{
				m_Roll = -m_Roll;
			}

			CameraStandalone::~CameraStandalone()
			{

			}
		}
	}
}
