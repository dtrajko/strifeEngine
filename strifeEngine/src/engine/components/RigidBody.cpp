#include "RigidBody.h"

namespace engine { namespace components {

	RigidBody::RigidBody(float mass, bool useGravity)
	{
		m_Mass = mass;
		m_UseGravity = useGravity;
	}

	RigidBody::~RigidBody()
	{

	}

} }
