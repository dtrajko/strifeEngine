#ifndef _LIGHT_H
#define _LIGHT_H

#include "../../../vendor/glm/glm.hpp"

namespace engine { namespace tm { namespace entities {

	class Light
	{
	private:
		glm::vec3 m_position;
		glm::vec3 m_color;
		glm::vec3 m_attenuation;

	public:
		Light(glm::vec3 position, glm::vec3 color);
		Light(glm::vec3 position, glm::vec3 color, glm::vec3 attenuation);
		void setPosition(glm::vec3 position);
		void setColor(glm::vec3 color);
		glm::vec3 getAttenuation();
		glm::vec3 getPosition();
		glm::vec3 getColor();
		glm::vec2 getLightBias();
		glm::vec3 getDirection();
	};
		
} } }

#endif
