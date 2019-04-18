#include "Material.h"

namespace engine { namespace graph {

		Material::Material()
		{
			m_ColorAmbient = DEFAULT_COLOR;
			m_ColorDiffuse = DEFAULT_COLOR;
			m_ColorSpecular = DEFAULT_COLOR;
			m_Texture = nullptr;
			m_Reflectance = 0;
			m_Transparency = 0;
			m_IsSolid = true;
		}

		Material::Material(TextureAtlas * texture) : Material(DEFAULT_COLOR, DEFAULT_COLOR, DEFAULT_COLOR, texture, 0)
		{

		}

		Material::Material(glm::vec4 colorAmbient, glm::vec4 colorDiffuse, glm::vec4 colorSpecular, TextureAtlas * texture, float reflectance)
		{
			m_ColorAmbient = colorAmbient;
			m_ColorDiffuse = colorDiffuse;
			m_ColorSpecular = colorSpecular;
			m_Texture = texture;
			m_Reflectance = reflectance;
			m_IsSolid = true;
		}

		Material * Material::setReflectance(float reflectance)
		{
			m_Reflectance = reflectance;
			return this;
		}

		Material * Material::setTransparency(float transparency)
		{
			m_Transparency = transparency;
			return this;
		}

		Material::~Material()
		{

		}

} }
