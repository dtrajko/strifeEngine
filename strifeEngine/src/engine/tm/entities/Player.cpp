#include "Player.h"

namespace engine { namespace tm { namespace entities {

	Player::Player(TexturedModel * model, glm::vec3 position, glm::vec3 rotation, glm::vec3 scale) :
		Entity(model, position, rotation, scale)
	{
	}

	void Player::move(float interval, Window* window, std::vector<Entity*> entities)
	{
		checkInputs(window);
		increaseRotation(glm::vec3(0, m_CurrentTurnSpeed, 0));
		glm::vec3 positionDelta;
		positionDelta.x = (float)(m_ForwardSpeed * glm::sin(glm::radians(m_Rotation.y)) + m_StrafeX * glm::cos(glm::radians(m_Rotation.y)));
		positionDelta.y = m_VerticalSpeed;
		positionDelta.z = (float)(m_ForwardSpeed * glm::cos(glm::radians(m_Rotation.y)) + m_StrafeZ * glm::sin(glm::radians(m_Rotation.y)));
		increasePosition(positionDelta);
		if (inCollision(entities))
		{
			increasePosition(-positionDelta);
		}
	}

	void Player::checkInputs(Window * window)
	{
		Input * input = window->getInput();

		m_ForwardSpeed = 0;
		m_VerticalSpeed = 0;
		m_CurrentTurnSpeed = 0;
		m_StrafeX = 0;
		m_StrafeZ = 0;

		// forward / backward movement
		if (input->isKeyDown(GLFW_KEY_W) || input->isKeyDown(GLFW_KEY_UP)) {
			m_ForwardSpeed -= RUN_SPEED;
		}
		if (input->isKeyDown(GLFW_KEY_S) || input->isKeyDown(GLFW_KEY_DOWN)) {
			m_ForwardSpeed += RUN_SPEED;
		}

		// strafe left / right
		if (input->isKeyDown(GLFW_KEY_D)) {
			m_StrafeX += RUN_SPEED;
			m_StrafeZ -= RUN_SPEED;
		}
		if (input->isKeyDown(GLFW_KEY_A)) {
			m_StrafeX -= RUN_SPEED;
			m_StrafeZ += RUN_SPEED;
		}

		// vertical strafe
		if (input->isKeyDown(GLFW_KEY_E) || input->isKeyDown(GLFW_KEY_SPACE)) {
			m_VerticalSpeed += RUN_SPEED;
		}
		if (input->isKeyDown(GLFW_KEY_LEFT_SHIFT)) {
			m_VerticalSpeed -= RUN_SPEED;
		}

		// rotate left / right
		if (input->isKeyDown(GLFW_KEY_Z) || input->isKeyDown(GLFW_KEY_LEFT)) {
			m_CurrentTurnSpeed += TURN_SPEED;
		}
		if (input->isKeyDown(GLFW_KEY_X) || input->isKeyDown(GLFW_KEY_RIGHT)) {
			m_CurrentTurnSpeed -= TURN_SPEED;
		}
	}

	bool Player::inCollision(std::vector<Entity*> entities)
	{
		for (Entity * entity : entities)
		{
			if (entity != this && entity->getEntityAABB() != nullptr && entity->getAABB() != nullptr)
			{
				AABB* entityAABB = entity->getAABB();
				if (m_AABB->contains(entityAABB->m_X, entityAABB->m_Y, entityAABB->m_Z, entityAABB->m_Scale))
				{
					return true;
				}
			}
		}
		return false;
	}

	glm::vec3 Player::calculateNewPosition(glm::vec3 offset) {
		return glm::vec3();
	}

	void Player::update()
	{
	}

	Player::~Player()
	{

	}

} } }
