#include "CubeMeshSimple.h"

namespace engine
{
	namespace tm
	{
		namespace models
		{
			CubeMeshSimple::CubeMeshSimple()
			{
				float verticesList[] = {
					-0.5f, 0.5f,-0.5f,
					-0.5f,-0.5f,-0.5f,
					0.5f,-0.5f,-0.5f,
					0.5f, 0.5f,-0.5f,

					-0.5f, 0.5f, 0.5f,
					-0.5f,-0.5f, 0.5f,
					0.5f,-0.5f, 0.5f,
					0.5f, 0.5f, 0.5f,

					0.5f, 0.5f,-0.5f,
					0.5f,-0.5f,-0.5f,
					0.5f,-0.5f, 0.5f,
					0.5f, 0.5f, 0.5f,

					-0.5f, 0.5f,-0.5f,
					-0.5f,-0.5f,-0.5f,
					-0.5f,-0.5f, 0.5f,
					-0.5f, 0.5f, 0.5f,

					-0.5f, 0.5f, 0.5f,
					-0.5f, 0.5f,-0.5f,
					0.5f, 0.5f,-0.5f,
					0.5f, 0.5f, 0.5f,

					-0.5f,-0.5f, 0.5f,
					-0.5f,-0.5f,-0.5f,
					0.5f,-0.5f,-0.5f,
					0.5f,-0.5f, 0.5f
				};
				vertices = verticesList;
				verticesCount = 6 * 4 * 3;
				
				unsigned int textureCoordsList[] = {
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
				textureCoords = textureCoordsList;
				textureCoordsCount = 24 * 2;

				unsigned int indicesList[] = {
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
				indices = indicesList;
				indicesCount = 12 * 3;
			}

			CubeMeshSimple::~CubeMeshSimple()
			{

			}
		}
	}
}
