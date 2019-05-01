#ifndef _RIGID_BODY_H
#define _RIGID_BODY_H

#include "../../vendor/glm/glm.hpp"

namespace engine { namespace components {

	class RigidBody
	{
	private:
		float m_Mass;
		glm::vec3 m_Gravity;

	public:
		RigidBody(float mass, glm::vec3 gravity);
		~RigidBody();
	};

} }

#endif
