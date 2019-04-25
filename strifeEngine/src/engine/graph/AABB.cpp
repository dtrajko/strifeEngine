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
		// std::cout << "AABB::contains: " << std::endl;
		// std::cout << "Player X: " << m_X << " Y: " << m_Y << " Z: " << m_Z << " Scale: " << m_Scale << std::endl;
		// std::cout << "Entity X: " << x2 << " Y: " << y2 << " Z: " << z2 << std::endl;
		// std::cout << "Result " << contains << std::endl;
		return contains;
	}

	AABB::~AABB()
	{

	}

} }
