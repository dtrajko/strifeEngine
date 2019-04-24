#include "AABB.h"

namespace engine { namespace graph {

	AABB::AABB(float x, float y, float z, float scale)
	{
		m_X = x;
		m_Y = y;
		m_Z = z;
		m_Scale = scale;
	}

	bool AABB::contains(float x2, float y2, float z2)
	{
		bool contains = 
			x2 > m_X && x2 <= m_X + m_Scale &&
			y2 > m_Y && y2 <= m_Y + m_Scale &&
			z2 > m_Z && z2 <= m_Z + m_Scale;
		return contains;
	}

	AABB::~AABB()
	{

	}

} }
