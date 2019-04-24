#pragma once

#include "../../tm/models/TexturedModel.h"
#include "../../../vendor/glm/glm.hpp"
#include "../../../vendor/glm/gtc/matrix_transform.hpp"
#include "../../../engine/graph/AABB.h"

using namespace engine::tm::models;
using namespace engine::graph;

namespace engine
{
	namespace tm
	{
		namespace entities
		{
			class Entity
			{
			protected:
				TexturedModel * m_TexturedModel;
				glm::vec3 m_Position;
				float rotX;
				float rotY;
				float rotZ;
				float m_Scale;
				bool solid;
				unsigned int m_TextureIndex = 0;
				AABB * m_AABB;
				Entity * m_EntityAABB;

			public:
				Entity(TexturedModel * model, glm::vec3 _position, float _rotX, float _rotY, float _rotZ, float _scale);
				Entity(TexturedModel * model, unsigned int textureIndex, glm::vec3 _position, float _rotX, float _rotY, float _rotZ, float _scale);
				void increasePosition(float dx, float dy, float dz);
				void increaseRotation(float dx, float dy, float dz);
				glm::vec3 getPosition();
				void setPosition(glm::vec3 _position);
				float getRotX();
				float getRotY();
				float getRotZ();
				float getScale();
				TexturedModel * getTexturedModel();
				float getTextureOffsetX();
				float getTextureOffsetY();
				void setAABB();
				AABB* getAABB();
				virtual ~Entity();
			};
		}
	}
}
