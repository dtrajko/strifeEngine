#pragma once

namespace engine
{
	namespace tm
	{
		namespace models
		{
			class QuadMeshSimple
			{
			public:
				float * vertices;
				float * textureCoords;
				unsigned int * indices;

				unsigned int verticesCount;
				unsigned int textureCoordsCount;
				unsigned int indicesCount;

				QuadMeshSimple();
				~QuadMeshSimple();
			};
		}
	}
}
