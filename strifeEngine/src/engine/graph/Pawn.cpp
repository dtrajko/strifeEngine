#include "Pawn.h"

namespace engine { namespace graph {

	Pawn::Pawn()
	{
		m_IsSelected = false;
		m_Position = glm::vec3(0.0f);
		m_Rotation = glm::vec3(0.0f);
		m_Scale = 1;
	}

	Pawn * Pawn::setScale(float scale)
	{
		m_Scale = scale;
		return this;
	}

	Pawn * Pawn::setMesh(Mesh * mesh)
	{
		m_Meshes.push_back(mesh);
		return this;
	}

	Mesh * Pawn::getMesh()
	{
		return m_Meshes.at(0);
	}

	Pawn * Pawn::setPosition(float x, float y, float z)
	{
		m_Position.x = x;
		m_Position.y = y;
		m_Position.z = z;
		return this;
	}

	glm::vec3 Pawn::getPosition() const
	{
		return m_Position;
	}

	float Pawn::getScale() const
	{
		return m_Scale;
	}

	Pawn::~Pawn()
	{

	}

} }
