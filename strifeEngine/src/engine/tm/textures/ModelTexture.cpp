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

			int ModelTexture::getID()
			{
				return m_textureID;
			}

			float ModelTexture::getShineDumper()
			{
				return m_shineDumper;
			}

			ModelTexture * ModelTexture::setShineDumper(float shineDumper)
			{
				m_shineDumper = shineDumper;
				return this;
			}

			float ModelTexture::getReflectivity()
			{
				return m_reflectivity;
			}

			ModelTexture * ModelTexture::setReflectivity(float reflectivity)
			{
				m_reflectivity = reflectivity;
				return this;
			}

			bool ModelTexture::isTransparent()
			{
				return m_IsTransparent;
			}

			ModelTexture * ModelTexture::setTransparency(bool isTransparent)
			{
				m_IsTransparent = isTransparent;
				return this;
			}

			bool ModelTexture::usesFakeLighting()
			{
				return m_UseFakeLighting;
			}

			ModelTexture * ModelTexture::setUsesFakeLighting(bool useFakeLighting)
			{
				m_UseFakeLighting = useFakeLighting;
				return this;
			}

			ModelTexture::~ModelTexture()
			{

			}

		}
	}
}
