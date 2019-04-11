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
		const static int HEIGHT = -6;
		const static int TILE_SIZE = 400;

	private:
		std::string DUDV_MAP = "resources/ThinMatrix/textures/water/waterDUDV.png";
		std::string NORMAL_MAP = "resources/ThinMatrix/textures/water/normal.png";

		float x, y, z;
		RawModel * m_Quad;
		ModelTexture * m_Texture;
		unsigned int dudvTexture;
		unsigned int normalMap;

	public:
		WaterTile(Loader * loader, float centerX, float Y, float centerZ);
		float getX();
		float getY();
		float getZ();
		unsigned int getDuDvTexture();
		unsigned int getNormalMap();
		RawModel * getModel();
		ModelTexture * getTexture();

	private:
		void setUpVao(Loader * loader);
	};

} } }

#endif
