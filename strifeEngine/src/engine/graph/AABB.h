#ifndef _AABB_H
#define _AABB_H

namespace engine { namespace graph {

	class AABB
	{
	public:
		float m_X = 0;
		float m_Y = 0;
		float m_Z = 0;
		float m_Scale = 1;

	private:

	public:
		AABB(float x, float y, float z, float scale);
		bool contains(float x2, float y2, float z2);
		virtual ~AABB();

	};
	
} }

#endif
