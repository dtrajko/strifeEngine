#include "WaterTile.h"

namespace engine { namespace tm { namespace water {

	WaterTile::WaterTile(Loader * loader, float centerX, float Y, float centerZ):
		x(centerX), y(Y), z(centerZ)
	{
		dudvTexture = loader->loadTexture(DUDV_MAP);
		normalMap = loader->loadTexture(NORMAL_MAP);
		setUpVao(loader);
	}

	float WaterTile::getX()
	{
		return x;
	}

	float WaterTile::getY()
	{
		return y;
	}

	float WaterTile::getZ()
	{
		return z;
	}

	RawModel * WaterTile::getModel()
	{
		return m_Quad;
	}

	ModelTexture * WaterTile::getTexture()
	{
		return m_Texture;
	}

	unsigned int WaterTile::getDuDvTexture()
	{
		return dudvTexture;
	}

	unsigned int WaterTile::getNormalMap()
	{
		return normalMap;
	}

	void WaterTile::setUpVao(Loader * loader)
	{
		// Just x and z vertex positions here, y is set to 0 in v.shader
		const std::vector<float> vertices = { -1, -1, -1, 1, 1, -1, 1, -1, -1, 1, 1, 1 };
		m_Quad = loader->loadToVAO((float *)& vertices[0], vertices.size(), 2);
	}

} } }
