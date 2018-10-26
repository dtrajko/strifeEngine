#include "Maths.h"

namespace engine
{
	namespace tm
	{
		namespace toolbox
		{
			glm::mat4 Maths::createTransformationMatrix(glm::vec3 translation, float rotX, float rotY, float rotZ, float scale)
			{
				glm::mat4 matrix;
				matrix = glm::translate(matrix, translation);
				matrix = glm::rotate(matrix, glm::radians(rotX), glm::vec3(1, 0, 0));
				matrix = glm::rotate(matrix, glm::radians(rotY), glm::vec3(0, 1, 0));
				matrix = glm::rotate(matrix, glm::radians(rotZ), glm::vec3(0, 0, 1));
				matrix = glm::scale(matrix, glm::vec3(scale, scale, scale));
				return matrix;
			}

			glm::mat4 Maths::createViewMatrix(ICamera * camera)
			{
				glm::mat4 viewMatrix;
				viewMatrix = glm::rotate(viewMatrix, glm::radians(camera->getPitch()), glm::vec3(1, 0, 0));
				viewMatrix = glm::rotate(viewMatrix, glm::radians(camera->getYaw()),   glm::vec3(0, 1, 0));
				viewMatrix = glm::rotate(viewMatrix, glm::radians(camera->getRoll()),  glm::vec3(0, 0, 1));
				glm::vec3 cameraPos = camera->getPosition();
				glm::vec3 negativeCameraPos = glm::vec3(-cameraPos.x, -cameraPos.y, -cameraPos.z);
				viewMatrix = glm::translate(viewMatrix, negativeCameraPos);
				return viewMatrix;
			}
		}
	}
}
