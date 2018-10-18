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

			glm::mat4 Camera::getViewMatrix()
			{
				return Maths().createViewMatrix(this);
			}

			glm::vec3 Camera::getPosition()
			{
				return glm::vec3();
			}

			glm::vec3 Camera::getRotation()
			{
				return glm::vec3();
			}

			glm::mat4 Camera::updateViewMatrix()
			{
				return glm::mat4();
			}

			glm::mat4 Camera::getProjectionViewMatrix()
			{
				return glm::mat4();
			}

			float Camera::getPitch()
			{
				return 0.0f;
			}

			Camera::~Camera()
			{

			}
		}
	}
}
