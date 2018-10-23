#include "TerrainTexturePack.h"

namespace engine
{
	namespace tm
	{
		namespace textures
		{
			TerrainTexturePack::TerrainTexturePack(TerrainTexture * _backgroundTexture, TerrainTexture * _rTexture, TerrainTexture * _gTexture, TerrainTexture * _bTexture)
			{
				backgroundTexture = _backgroundTexture;
				rTexture = _rTexture;
				gTexture = _gTexture;
				bTexture = _bTexture;
			}
			TerrainTexture * TerrainTexturePack::getBackgroundTexture()
			{
				return backgroundTexture;
			}
			TerrainTexture * TerrainTexturePack::getRedTexture()
			{
				return rTexture;
			}
			TerrainTexture * TerrainTexturePack::getGreenTexture()
			{
				return gTexture;
			}
			TerrainTexture * TerrainTexturePack::getBlueTexture()
			{
				return bTexture;
			}

			TerrainTexturePack::~TerrainTexturePack()
			{

			}
		}
	}
}
