#include "Camera.h"

namespace engine
{
	namespace tm
	{
		namespace entities
		{
			Camera::Camera()
			{
			}

			void Camera::moveWithPlayer(Window* window)
			{
				Input* input = window->getInput();
				m_DisplayVector = input->getDisplayVector();

				m_Pitch += m_DisplayVector.x * cursorSensitivity;
				m_Player->increaseRotation(glm::vec3(0, -m_DisplayVector.y * cursorSensitivity, 0));

				calculateZoom(input);
				calculatePitch(input);
				calculateAngleAroundPlayer(input);
				float distanceHorizontal = calculateDistanceHorizontal();
				float distanceVertical = calculateDistanceVertical();
				calculateCameraPosition(distanceHorizontal, distanceVertical);
				float theta = m_Player->getRotation().y + m_AngleAroundPlayer;
				m_Yaw = 360.0f - theta;
				updateViewMatrix();
			}

			void Camera::moveStandalone(Window * window)
			{
				Input * input = window->getInput();
				calculateZoom(input);
				calculatePitch(input);
				calculateAngleAroundPlayer(input);
				float distanceHorizontal = calculateDistanceHorizontal();
				float distanceVertical = calculateDistanceVertical();
				calculateCameraPosition(distanceHorizontal, distanceVertical);
				updateViewMatrix();
			}

			void Camera::move(Window* window)
			{
				moveWithPlayer(window);
			}

			void Camera::calculateCameraPosition(float distanceHorizontal, float distanceVertical)
			{
				float theta = m_Player->getRotation().y + m_AngleAroundPlayer;
				float offsetX = distanceHorizontal * glm::sin(glm::radians(theta));
				float offsetZ = distanceHorizontal * glm::cos(glm::radians(theta));
				m_Position.x = m_Player->getPosition().x - offsetX;
				m_Position.y = m_Player->getPosition().y + distanceVertical + m_OffsetY;
				m_Position.z = m_Player->getPosition().z - offsetZ;
			}

			float Camera::calculateDistanceHorizontal()
			{
				return m_DistanceFromPlayer * glm::cos(glm::radians(m_Pitch));
			}

			float Camera::calculateDistanceVertical()
			{
				return m_DistanceFromPlayer * glm::sin(glm::radians(m_Pitch));
			}

			void Camera::calculateZoom(Input * input)
			{
				float zoomLevel = (float) input->getMouseWheelDeltaY() * m_ZoomSpeed;
				m_DistanceFromPlayer -= zoomLevel;
			}

			/*
			 * #define GLFW_MOUSE_BUTTON_LEFT    GLFW_MOUSE_BUTTON_1
			 * #define GLFW_MOUSE_BUTTON_MIDDLE  GLFW_MOUSE_BUTTON_3
			 * #define GLFW_MOUSE_BUTTON_RIGHT   GLFW_MOUSE_BUTTON_2
			 */
			void Camera::calculatePitch(Input * input)
			{
				if (input->isMouseButtonPressed(2))
				{
					float pitchChange = input->getDisplayVector().y * 0.5f;
					m_Pitch -= pitchChange;
				}
			}

			/*
			 * #define GLFW_MOUSE_BUTTON_LEFT    GLFW_MOUSE_BUTTON_1
			 * #define GLFW_MOUSE_BUTTON_MIDDLE  GLFW_MOUSE_BUTTON_3
			 * #define GLFW_MOUSE_BUTTON_RIGHT   GLFW_MOUSE_BUTTON_2
			 */
			void Camera::calculateAngleAroundPlayer(Input * input)
			{
				if (input->isMouseButtonPressed(1))
				{
					float angleChange = input->getDisplayVector().x * 1.0f;
					m_AngleAroundPlayer -= angleChange;
				}
			}

			void Camera::setPlayer(Player * player)
			{
				m_Player = player;
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
