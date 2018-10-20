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
				return texturedModel;
			}

			Entity::~Entity()
			{

			}
		}
	}
}
