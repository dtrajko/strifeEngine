#ifndef _WATER_TILE_H
#define _WATER_TILE_H

#include "../models/RawModel.h"
#include "../textures/ModelTexture.h"
#include "../loaders/Loader.h"

using namespace engine::tm::models;
using namespace engine::tm::textures;
using namespace engine::tm::loaders;

namespace engine { namespace tm { namespace water {

	class WaterTile
	{
	public:
		const static int HEIGHT = 2;
		const static int TILE_SIZE = 240;

	private:
		std::string DUDV_MAP = "resources/ThinMatrix/textures/water/waterDUDV.png";
		std::string NORMAL_MAP = "resources/ThinMatrix/textures/water/normal.png";

		float x, y, z;
		unsigned int dudvTexture;
		unsigned int normalMap;
		RawModel * m_Quad;

	public:
		WaterTile(Loader * loader, float centerX, float Y, float centerZ);
		float getX() const;
		float getY() const;
		float getZ() const;
		unsigned int getDuDvTexture() const;
		unsigned int getNormalMap() const;
		RawModel * getModel() const;

	private:
		RawModel * setUpVao(Loader * loader);
	};

} } }

#endif
