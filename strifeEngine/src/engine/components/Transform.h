#ifndef _TRANSFORM_H
#define _TRANSFORM_H

#include "../../vendor/glm/glm.hpp"

namespace engine { namespace components {

	class Transform
	{
	public:
		glm::vec3 m_Position;
		glm::vec3 m_Rotation;
		glm::vec3 m_Scale;

	public:
		Transform();
		Transform(glm::vec3 position, glm::vec3 rotation, glm::vec3 scale);
		~Transform();
	};

} }

#endif
