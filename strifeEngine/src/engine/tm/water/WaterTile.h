#pragma once

namespace engine { namespace tm { namespace water {

	class WaterTile
	{
	public:
		const static int TILE_SIZE = 400;

	private:
		float x, y, z;

	public:
		WaterTile(float centerX, float Y, float centerZ);
		float getX();
		float getY();
		float getZ();
	};

} } }
