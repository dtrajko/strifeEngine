#ifndef _AABB_H
#define _AABB_H

#include <iostream>
#include "../../vendor/glm/glm.hpp"

namespace engine { namespace graph {

	class AABB
	{
	public:
		float m_X = 0;
		float m_Y = 0;
		float m_Z = 0;
		glm::vec3 m_Scale = glm::vec3(1);

	private:

	public:
		AABB(float x, float y, float z, glm::vec3 scale);
		bool contains(float x2, float y2, float z2, glm::vec3 scale2);
		virtual ~AABB();

	};
	
} }

#endif
