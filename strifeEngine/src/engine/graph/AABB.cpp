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

	/*
	 * https://www.toptal.com/game/video-game-physics-part-ii-collision-detection-for-solid-objects
	 */
	bool AABB::testAABBOverlap(AABB * a, AABB * b)
	{
		float d1x = b->m_X - a->m_X + a->m_Scale.x;
		float d1y = b->m_Y - a->m_Y + a->m_Scale.y;
		float d1z = b->m_Z - a->m_Z + a->m_Scale.z;
		float d2x = a->m_X - b->m_X + b->m_Scale.x;
		float d2y = a->m_Y - b->m_Y + b->m_Scale.y;
		float d2z = a->m_Z - b->m_Z + b->m_Scale.z;

		if (d1x > 0.0f || d1y > 0.0f || d1z > 0.0f)
			return false;

		if (d2x > 0.0f || d2y > 0.0f || d2z > 0.0f)
			return false;

		return true;
	}

	AABB::~AABB()
	{

	}

} }
