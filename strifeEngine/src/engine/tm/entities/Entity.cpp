#include "Entity.h"

namespace engine
{
	namespace tm
	{
		namespace entities
		{
			Entity::Entity(TexturedModel* model, glm::vec3 position, float rotX, float rotY, float rotZ, glm::vec3 scale)
			{
				m_TexturedModel = model;
				m_Position = position;
				m_RotX = rotX;
				m_RotY = rotY;
				m_RotZ = rotZ;
				m_Scale = scale;
				solid = false;
			}

			Entity::Entity(TexturedModel * model, glm::vec3 position, float rotX, float rotY, float rotZ, float scale):
				Entity(model, position, rotX, rotY, rotZ, glm::vec3(scale, scale, scale))
			{
			}

			Entity::Entity(TexturedModel * model, unsigned int textureIndex, glm::vec3 position, float rotX, float rotY, float rotZ, float scale):
				Entity(model, position, rotX, rotY, rotZ, glm::vec3(scale, scale, scale))
			{
				m_TextureIndex = textureIndex;
			}

			void Entity::increasePosition(float dx, float dy, float dz)
			{
				m_Position.x += dx;
				m_Position.y += dy;
				m_Position.z += dz;

				if (m_EntityAABB != nullptr)
				{
					m_EntityAABB->increasePosition(dx, dy, dz);
				}
				setAABB();
			}

			void Entity::increaseRotation(float dx, float dy, float dz)
			{
				m_RotX += dx;
				m_RotY += dy;
				m_RotZ += dz;
			}

			glm::vec3 Entity::getPosition()
			{
				return m_Position;
			}

			void Entity::setPosition(glm::vec3 _position)
			{
				m_Position = _position;
			}

			float Entity::getRotX()
			{
				return m_RotX;
			}

			float Entity::getRotY()
			{
				return m_RotY;
			}

			float Entity::getRotZ()
			{
				return m_RotZ;
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
