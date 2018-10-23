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
				unsigned int verticesCount = 6 * 4 * 3;
				unsigned int textureCoordsCount = 24 * 2;
				unsigned int indicesCount = 12 * 3;

				float vertices[6 * 4 * 3];
				float textureCoords[24 * 2];
				unsigned int indices[12 * 3];

				CubeMeshSimple();
				void SetVertices(float * ptr);
				void SetTextureCoords(float * ptr);
				void SetIndices(unsigned int * ptr);
				~CubeMeshSimple();
			};
		}
	}
}
