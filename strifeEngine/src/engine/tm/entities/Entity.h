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
				glm::vec3 m_Rotation;
				glm::vec3 m_Velocity; // physics
				float m_Mass; // kg physics
				glm::vec3 m_Scale;
				bool solid;
				unsigned int m_TextureIndex = 0;
				AABB * m_AABB;
				Entity * m_EntityAABB = nullptr;

			public:
				Entity(TexturedModel* model, glm::vec3 position, glm::vec3 rotation, glm::vec3 scale);
				Entity(TexturedModel* model, unsigned int textureIndex, glm::vec3 position, glm::vec3 rotation, glm::vec3 scale);
				void increasePosition(glm::vec3 positionDelta);
				void increaseRotation(glm::vec3 rotationDelta);
				glm::vec3 getPosition();
				glm::vec3 getRotation();
				glm::vec3 getScale();
				void setPosition(glm::vec3 position);
				TexturedModel * getTexturedModel();
				float getTextureOffsetX();
				float getTextureOffsetY();
				void setAABB();
				AABB * getAABB();
				void setEntityAABB(Entity * entityAABB);
				Entity * getEntityAABB();
				virtual ~Entity();
			};
		}
	}
}
