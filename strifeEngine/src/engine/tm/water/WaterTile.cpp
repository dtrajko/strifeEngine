#include "WaterTile.h"

namespace engine { namespace tm { namespace water {

	WaterTile::WaterTile(Loader * loader, float centerX, float Y, float centerZ):
		x(centerX), y(Y), z(centerZ)
	{
		dudvTexture = loader->loadTexture(DUDV_MAP);
		normalMap = loader->loadTexture(NORMAL_MAP);
		m_Quad = setUpVao(loader);
	}

	RawModel * WaterTile::setUpVao(Loader * loader)
	{
		// Just x and z vertex positions here, y is set to 0 in v.shader
		const std::vector<float> vertices = {
			-1, -1,
			-1,  1,
			 1, -1,
			 1, -1,
			-1,  1,
			 1,  1
		};
		RawModel * quad = loader->loadToVAO((float *)& vertices[0], (unsigned int) vertices.size(), 2);
		return quad;
	}

	float WaterTile::getX() const
	{
		return x;
	}

	float WaterTile::getY() const
	{
		return y;
	}

	float WaterTile::getZ() const
	{
		return z;
	}

	RawModel * WaterTile::getModel() const
	{
		return m_Quad;
	}

	unsigned int WaterTile::getDuDvTexture() const
	{
		return dudvTexture;
	}

	unsigned int WaterTile::getNormalMap() const
	{
		return normalMap;
	}

} } }
