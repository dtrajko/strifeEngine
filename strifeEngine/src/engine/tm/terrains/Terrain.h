#pragma once

#include <string>
#include "../../interfaces/ITerrain.h"
#include "../../tm/loaders/Loader.h"

using namespace engine::interfaces;
using namespace engine::tm::loaders;

namespace engine
{
	namespace tm
	{
		namespace terrains
		{
			class Terrain : public ITerrain
			{
			public:
				int SIZE = 800;
			private:
				int MAX_HEIGHT = 30;
				int MAX_PIXEL_COLOR = 256 * 256 * 256;
				int vertexCount = 63;
				float m_x;
				float m_z;
				RawModel * model;
				TerrainTexturePack * m_texturePack;
				TerrainTexture * m_blendMap;
				std::string m_heightMap;
				float heights[10][10];

			public:
				Terrain(float gridX, float gridZ, Loader loader, TerrainTexturePack texturePack, TerrainTexture blendMap, std::string & heightMap);
				RawModel * generateTerrain(Loader loader, std::string & heightMap);
				float getX();
				float getZ();
				RawModel * getModel();
				TerrainTexturePack * getTexturePack();
				TerrainTexture * getBlendMap();
				float getHeightOfTerrain(float coordX, float coordZ);
				float getWaterHeight();
			};
		}
	}
}
