#include "RigidBody.h"

namespace engine { namespace components {

	RigidBody::RigidBody(float mass, glm::vec3 gravity)
	{
		m_Mass = mass;
		m_Gravity = gravity;
	}

	RigidBody::~RigidBody()
	{

	}

} }
