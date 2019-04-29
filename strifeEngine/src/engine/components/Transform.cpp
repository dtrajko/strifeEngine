#include "Transform.h"

namespace engine { namespace components {

	Transform::Transform() : Transform(glm::vec3(0), glm::vec3(0), glm::vec3(1))
	{
	}

	Transform::Transform(glm::vec3 position, glm::vec3 rotation, glm::vec3 scale)
	{
		m_Position = position;
		m_Rotation = rotation;
		m_Scale    = scale;
	}

	Transform::~Transform()
	{

	}

} }
