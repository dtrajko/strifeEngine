#include "Player.h"

namespace engine { namespace tm { namespace entities {

	Player::Player(TexturedModel * model, glm::vec3 _position, float _rotX, float _rotY, float _rotZ, float _scale) :
		Entity(model, _position, _rotX, _rotY, _rotZ, _scale)
	{
	}

	void Player::move(float interval, Window* window, std::vector<Entity*> entities)
	{
		checkInputs(window);
		increaseRotation(0, m_CurrentTurnSpeed * 0.01f, 0);
		float distance = m_CurrentSpeed * -0.1f;
		float dx = (float)(distance * glm::sin(glm::radians(rotY)) + m_StrifeX);
		float dy = m_StrifeY;
		float dz = (float)(distance * glm::cos(glm::radians(rotY)) + m_StrifeZ);
		increasePosition(dx, dy, dz);
		if (inCollision(entities))
		{
			increasePosition(-dx, -dy, -dz);
		}
	}

	void Player::checkInputs(Window * window)
	{
		Input * input = window->getInput();
		m_CurrentSpeed = 0;
		if (input->isKeyDown(GLFW_KEY_W) || input->isKeyDown(GLFW_KEY_UP)) {
			m_CurrentSpeed = RUN_SPEED;
		}
		if (input->isKeyDown(GLFW_KEY_S) || input->isKeyDown(GLFW_KEY_DOWN)) {
			m_CurrentSpeed = -RUN_SPEED;
		}
		m_CurrentTurnSpeed = 0;
		if (input->isKeyDown(GLFW_KEY_D) || input->isKeyDown(GLFW_KEY_RIGHT)) {
			m_CurrentTurnSpeed = -TURN_SPEED;
		}
		if (input->isKeyDown(GLFW_KEY_A) || input->isKeyDown(GLFW_KEY_LEFT)) {
			m_CurrentTurnSpeed = TURN_SPEED;
		}
		m_StrifeX = 0;
		m_StrifeY = 0;
		m_StrifeZ = 0;
		if (input->isKeyDown(GLFW_KEY_Z))
		{
			m_StrifeX -= glm::cos(glm::radians(rotY));
			m_StrifeZ += glm::sin(glm::radians(rotY));
		}
		if (input->isKeyDown(GLFW_KEY_X))
		{
			m_StrifeX += glm::cos(glm::radians(rotY));
			m_StrifeZ -= glm::sin(glm::radians(rotY));
		}
		// vertical strife
		if (input->isKeyDown(GLFW_KEY_E) || input->isKeyDown(GLFW_KEY_SPACE)) {
			m_StrifeY = RUN_SPEED * 0.1f;
		}
		if (input->isKeyDown(GLFW_KEY_LEFT_SHIFT)) {
			m_StrifeY = -RUN_SPEED * 0.1f;
		}
	}

	bool Player::inCollision(std::vector<Entity*> entities)
	{
		for (Entity * entity : entities)
		{
			if (entity != this && entity->getEntityAABB() != nullptr && entity->getAABB() != nullptr)
			{
				AABB* entityAABB = entity->getAABB();
				if (m_AABB->contains(entityAABB->m_X, entityAABB->m_Y, entityAABB->m_Z))
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
