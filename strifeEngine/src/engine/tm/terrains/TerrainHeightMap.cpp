#include "TerrainHeightMap.h"

namespace engine
{
	namespace tm
	{
		namespace terrains
		{
			TerrainHeightMap::TerrainHeightMap(float gridX, float gridZ, Loader * loader, TerrainTexturePack * texturePack, TerrainTexture * blendMap, std::string heightMap)
			{
				m_texturePack = texturePack;
				m_blendMap = blendMap;
				m_heightMap = heightMap;
				m_x = gridX * SIZE;
				m_z = gridZ * SIZE;
				model = generateTerrain(loader, heightMap);
			}

			RawModel * TerrainHeightMap::generateTerrain(Loader * loader, std::string heightMap)
			{
				return nullptr;
			}

			float TerrainHeightMap::getX()
			{
				return m_x;
			}

			float TerrainHeightMap::getZ()
			{
				return m_z;
			}

			RawModel * TerrainHeightMap::getModel()
			{
				return model;
			}

			TerrainTexturePack * TerrainHeightMap::getTexturePack()
			{
				return m_texturePack;
			}

			TerrainTexture * TerrainHeightMap::getBlendMap()
			{
				return m_blendMap;
			}

			float TerrainHeightMap::getHeightOfTerrain(float coordX, float coordZ)
			{
				return 0.0f;
			}

			float TerrainHeightMap::getWaterHeight()
			{
				return 0.0f;
			}
		}
	}
}
