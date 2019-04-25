#include "AABB.h"

namespace engine { namespace graph {

	AABB::AABB(float x, float y, float z, glm::vec3 scale)
	{
		m_X = x;
		m_Y = y;
		m_Z = z;
		m_Scale = scale;
	}

	bool AABB::contains(float x2, float y2, float z2, glm::vec3 scale2)
	{
		bool contains = !(m_X + m_Scale.x < x2 || x2 + scale2.x < m_X ||
			              m_Y + m_Scale.y < y2 || y2 + scale2.y < m_Y ||
			              m_Z + m_Scale.z < z2 || z2 + scale2.z < m_Z);
		return contains;
	}

	AABB::~AABB()
	{

	}

} }
