#ifndef _PAWN_H
#define _PAWN_H

#include <vector>
#include "../../vendor/glm/glm.hpp"
#include "../../engine/graph/Mesh.h"
#include "AABB.h"

namespace engine { namespace graph {

	class Pawn
	{
	private:
		std::vector<Mesh *> m_Meshes;
		glm::vec3 m_Position;
		glm::vec3 m_Rotation;
		float m_Scale;
		bool m_IsSelected;
		AABB * boundingBox;

	public:
		Pawn();
		Pawn * setScale(float scale);
		Pawn * setMesh(Mesh * mesh);
		Mesh * getMesh();
		Pawn * setPosition(float x, float y, float z);
		glm::vec3 getPosition() const;
		float getScale() const;
		virtual ~Pawn();

	};
	
} }

#endif
