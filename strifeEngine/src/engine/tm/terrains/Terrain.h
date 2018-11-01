#pragma once

#include <iostream>
#include "../../../engine/interfaces/ITerrain.h"
#include "../../../engine/tm/models/RawModel.h"
#include "../../../engine/tm/loaders/Loader.h"
#include "../../../engine/tm/textures/ModelTexture.h"
#include "../../../vendor/stb_image/stb_image.h"

using namespace engine::interfaces;
using namespace engine::tm::models;
using namespace engine::tm::loaders;
using namespace engine::tm::textures;

namespace engine
{
	namespace tm
	{
		namespace terrains
		{
			class Terrain : public ITerrain
			{
			private:
				float m_Size = 800;
				float MAX_HEIGHT = 40;
				float MAX_PIXEL_COLOR = 256 * 256 * 256;

				unsigned int m_VertexCount = 64;
				float m_X;
				float m_Z;
				RawModel * m_Model;
				ModelTexture * m_Texture;

			public:
				Terrain(int gridX, int gridZ, Loader * loader, ModelTexture * texture, const std::string & heightMap);
				float getX();
				float getZ();
				RawModel * getModel();
				ModelTexture * getTexture();
				TerrainTexturePack * getTexturePack();
				TerrainTexture * getBlendMap();
				float getHeightOfTerrain(float coordX, float coordZ);
				float getWaterHeight();

			private:
				RawModel * generateTerrain(Loader * loader, const std::string & heightMap);
				void generateTerrainIndices(unsigned int * indices);
				float getHeight(int x, int z, unsigned char* image, int imageWidth, int imageHeight);
			};
		}
	}
}
