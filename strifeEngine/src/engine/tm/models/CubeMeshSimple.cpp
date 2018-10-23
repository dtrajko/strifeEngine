#include "CubeMeshSimple.h"

namespace engine
{
	namespace tm
	{
		namespace models
		{
			CubeMeshSimple::CubeMeshSimple()
			{
				float vertices[6 * 4 * 3] = {
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
				SetVertices(vertices);

				float textureCoords[24 * 2] = {
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
				SetTextureCoords(textureCoords);

				unsigned int indices[12 * 3] = {
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
				SetIndices(indices);
			}

			void CubeMeshSimple::SetVertices(float * arrayPtr)
			{
				for (unsigned int i = 0; i < verticesCount; ++i)
				{
					this->vertices[i] = arrayPtr[i];
				}
			}

			void CubeMeshSimple::SetTextureCoords(float * arrayPtr)
			{
				for (unsigned int i = 0; i < textureCoordsCount; ++i)
				{
					this->textureCoords[i] = arrayPtr[i];
				}
			}

			void CubeMeshSimple::SetIndices(unsigned int * arrayPtr)
			{
				for (unsigned int i = 0; i < indicesCount; ++i)
				{
					this->indices[i] = arrayPtr[i];
				}
			}

			CubeMeshSimple::~CubeMeshSimple()
			{

			}
		}
	}
}
