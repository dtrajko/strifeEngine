#include "Entity.h"

namespace engine
{
	namespace tm
	{
		namespace entities
		{
			Entity::Entity(TexturedModel* model, glm::vec3 position, glm::vec3 rotation, glm::vec3 scale)
			{
				m_TexturedModel = model;
				m_Position = position;
				m_Rotation = rotation;
				m_Velocity = glm::vec3();
				m_Mass = 1.0f;
				m_Scale = scale;
				solid = false;
				setAABB();
			}

			Entity::Entity(TexturedModel * model, unsigned int textureIndex, glm::vec3 position, glm::vec3 rotation, glm::vec3 scale):
				Entity(model, position, rotation, scale)
			{
				m_TextureIndex = textureIndex;
			}

			void Entity::increasePosition(glm::vec3 positionDelta)
			{
				m_Position += positionDelta;

				if (m_EntityAABB != nullptr)
				{
					m_EntityAABB->increasePosition(positionDelta);
				}
				setAABB();
			}

			void Entity::increaseRotation(glm::vec3 rotationDelta)
			{
				m_Rotation += rotationDelta;
			}

			glm::vec3 Entity::getPosition()
			{
				return m_Position;
			}

			void Entity::setPosition(glm::vec3 position)
			{
				m_Position = position;

				if (m_EntityAABB != nullptr)
				{
					m_EntityAABB->setPosition(position);
				}
				setAABB();
			}

			glm::vec3 Entity::getRotation()
			{
				return m_Rotation;
			}

			glm::vec3 Entity::getScale()
			{
				return m_Scale;
			}

			TexturedModel * Entity::getTexturedModel()
			{
				return m_TexturedModel;
			}

			float Entity::getTextureOffsetX()
			{
				unsigned int column = m_TextureIndex % m_TexturedModel->getTexture()->getNumberOfRows();
				float offsetX = (float)column / (float)m_TexturedModel->getTexture()->getNumberOfRows();
				return offsetX;
			}

			float Entity::getTextureOffsetY()
			{
				unsigned int row = m_TextureIndex / m_TexturedModel->getTexture()->getNumberOfRows();
				float offsetY = (float)row / (float)m_TexturedModel->getTexture()->getNumberOfRows();
				return offsetY;
			}

			void Entity::setAABB()
			{
				glm::vec3 scaleAABB = (m_EntityAABB != nullptr) ? m_EntityAABB->m_Scale : m_Scale;
				float posX = (m_EntityAABB != nullptr) ? m_EntityAABB->m_Position.x : m_Position.x;
				float posY = (m_EntityAABB != nullptr) ? m_EntityAABB->m_Position.y : m_Position.y;
				float posZ = (m_EntityAABB != nullptr) ? m_EntityAABB->m_Position.z : m_Position.z;
				float topLeftX = posX - scaleAABB.x;
				float topLeftY = posY - scaleAABB.y;
				float topLeftZ = posZ - scaleAABB.z;
				m_AABB = new AABB(topLeftX, topLeftY, topLeftZ, glm::vec3(scaleAABB.x * 2, scaleAABB.y * 2, scaleAABB.z * 2));
			}

			AABB * Entity::getAABB()
			{
				if (m_AABB == nullptr)
				{
					setAABB();
				}
				return m_AABB;
			}

			void Entity::setEntityAABB(Entity* entityAABB)
			{
				m_EntityAABB = entityAABB;
				setAABB();
			}

			Entity * Entity::getEntityAABB()
			{
				return m_EntityAABB;
			}

			Entity::~Entity()
			{

			}
		}
	}
}
