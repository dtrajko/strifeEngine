#ifndef _MESH_H
#define _MESH_H

#include <string>
#include "../../engine/tm/models/RawModel.h"
#include "../../engine/graph/Material.h"

using namespace engine::tm::models;
using namespace engine::graph;

namespace engine { namespace graph {

	class Mesh : public RawModel
	{
	private:
		Material * m_Material;

	public:
		Mesh(int _vaoID, unsigned int _vertexCount);
		Mesh * setMaterial(Material * material);
		Material * getMaterial() const;
		virtual ~Mesh();

	};

} }

#endif
