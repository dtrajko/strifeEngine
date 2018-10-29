#pragma once

#include <iostream>
#include "../../../engine/interfaces/ITerrain.h"
#include "../../../engine/tm/models/RawModel.h"
#include "../../../engine/tm/loaders/Loader.h"
#include "../../../engine/tm/textures/ModelTexture.h"

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
				unsigned int m_VertexCount = 64;
				float m_X;
				float m_Z;
				RawModel * m_Model;
				ModelTexture * m_Texture;

			public:
				Terrain(int gridX, int gridZ, Loader * loader, ModelTexture * texture);
				float getX();
				float getZ();
				RawModel * getModel();
				ModelTexture * getTexture();
				TerrainTexturePack * getTexturePack();
				TerrainTexture * getBlendMap();
				float getHeightOfTerrain(float coordX, float coordZ);
				float getWaterHeight();

			private:
				RawModel * generateTerrain(Loader * loader);
				void generateTerrainIndices(unsigned int * indices);
			};
		}
	}
}
