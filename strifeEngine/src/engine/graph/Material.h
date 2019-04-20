#ifndef _MATERIAL_H
#define _MATERIAL_H

#include <string>
#include "../../vendor/glm/glm.hpp"
#include "TextureAtlas.h"

namespace engine { namespace graph {

	class Material
	{
	private:
		glm::vec4 DEFAULT_COLOR = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f);
		glm::vec4 m_ColorAmbient;
		glm::vec4 m_ColorDiffuse;
		glm::vec4 m_ColorSpecular;
		float m_Reflectance;
		float m_Transparency;
		TextureAtlas * m_Texture;
		TextureAtlas * m_NormalMap;
		bool m_IsSolid;

	public:
		Material();
		Material(TextureAtlas * texture);
		Material(TextureAtlas * texture, float reflectance);
		Material(glm::vec4 ambientColor, glm::vec4 diffuseColor, glm::vec4 specularColor, TextureAtlas * texture, float reflectance);
		Material * setReflectance(float reflectance);
		Material * setTransparency(float transparency);
		TextureAtlas * getTexture() const;
		TextureAtlas * getNormalMap() const;
		virtual ~Material();

	};

} }

#endif
