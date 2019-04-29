#ifndef _RIGID_BODY_H
#define _RIGID_BODY_H

#include "../../vendor/glm/glm.hpp"

namespace engine { namespace components {

	class RigidBody
	{
	private:
		float m_Mass;
		bool m_UseGravity;

	public:
		RigidBody(float mass, bool useGravity);
		~RigidBody();
	};

} }

#endif
