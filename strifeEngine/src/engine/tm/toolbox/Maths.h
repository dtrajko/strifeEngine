#pragma once

#include "../../interfaces/ICamera.h"
#include "../../../vendor/glm/glm.hpp"
#include "../../../vendor/glm/gtc/matrix_transform.hpp"

using namespace engine::interfaces;

namespace engine
{
	namespace tm
	{
		namespace toolbox
		{
			class Maths
			{
			public:
				static glm::mat4 createViewMatrix(ICamera * camera)
				{
					return glm::mat4();
				}
			};
		}
	}
}
