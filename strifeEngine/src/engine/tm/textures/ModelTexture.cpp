#include "ModelTexture.h"

namespace engine
{
	namespace tm
	{
		namespace textures
		{
			ModelTexture::ModelTexture(int id)
			{
				m_textureID = id;
			}

			int ModelTexture::getID() const
			{
				return m_textureID;
			}

			float ModelTexture::getShineDumper() const
			{
				return m_shineDumper;
			}

			ModelTexture * ModelTexture::setShineDumper(float shineDumper)
			{
				m_shineDumper = shineDumper;
				return this;
			}

			float ModelTexture::getReflectivity() const
			{
				return m_reflectivity;
			}

			ModelTexture * ModelTexture::setReflectivity(float reflectivity)
			{
				m_reflectivity = reflectivity;
				return this;
			}

			bool ModelTexture::isTransparent() const
			{
				return m_IsTransparent;
			}

			ModelTexture * ModelTexture::setTransparency(bool isTransparent)
			{
				m_IsTransparent = isTransparent;
				return this;
			}

			bool ModelTexture::usesFakeLighting() const
			{
				return m_UseFakeLighting;
			}

			ModelTexture * ModelTexture::setUsesFakeLighting(bool useFakeLighting)
			{
				m_UseFakeLighting = useFakeLighting;
				return this;
			}

			ModelTexture * ModelTexture::setNumberOfRows(unsigned int numberOfRows)
			{
				m_NumberOfRows = numberOfRows;
				return this;
			}

			unsigned int ModelTexture::getNumberOfRows() const
			{
				return m_NumberOfRows;
			}

			ModelTexture::~ModelTexture()
			{

			}

		}
	}
}
