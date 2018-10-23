#pragma once

#include "TerrainTexture.h"

namespace engine
{
	namespace tm
	{
		namespace textures
		{
			class TerrainTexturePack
			{
			private:
				TerrainTexture * backgroundTexture;
				TerrainTexture * rTexture;
				TerrainTexture * gTexture;
				TerrainTexture * bTexture;

			public:
				TerrainTexturePack(
					TerrainTexture * _backgroundTexture, 
					TerrainTexture * _rTexture,
					TerrainTexture * _gTexture,
					TerrainTexture * _bTexture
				);

				TerrainTexture * getBackgroundTexture();
				TerrainTexture * getRedTexture();
				TerrainTexture * getGreenTexture();
				TerrainTexture * getBlueTexture();
				virtual ~TerrainTexturePack();
			};
		}
	}
}
