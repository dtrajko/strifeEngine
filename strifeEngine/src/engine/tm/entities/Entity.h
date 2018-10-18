#pragma once

#include "../../tm/models/TexturedModel.h"
#include "../../../vendor/glm/glm.hpp"
#include "../../../vendor/glm/gtc/matrix_transform.hpp"

using namespace engine::tm::models;

namespace engine
{
	namespace tm
	{
		namespace entities
		{
			class Entity
			{
			public:
				Entity(TexturedModel * model, glm::vec3 position, float rotX, float rotY, float rotZ, float scale);
				virtual ~Entity();
			};
		}
	}
}
