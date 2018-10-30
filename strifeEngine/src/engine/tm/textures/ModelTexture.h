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
				int m_textureID;
				float m_shineDumper = 1;
				float m_reflectivity = 0;
				bool m_IsTransparent = false;
				bool m_UseFakeLighting = false;

			public:
				ModelTexture(int id);
				int getID();
				float getShineDumper();
				ModelTexture * setShineDumper(float shineDumper);
				float getReflectivity();
				ModelTexture * setReflectivity(float reflectivity);
				bool isTransparent();
				ModelTexture * setTransparency(bool isTransparent);
				bool usesFakeLighting();
				ModelTexture * setUsesFakeLighting(bool useFakeLighting);
				~ModelTexture();
			};
		}
	}
}
