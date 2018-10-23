#include "QuadMeshSimple.h"

namespace engine
{
	namespace tm
	{
		namespace models
		{
			QuadMeshSimple::QuadMeshSimple()
			{
				float vertices[1 * 4 * 3] = {
					-0.5f,  0.5f, 0.0f,  // V0
					-0.5f, -0.5f, 0.0f,  // V1
					0.5f, -0.5f, 0.0f,  // V2
					0.5f,  0.5f, 0.0f,  // V3
				};
				SetVertices(vertices);

				float textureCoords[4 * 2] = {
					0, 0,  // V0
					0, 1,  // V1
					1, 1,  // V2
					1, 0,  // V3
				};
				SetTextureCoords(textureCoords);

				unsigned int indices[2 * 3] = {
					0, 1, 3,  // top left triangle     (V0, V1, V2)
					3, 1, 2   // bottom right triangle (V3, V1, V2)
				};
				SetIndices(indices);
			}

			void QuadMeshSimple::SetVertices(float * arrayPtr)
			{
				for (unsigned int i = 0; i < verticesCount; ++i)
				{
					this->vertices[i] = arrayPtr[i];
				}
			}

			void QuadMeshSimple::SetTextureCoords(float * arrayPtr)
			{
				for (unsigned int i = 0; i < textureCoordsCount; ++i)
				{
					this->textureCoords[i] = arrayPtr[i];
				}
			}

			void QuadMeshSimple::SetIndices(unsigned int * arrayPtr)
			{
				for (unsigned int i = 0; i < indicesCount; ++i)
				{
					this->indices[i] = arrayPtr[i];
				}
			}

			QuadMeshSimple::~QuadMeshSimple()
			{

			}
		}
	}
}
