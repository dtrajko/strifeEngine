#pragma once

namespace engine
{
	namespace tm
	{
		namespace textures
		{
			class ModelTexture
			{
			private:
				int textureID;

			public:
				ModelTexture(int id);
				int getID();
				~ModelTexture();
			};
		}
	}
}
