#include "QuadMeshSimple.h"

namespace engine
{
	namespace tm
	{
		namespace models
		{
			QuadMeshSimple::QuadMeshSimple()
			{
				float verticesList[] = {
					// left bottom triangle
					-0.5f,  0.5f, 0.0f,  // V0
					-0.5f, -0.5f, 0.0f,  // V1
					 0.5f, -0.5f, 0.0f,  // V2
					 0.5f,  0.5f, 0.0f,  // V3
				};
				vertices = verticesList;
				verticesCount = 1 * 4 * 3;
				
				float textureCoordsList[] = {
					0, 0,  // V0
					0, 1,  // V1
					1, 1,  // V2
					1, 0,  // V3
				};
				textureCoords = textureCoordsList;
				textureCoordsCount = 4 * 2;

				unsigned int indicesList[] = {
					0, 1, 3,  // top left triangle     (V0, V1, V2)
					3, 1, 2   // bottom right triangle (V3, V1, V2)
				};
				indices = indicesList;
				indicesCount = 2 * 3;
			}

			QuadMeshSimple::~QuadMeshSimple()
			{

			}
		}
	}
}
