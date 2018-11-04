#pragma once

#include <vector>

namespace engine
{
	namespace tm
	{
		namespace models
		{
			class CubeMeshSimple
			{
			private:
				const std::vector<float> vecVertices = {
					-0.5f,  0.5f, -0.5f,
					-0.5f, -0.5f, -0.5f,
					0.5f, -0.5f, -0.5f,
					0.5f,  0.5f, -0.5f,

					-0.5f,  0.5f,  0.5f,
					-0.5f, -0.5f,  0.5f,
					0.5f, -0.5f,  0.5f,
					0.5f,  0.5f,  0.5f,

					0.5f,  0.5f, -0.5f,
					0.5f, -0.5f, -0.5f,
					0.5f, -0.5f,  0.5f,
					0.5f,  0.5f,  0.5f,

					-0.5f,  0.5f, -0.5f,
					-0.5f, -0.5f, -0.5f,
					-0.5f, -0.5f,  0.5f,
					-0.5f,  0.5f,  0.5f,

					-0.5f,  0.5f,  0.5f,
					-0.5f,  0.5f, -0.5f,
					0.5f,  0.5f, -0.5f,
					0.5f,  0.5f,  0.5f,

					-0.5f, -0.5f,  0.5f,
					-0.5f, -0.5f, -0.5f,
					0.5f, -0.5f, -0.5f,
					0.5f, -0.5f,  0.5f
				};

				const std::vector<float> vecTextureCoords = {
					0, 0,
					0, 1,
					1, 1,
					1, 0,
					0, 0,
					0, 1,
					1, 1,
					1, 0,
					0, 0,
					0, 1,
					1, 1,
					1, 0,
					0, 0,
					0, 1,
					1, 1,
					1, 0,
					0, 0,
					0, 1,
					1, 1,
					1, 0,
					0, 0,
					0, 1,
					1, 1,
					1, 0
				};

				const std::vector<unsigned int> vecIndices = {
					0, 1, 3,
					3, 1, 2,
					4, 5, 7,
					7, 5, 6,
					8, 9, 11,
					11, 9, 10,
					12, 13, 15,
					15, 13, 14,
					16, 17, 19,
					19, 17, 18,
					20, 21, 23,
					23, 21, 22
				};

			public:
				CubeMeshSimple();
				float * getVertices();
				float * getTextureCoords();
				unsigned int * getIndices();
				unsigned int getVerticesCount();
				unsigned int getTextureCoordsCount();
				unsigned int getIndicesCount();
				~CubeMeshSimple();
			};
		}
	}
}
