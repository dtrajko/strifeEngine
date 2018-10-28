#include "Terrain.h"

namespace engine
{
	namespace tm
	{
		namespace terrains
		{
			Terrain::Terrain(int gridX, int gridZ, Loader * loader, ModelTexture * texture)
			{
				m_Texture = texture;
				m_X = gridX * m_Size;
				m_Z = gridZ * m_Size;
				m_Model = generateTerrain(loader);
			}

			RawModel * Terrain::generateTerrain(Loader * loader)
			{
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
						vertices[vertexPointer * 3 + 1] = 0;
						vertices[vertexPointer * 3 + 2] = (float) i / ((float) m_VertexCount - 1) * m_Size;
						normals[vertexPointer * 3] = 0;
						normals[vertexPointer * 3 + 1] = 1;
						normals[vertexPointer * 3 + 2] = 0;
						textureCoords[vertexPointer * 2] = (float) j / ((float)m_VertexCount - 1);
						textureCoords[vertexPointer * 2 + 1] = (float) i / ((float)m_VertexCount - 1);
						vertexPointer++;
					}
				}

				generateTerrainIndices(indices);
				return loader->loadToVAO(vertices, verticesCount, textureCoords, textureCoordsCount, normals, normalsCount, indices, indicesCount);
			}

			void Terrain::generateTerrainIndices(unsigned int * indices)
			{
				unsigned int pointer = 0;
				for (unsigned int gz = 0; gz < m_VertexCount; gz++)
				{
					for (unsigned int gx = 0; gx < m_VertexCount; gx++)
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
