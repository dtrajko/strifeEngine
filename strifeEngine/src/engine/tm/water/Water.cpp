#include "Water.h"

namespace engine { namespace tm { namespace water {
	
	Water::Water(Loader * loader)
	{
		dudvTexture = loader->loadTexture(DUDV_MAP);
		normalMap = loader->loadTexture(NORMAL_MAP);
		setUpVao(loader);
	}

	RawModel * Water::getQuad()
	{
		return quad;
	}

	int Water::getDuDvTexture()
	{
		return dudvTexture;
	}

	int Water::getNormalMap()
	{
		return normalMap;
	}

	void Water::setUpVao(Loader * loader)
	{
		// Just x and z vertex positions here, y is set to 0 in v.shader
		const std::vector<float> vertices = { -1, -1, -1, 1, 1, -1, 1, -1, -1, 1, 1, 1 };
		quad = loader->loadToVAO((float *)& vertices[0], vertices.size(), 2);
	}

} } }
