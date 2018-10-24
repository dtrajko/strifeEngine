#pragma once

#include <vector>

namespace engine
{
	namespace tm
	{
		namespace models
		{
			class QuadMeshSimple
			{
			public:
				// unsigned int verticesCount = 1 * 4 * 3;
				// unsigned int textureCoordsCount = 4 * 2;
				// unsigned int indicesCount = 2 * 3;

				std::vector<float> vecVertices = {
					-0.5f,  0.5f, 0.0f,  // V0
					-0.5f, -0.5f, 0.0f,  // V1
					0.5f, -0.5f, 0.0f,  // V2
					0.5f,  0.5f, 0.0f,  // V3
				};

				std::vector<float> vecTextureCoords = {
					0, 0,  // V0
					0, 1,  // V1
					1, 1,  // V2
					1, 0,  // V3
				};

				std::vector<unsigned int> vecIndices = {
					0, 1, 3,  // top left triangle     (V0, V1, V2)
					3, 1, 2   // bottom right triangle (V3, V1, V2)
				};

				QuadMeshSimple();
				float * getVertices();
				float * getTextureCoords();
				unsigned int * getIndices();
				~QuadMeshSimple();
			};
		}
	}
}
