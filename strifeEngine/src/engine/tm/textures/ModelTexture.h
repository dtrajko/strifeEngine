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
				unsigned int m_NumberOfRows = 0;

			public:
				ModelTexture(int id);
				int getID() const;
				float getShineDumper() const;
				ModelTexture * setShineDumper(float shineDumper);
				float getReflectivity() const;
				ModelTexture * setReflectivity(float reflectivity);
				bool isTransparent() const;
				ModelTexture * setTransparency(bool isTransparent);
				bool usesFakeLighting() const;
				ModelTexture * setUsesFakeLighting(bool useFakeLighting);
				ModelTexture * setNumberOfRows(unsigned int numberOfRows);
				unsigned int getNumberOfRows() const;
				~ModelTexture();
			};
		}
	}
}
