#ifndef _PLAYER_H
#define _PLAYER_H

#include <vector>
#include "../../../engine/tm/entities/Entity.h"
#include "../../../engine/graph/Window.h"

using namespace engine::tm::entities;
using namespace engine::graph;

namespace engine { namespace tm { namespace entities {

	class Player : public Entity
	{
	private:
		float RUN_SPEED = 0.5f;
		float TURN_SPEED = 0.5f;
		float m_ForwardSpeed = 0;
		float m_VerticalSpeed = 0;
		float m_CurrentTurnSpeed = 0;
		float m_StrafeX = 0;
		float m_StrafeZ = 0;
		glm::vec3 cameraInc = glm::vec3();

	public:
		Player(TexturedModel* model, glm::vec3 position, glm::vec3 rotation, glm::vec3 scale);
		void move(float interval, Window* window, std::vector<Entity*> entities);
		void update();
		virtual ~Player();
	private:
		void checkInputs(Window * window);
		glm::vec3 calculateNewPosition(glm::vec3 offset);
		bool inCollision(std::vector<Entity*> entities);
	};

} } }

#endif
