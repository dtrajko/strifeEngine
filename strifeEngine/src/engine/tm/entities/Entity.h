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
			private:
				TexturedModel * texturedModel;
				glm::vec3 position;
				float rotX;
				float rotY;
				float rotZ;
				float scale;
				bool solid;
				int textureIndex = 0;

			public:
				Entity(TexturedModel * model, glm::vec3 _position, float _rotX, float _rotY, float _rotZ, float _scale);
				void increasePosition(float dx, float dy, float dz);
				void increaseRotation(float dx, float dy, float dz);
				glm::vec3 getPosition();
				float getRotX();
				float getRotY();
				float getRotZ();
				float getScale();
				TexturedModel * getTexturedModel();
				virtual ~Entity();
			};
		}
	}
}
