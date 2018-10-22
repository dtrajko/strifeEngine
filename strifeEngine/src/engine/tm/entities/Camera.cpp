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

			void Camera::move(Window * window)
			{

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
