#ifndef _PLAYER_H
#define _PLAYER_H

#include "../../interfaces/ICamera.h"
#include "../entities/Entity.h"
#include "../../utils/Util.h"

using namespace engine::interfaces;
using namespace engine::tm::entities;
using namespace engine::utils;

namespace engine { namespace tm { namespace entities {

	class Player
	{
	private:
		ICamera * m_Camera;
		Entity * m_Entity;
		const float m_CursorSensitivity = 0.2f;
		glm::vec3 m_Position = glm::vec3(0.0f, 0.0f, 0.0f);
		float m_Pitch = 0;
		float m_Yaw = 0;
		float m_Roll = 0;
		glm::vec3 m_PositionIncrement;
		glm::vec2 m_DisplayVector;
		float m_Speed;

	public:
		Player(ICamera * camera, Entity * entity);
		void move(Window * window);
		void update();
		virtual ~Player();
	private:
		glm::vec3 calculateNewPosition(glm::vec3 offset);
	};

} } }

#endif
