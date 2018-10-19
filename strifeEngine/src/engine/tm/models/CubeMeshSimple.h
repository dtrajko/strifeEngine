#pragma once

namespace engine
{
	namespace tm
	{
		namespace models
		{
			class CubeMeshSimple
			{
			public:
				float * vertices;
				unsigned int * textureCoords;
				unsigned int * indices;

				unsigned int verticesCount;
				unsigned int textureCoordsCount;
				unsigned int indicesCount;

				CubeMeshSimple();
				~CubeMeshSimple();
			};
		}
	}
}
