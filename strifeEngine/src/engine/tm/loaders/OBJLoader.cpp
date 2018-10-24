#include "OBJLoader.h"

namespace engine
{
	namespace tm
	{
		namespace loaders
		{
			RawModel * OBJLoader::loadOBJModel(std::string fileName, Loader * loader)
			{
				std::vector<glm::vec3> vecVertices = {};
				std::vector<glm::vec2> vecTextureCoords = {};
				std::vector<glm::vec3> vecNormals = {};
				std::vector<int> vecIndices = {};

				unsigned int positionsCount = 10;
				unsigned int textureCoordsCount = 10;
				unsigned int normalsCount = 10;
				unsigned int indicesCount = 10;
				float positions[10];
				float textureCoords[10];
				float normals[10];
				unsigned int indices[10];

				std::ifstream stream(fileName);
				std::string line;
				std::stringstream fileContent;
				while (getline(stream, line))
				{
					fileContent << line << "\n";
				}

				return loader->loadToVAO(positions, positionsCount, textureCoords, textureCoordsCount, normals, normalsCount, indices, indicesCount);
			}

			void OBJLoader::processVertex()
			{

			}
		}
	}
}
