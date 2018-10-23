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
				unsigned int verticesCount = 1 * 4 * 3;
				unsigned int textureCoordsCount = 4 * 2;
				unsigned int indicesCount = 2 * 3;

				float vertices[1 * 4 * 3];
				float textureCoords[4 * 2];
				unsigned int indices[2 * 3];

				QuadMeshSimple();
				void SetVertices(float * ptr);
				void SetTextureCoords(float * ptr);
				void SetIndices(unsigned int * ptr);
				~QuadMeshSimple();
			};
		}
	}
}
