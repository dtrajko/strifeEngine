#include "Player.h"

namespace engine { namespace tm { namespace entities {

	Player::Player(ICamera * camera, Entity * entity) : m_Camera(camera), m_Entity(entity)
	{
		glm::vec3 camPos = m_Camera->getPosition();
		m_Entity->setPosition(camPos);
		m_Entity->increasePosition(0, -20.0f, -40.0f);
	}

	void Player::move(Window * window)
	{
		Input * input = window->getInput();

		m_PositionIncrement = glm::vec3();

		if (input->isKeyDown(GLFW_KEY_A) || input->isKeyDown(GLFW_KEY_LEFT)) {
			m_PositionIncrement.x += -m_Speed;
		}
		if (input->isKeyDown(GLFW_KEY_D) || input->isKeyDown(GLFW_KEY_RIGHT)) {
			m_PositionIncrement.x += +m_Speed;
		}
		if (input->isKeyDown(GLFW_KEY_W) || input->isKeyDown(GLFW_KEY_UP)) {
			m_PositionIncrement.z += -m_Speed;
		}
		if (input->isKeyDown(GLFW_KEY_S) || input->isKeyDown(GLFW_KEY_DOWN)) {
			m_PositionIncrement.z += +m_Speed;
		}

		if (input->isKeyDown(GLFW_KEY_E) || input->isKeyDown(GLFW_KEY_SPACE)) {
			m_Position.y += 0.1f;
		}
		if (input->isKeyDown(GLFW_KEY_LEFT_SHIFT)) {
			m_Position.y += -0.1f;
		}

		glm::vec2 rotVec = input->getDisplayVector();
		m_Pitch += rotVec.x * m_CursorSensitivity;
		m_Yaw += rotVec.y * m_CursorSensitivity;

		glm::vec3 newPos = calculateNewPosition(m_PositionIncrement);
		m_Position.x = newPos.x;
		m_Position.y = newPos.y;
		m_Position.z = newPos.z;
	}

	glm::vec3 Player::calculateNewPosition(glm::vec3 offset) {
		glm::vec3 newPos = glm::vec3(m_Position.x, m_Position.y, m_Position.z);
		if (offset.z != 0) {
			newPos.x += (float)glm::sin(glm::radians(m_Yaw)) * -1.0f * offset.z;
			newPos.z += (float)glm::cos(glm::radians(m_Yaw)) * offset.z;
		}
		if (offset.x != 0) {
			newPos.x += (float)glm::sin(glm::radians(m_Yaw - 90)) * -1.0f * offset.x;
			newPos.z += (float)glm::cos(glm::radians(m_Yaw - 90)) * offset.x;
		}
		newPos.y += offset.y;
		return newPos;
	}

	void Player::update()
	{
	}

	Player::~Player()
	{

	}

} } }
