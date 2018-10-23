#include "TerrainTexture.h"

namespace engine
{
	namespace tm
	{
		namespace textures
		{
			TerrainTexture::TerrainTexture(int _textureID)
			{
				textureID = _textureID;
			}

			int TerrainTexture::getTextureID()
			{
				return textureID;
			}
		}
	}
}
