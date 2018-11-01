#include "Terrain.h"

namespace engine
{
	namespace tm
	{
		namespace terrains
		{
			Terrain::Terrain(float gridX, float gridZ, Loader * loader, ModelTexture * texture, const std::string & heightMap)
			{
				m_Texture = texture;
				m_X = gridX * m_Size;
				m_Z = gridZ * m_Size;
				m_Model = generateTerrain(loader, heightMap);
			}

			RawModel * Terrain::generateTerrain(Loader * loader, const std::string & heightMap)
			{
				int imageWidth;
				int imageHeight;
				int imageChannels;
				unsigned char* image = SOIL_load_image(heightMap.c_str(), &imageWidth, &imageHeight, &imageChannels, SOIL_LOAD_RGBA);

				m_VertexCount = imageWidth;

				unsigned int count = m_VertexCount * m_VertexCount;
				unsigned int verticesCount = count * 3;
				unsigned int normalsCount = count * 3;
				unsigned int textureCoordsCount = count * 2;
				unsigned int indicesCount = 6 * (m_VertexCount - 1) * (m_VertexCount - 1);
				float * vertices = new float[verticesCount];
				float * normals = new float[normalsCount];
				float * textureCoords = new float[textureCoordsCount];
				unsigned int * indices = new unsigned int[indicesCount];
				unsigned int vertexPointer = 0;
				for (unsigned int i = 0; i < m_VertexCount; i++)
				{
					for (unsigned int j = 0; j < m_VertexCount; j++)
					{
						vertices[vertexPointer * 3]     = (float) j / ((float) m_VertexCount - 1) * m_Size;
						vertices[vertexPointer * 3 + 1] = getHeight(j, i, image, imageWidth, imageHeight, imageChannels);
						vertices[vertexPointer * 3 + 2] = (float) i / ((float) m_VertexCount - 1) * m_Size;
						glm::vec3 normal = calculateNormal(j, i, image, imageWidth, imageHeight, imageChannels);
						normals[vertexPointer * 3]     = normal.x;
						normals[vertexPointer * 3 + 1] = normal.y;
						normals[vertexPointer * 3 + 2] = normal.z;
						textureCoords[vertexPointer * 2]     = (float) j / ((float) m_VertexCount - 1);
						textureCoords[vertexPointer * 2 + 1] = (float) i / ((float) m_VertexCount - 1);
						vertexPointer++;
					}
				}

				generateTerrainIndices(indices);
				RawModel * rawModel = loader->loadToVAO(vertices, verticesCount, textureCoords, textureCoordsCount, normals, normalsCount, indices, indicesCount);
				return rawModel;
			}

			float Terrain::getHeight(int x, int z, unsigned char* image, int imageWidth, int imageHeight, int imageChannels)
			{
				if (x < 0 || x >= imageWidth || z < 0 || z >= imageHeight)
				{
					return 0;
				}

				int red   = (int) image[((z * imageWidth + x) * imageChannels) + 0];
				int green = (int) image[((z * imageWidth + x) * imageChannels) + 1];
				int blue  = (int) image[((z * imageWidth + x) * imageChannels) + 2];
				int alpha = (int) image[((z * imageWidth + x) * imageChannels) + 3];

				float height = (float) ((red + green + blue) / 3);
				height *= ((MAX_HEIGHT * 2) / MAX_PIXEL_COLOR);
				height -= MAX_HEIGHT;
				return height;
			}

			glm::vec3 Terrain::calculateNormal(int x, int z, unsigned char* image, int imageWidth, int imageHeight, int imageChannels)
			{
				float heightL = getHeight(x - 1, z, image, imageWidth, imageHeight, imageChannels);
				float heightR = getHeight(x + 1, z, image, imageWidth, imageHeight, imageChannels);
				float heightD = getHeight(x, z - 1, image, imageWidth, imageHeight, imageChannels);
				float heightU = getHeight(x, z + 1, image, imageWidth, imageHeight, imageChannels);
				glm::vec3 normal = glm::vec3(heightL - heightR, 2.0f, heightD - heightU);
				glm::normalize(normal);
				return normal;
			}

			void Terrain::generateTerrainIndices(unsigned int * indices)
			{
				unsigned int pointer = 0;
				for (unsigned int gz = 0; gz < m_VertexCount - 1; gz++)
				{
					for (unsigned int gx = 0; gx < m_VertexCount - 1; gx++)
					{
						unsigned int topLeft = (gz * m_VertexCount) + gx;
						unsigned int topRight = topLeft + 1;
						unsigned int bottomLeft = ((gz + 1) * m_VertexCount) + gx;
						unsigned int bottomRight = bottomLeft + 1;
						indices[pointer++] = topLeft;
						indices[pointer++] = bottomLeft;
						indices[pointer++] = topRight;
						indices[pointer++] = topRight;
						indices[pointer++] = bottomLeft;
						indices[pointer++] = bottomRight;
					}
				}
			}

			float Terrain::getX()
			{
				return m_X;
			}

			float Terrain::getZ()
			{
				return m_Z;
			}

			RawModel * Terrain::getModel()
			{
				return m_Model;
			}

			ModelTexture * Terrain::getTexture()
			{
				return m_Texture;
			}

			TerrainTexturePack * Terrain::getTexturePack()
			{
				return nullptr;
			}

			TerrainTexture * Terrain::getBlendMap()
			{
				return nullptr;
			}

			float Terrain::getHeightOfTerrain(float coordX, float coordZ)
			{
				return 0.0f;
			}

			float Terrain::getWaterHeight()
			{
				return 0.0f;
			}
		}
	}
}
