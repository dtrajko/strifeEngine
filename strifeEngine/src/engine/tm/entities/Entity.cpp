#include "Entity.h"

namespace engine
{
	namespace tm
	{
		namespace entities
		{
			Entity::Entity(TexturedModel * model, glm::vec3 _position, float _rotX, float _rotY, float _rotZ, float _scale)
			{
				m_TexturedModel = model;
				m_Position = _position;
				rotX = _rotX;
				rotY = _rotY;
				rotZ = _rotZ;
				m_Scale = _scale;
				solid = false;
			}

			Entity::Entity(TexturedModel * model, unsigned int textureIndex, glm::vec3 _position, float _rotX, float _rotY, float _rotZ, float _scale):
				Entity(model, _position, _rotX, _rotY, _rotZ, _scale)
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
				rotX += dx;
				rotY += dy;
				rotZ += dz;
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
				return rotX;
			}

			float Entity::getRotY()
			{
				return rotY;
			}

			float Entity::getRotZ()
			{
				return rotZ;
			}

			float Entity::getScale()
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
				float scaleAABB = (m_EntityAABB != nullptr) ? m_EntityAABB->m_Scale : m_Scale;
				float topLeftX = m_Position.x - scaleAABB;
				float topLeftY = m_Position.y - scaleAABB;
				float topLeftZ = m_Position.z - scaleAABB;
				m_AABB = new AABB(topLeftX, topLeftY, topLeftZ, scaleAABB * 2);
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
