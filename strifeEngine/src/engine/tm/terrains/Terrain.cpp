#include "Terrain.h"

namespace engine
{
	namespace tm
	{
		namespace terrains
		{
			Terrain::Terrain(float gridX, float gridZ, Loader * loader, TerrainTexturePack * texturePack, TerrainTexture * blendMap, std::string heightMap)
			{
				m_texturePack = texturePack;
				m_blendMap = blendMap;
				m_heightMap = heightMap;
				m_x = gridX * SIZE;
				m_z = gridZ * SIZE;
				model = generateTerrain(loader, heightMap);
			}

			RawModel * Terrain::generateTerrain(Loader * loader, std::string heightMap)
			{
				return nullptr;
			}

			float Terrain::getX()
			{
				return m_x;
			}

			float Terrain::getZ()
			{
				return m_z;
			}
			RawModel * Terrain::getModel()
			{
				return model;
			}

			TerrainTexturePack * Terrain::getTexturePack()
			{
				return m_texturePack;
			}

			TerrainTexture * Terrain::getBlendMap()
			{
				return m_blendMap;
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
