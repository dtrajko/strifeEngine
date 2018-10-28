#pragma once

#include "../../engine/tm/models/RawModel.h"
#include "../../engine/tm/textures/TerrainTexture.h"
#include "../../engine/tm/textures/TerrainTexturePack.h"
#include "../../engine/tm/models/RawModel.h"

using namespace engine::tm::models;
using namespace engine::tm::textures;

namespace engine
{
	namespace interfaces
	{
		class ITerrain
		{
		private:
			RawModel * m_Model;

		public:
			virtual float getX() = 0;
			virtual float getZ() = 0;
			virtual RawModel * getModel() = 0;
			virtual TerrainTexturePack * getTexturePack() = 0;
			virtual TerrainTexture * getBlendMap() = 0;
			virtual float getHeightOfTerrain(float coordX, float coordZ) = 0;
			virtual float getWaterHeight() = 0;
		};
	}
}
