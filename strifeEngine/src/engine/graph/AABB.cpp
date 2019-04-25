#include "AABB.h"

namespace engine { namespace graph {

	AABB::AABB(float x, float y, float z, float scale)
	{
		m_X = x;
		m_Y = y;
		m_Z = z;
		m_Scale = scale;
	}

	bool AABB::contains(float x2, float y2, float z2, float scale2)
	{
		bool contains = !(m_X + m_Scale < x2 || x2 + scale2 < m_X ||
			              m_Y + m_Scale < y2 || y2 + scale2 < m_Y ||
			              m_Z + m_Scale < z2 || z2 + scale2 < m_Z);
		return contains;
	}

	AABB::~AABB()
	{

	}

} }
