#include "WaterTile.h"

namespace engine { namespace tm { namespace water {

	WaterTile::WaterTile(float centerX, float Y, float centerZ):
		x(centerX), y(Y), z(centerZ)
	{

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

} } }
