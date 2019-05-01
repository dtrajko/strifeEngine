#ifndef _TIME_H
#define _TIME_H

#include "../../vendor/glm/glm.hpp"

namespace engine { namespace components {

	class Time
	{
	private:
		float m_DeltaTime;

	public:
		Time();
		~Time();
	};

} }

#endif
