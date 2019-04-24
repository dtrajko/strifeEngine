#ifndef _PLAYER_H
#define _PLAYER_H

#include "../../../engine/tm/entities/Entity.h"
#include "../../../engine/graph/Window.h"

using namespace engine::tm::entities;
using namespace engine::graph;

namespace engine { namespace tm { namespace entities {

	class Player : public Entity
	{
	private:
		const static int RUN_SPEED = 4;
		const static int TURN_SPEED = 80;
		float m_CurrentSpeed = 0;
		float m_CurrentTurnSpeed = 0;
		glm::vec3 cameraInc = glm::vec3();

	public:
		Player(TexturedModel * model, glm::vec3 _position, float _rotX, float _rotY, float _rotZ, float _scale);
		void move(float interval, Window * window);
		void update();
		virtual ~Player();
	private:
		void checkInputs(Window * window);
		glm::vec3 calculateNewPosition(glm::vec3 offset);
	};

} } }

#endif
