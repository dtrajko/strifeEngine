#include "Entity.h"

namespace engine
{
	namespace tm
	{
		namespace entities
		{
			Entity::Entity(TexturedModel * model, glm::vec3 _position, float _rotX, float _rotY, float _rotZ, float _scale)
			{
				texturedModel = model;
				position = _position;
				rotX = _rotX;
				rotY = _rotY;
				rotZ = _rotZ;
				scale = _scale;
				solid = false;
			}

			glm::vec3 Entity::getPosition()
			{
				return position;
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

			void Entity::setRotation(float _rotX, float _rotY, float _rotZ)
			{
				rotX = _rotX;
				rotY = _rotY;
				rotZ = _rotZ;
			}

			TexturedModel * Entity::getTexturedModel()
			{
				return texturedModel;
			}

			Entity::~Entity()
			{

			}
		}
	}
}
