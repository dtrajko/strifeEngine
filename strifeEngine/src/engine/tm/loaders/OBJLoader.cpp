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
				std::vector<unsigned int> vecIndices = {};

				float * textureArray = nullptr;
				float * normalsArray = nullptr;

				std::ifstream stream(fileName);
				std::string line;
				std::stringstream fileContent;

				bool faceArraysInitialized = false;
				std::vector<std::string> tokens;
				glm::vec3 vertex;
				glm::vec2 texture;
				glm::vec3 normal;
				std::vector<std::string> vertexData = {};
				std::string tokenChunk;

				while (getline(stream, line))
				{
					// split line into chunks/tokens
					std::istringstream iss(line);
					tokens =
					{
						std::istream_iterator<std::string>{iss},
						std::istream_iterator<std::string>{}
					};

					if (line.compare(0, 2, "v ") == 0)
					{
						vertex = glm::vec3(std::atof(tokens[1].c_str()), std::atof(tokens[2].c_str()), std::atof(tokens[3].c_str()));
						vecVertices.push_back(vertex);
					}
					else if (line.compare(0, 3, "vt ") == 0)
					{
						texture = glm::vec2(std::atof(tokens[1].c_str()), std::atof(tokens[2].c_str()));
						vecTextureCoords.push_back(texture);
					}
					else if (line.compare(0, 3, "vn ") == 0)
					{
						normal = glm::vec3(std::atof(tokens[1].c_str()), std::atof(tokens[2].c_str()), std::atof(tokens[3].c_str()));
						vecNormals.push_back(normal);
					}
					else if (line.compare(0, 2, "f ") == 0)
					{
						if (!faceArraysInitialized)
						{
							textureArray = new float[vecVertices.size() * 2];
							normalsArray = new float[vecVertices.size() * 3];
							faceArraysInitialized = true;
						}
						for (unsigned int index = 1; index <= 3; index++)
						{
							vertexData = {};
							std::stringstream token_chunk_ss(tokens[index]);
							while (token_chunk_ss.good())
							{
								tokenChunk = "";
								getline(token_chunk_ss, tokenChunk, '/');
								vertexData.push_back(tokenChunk);
							}
							processVertex(vertexData, vecIndices, vecTextureCoords, vecNormals, textureArray, normalsArray);
						}						
					}
				}

				unsigned int verticesCount = (unsigned int) vecVertices.size() * 3;
				unsigned int textureCoordsCount = (unsigned int) vecVertices.size() * 2;
				unsigned int normalsCount = (unsigned int) vecVertices.size() * 3;
				unsigned int indicesCount = (unsigned int) vecIndices.size();

				float * verticesArray = new float[vecVertices.size() * 3];
				unsigned int * indicesArray = new unsigned int[vecIndices.size()];

				unsigned int vertexPointer = 0;
				for (glm::vec3 vertex : vecVertices) {
					verticesArray[vertexPointer++] = vertex.x;
					verticesArray[vertexPointer++] = vertex.y;
					verticesArray[vertexPointer++] = vertex.z;
				}
				for (unsigned int indIndex = 0; indIndex < vecIndices.size(); indIndex++) {
					indicesArray[indIndex] = vecIndices.at(indIndex);
				}

				return loader->loadToVAO(verticesArray, verticesCount, textureArray, textureCoordsCount, normalsArray, normalsCount, indicesArray, indicesCount);
			}

			void OBJLoader::processVertex(std::vector<std::string> vertexData,
				std::vector<unsigned int> & vecIndices, std::vector<glm::vec2> & vecTextureCoords, std::vector<glm::vec3> & vecNormals,
				float textureArray[], float normalsArray[])
			{
				int currentVertexPointer = std::atoi(vertexData[0].c_str()) - 1;
				vecIndices.push_back(currentVertexPointer);
				glm::vec2 currentTextureCoord = vecTextureCoords.at(std::atoi(vertexData[1].c_str()) - 1);

				textureArray[currentVertexPointer * 2] = currentTextureCoord.x;
				textureArray[currentVertexPointer * 2 + 1] = 1 - currentTextureCoord.y;

				if (!vertexData[2].empty()) {
					glm::vec3 currentNormal = vecNormals.at(std::atoi(vertexData[2].c_str()) - 1);
					normalsArray[currentVertexPointer * 3]     = currentNormal.x;
					normalsArray[currentVertexPointer * 3 + 1] = currentNormal.y;
					normalsArray[currentVertexPointer * 3 + 2] = currentNormal.z;
				}
			}
		}
	}
}
