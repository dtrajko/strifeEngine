#include "Player.h"

namespace engine { namespace tm { namespace entities {

	Player::Player(TexturedModel * model, glm::vec3 _position, float _rotX, float _rotY, float _rotZ, float _scale) :
		Entity(model, _position, _rotX, _rotY, _rotZ, _scale)
	{
	}

	void Player::move(float interval, Window * window)
	{
		checkInputs(window);
		increaseRotation(0, m_CurrentTurnSpeed * 0.01f, 0);
		float distance = m_CurrentSpeed * -0.1f;
		float dx = (float)(distance * glm::sin(glm::radians(rotY)));
		float dz = (float)(distance * glm::cos(glm::radians(rotY)));
		increasePosition(dx, 0, dz);
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
		if (input->isKeyDown(GLFW_KEY_E) || input->isKeyDown(GLFW_KEY_SPACE)) {
			increasePosition(0, RUN_SPEED * 0.1f, 0);
		}
		if (input->isKeyDown(GLFW_KEY_LEFT_SHIFT)) {
			increasePosition(0, -RUN_SPEED * 0.1f, 0);
		}

		float strifeX = 0;
		float strifeZ = 0;
		if (input->isKeyDown(GLFW_KEY_Z))
		{
			strifeX -= glm::cos(glm::radians(rotY));
			strifeZ += glm::sin(glm::radians(rotY));
		}
		if (input->isKeyDown(GLFW_KEY_X))
		{
			strifeX += glm::cos(glm::radians(rotY));
			strifeZ -= glm::sin(glm::radians(rotY));
		}
		increasePosition(strifeX, 0, strifeZ);
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
