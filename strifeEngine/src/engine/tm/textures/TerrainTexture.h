#pragma once

namespace engine
{
	namespace tm
	{
		namespace textures
		{
			class TerrainTexture
			{
			private:
				int textureID;
			public:
				TerrainTexture(int textureID);
				int getTextureID();
			};
		}
	}
}
