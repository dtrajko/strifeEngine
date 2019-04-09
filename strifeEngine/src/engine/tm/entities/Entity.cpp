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
				position = _position;
				rotX = _rotX;
				rotY = _rotY;
				rotZ = _rotZ;
				scale = _scale;
				solid = false;
			}

			Entity::Entity(TexturedModel * model, unsigned int textureIndex, glm::vec3 _position, float _rotX, float _rotY, float _rotZ, float _scale):
				Entity(model, _position, _rotX, _rotY, _rotZ, _scale)
			{
				m_TextureIndex = textureIndex;
			}

			void Entity::increasePosition(float dx, float dy, float dz)
			{
				position.x += dx;
				position.y += dy;
				position.z += dz;
			}

			void Entity::increaseRotation(float dx, float dy, float dz)
			{
				rotX += dx;
				rotY += dy;
				rotZ += dz;
			}

			glm::vec3 Entity::getPosition()
			{
				return position;
			}

			void Entity::setPosition(glm::vec3 _position)
			{
				position = _position;
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
				return scale;
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

			Entity::~Entity()
			{

			}
		}
	}
}
