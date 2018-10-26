#include "Light.h"

namespace engine
{
	namespace tm
	{
		namespace entities
		{
			Light::Light(glm::vec3 position, glm::vec3 color)
			{
				m_position = position;
				m_color = color;
				m_attenuation = glm::vec3(1, 0, 0);
			}

			Light::Light(glm::vec3 position, glm::vec3 color, glm::vec3 attenuation) : Light(position, color)
			{
				m_attenuation = attenuation;
			}

			void Light::setPosition(glm::vec3 position)
			{
				m_position = position;
			}

			void Light::setColor(glm::vec3 color)
			{
				m_color = color;
			}

			glm::vec3 Light::getAttenuation()
			{
				return m_attenuation;
			}

			glm::vec3 Light::getPosition()
			{
				return m_position;
			}

			glm::vec3 Light::getColor()
			{
				return m_color;
			}

			glm::vec2 Light::getLightBias()
			{
				return glm::vec2();
			}
			glm::vec3 Light::getDirection()
			{
				return glm::vec3();
			}
		}
	}
}
