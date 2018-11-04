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
			private:
				const std::vector<float> vecVertices = {
					-0.5f,  0.5f, 0.0f,  // V0
					-0.5f, -0.5f, 0.0f,  // V1
					 0.5f, -0.5f, 0.0f,  // V2
					 0.5f,  0.5f, 0.0f,  // V3
				};

				const std::vector<float> vecTextureCoords = {
					0, 0,  // V0
					0, 1,  // V1
					1, 1,  // V2
					1, 0,  // V3
				};

				const std::vector<unsigned int> vecIndices = {
					0, 1, 3,  // top left triangle     (V0, V1, V2)
					3, 1, 2   // bottom right triangle (V3, V1, V2)
				};

			public:
				QuadMeshSimple();
				float * getVertices();
				float * getTextureCoords();
				unsigned int * getIndices();
				unsigned int getVerticesCount();
				unsigned int getTextureCoordsCount();
				unsigned int getIndicesCount();
				~QuadMeshSimple();
			};
		}
	}
}
