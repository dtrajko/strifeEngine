#include "Mesh.h"

namespace engine { namespace graph {

	Mesh::Mesh(int _vaoID, unsigned int _vertexCount) : RawModel(_vaoID, _vertexCount)
	{
		m_Material = nullptr;
	}

	Mesh * Mesh::setMaterial(Material * material)
	{
		m_Material = material;
		return this;
	}

	Material * Mesh::getMaterial() const
	{
		return m_Material;
	}

	Mesh::~Mesh()
	{

	}

} }
