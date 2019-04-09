#pragma once

#include <iostream>
#include "../models/RawModel.h"
#include "../loaders/Loader.h"

using namespace engine::tm::models;
using namespace engine::tm::loaders;

namespace engine { namespace tm { namespace water {

	class Water
	{
	public:
		const static int HEIGHT = -6;
	private:
		std::string DUDV_MAP = "resources/ThinMatrix/textures/water/waterDUDV.png";
		std::string NORMAL_MAP = "resources/ThinMatrix/textures/water/normal.png";

		RawModel * quad;
		int dudvTexture;
		int normalMap;

	public:
		Water(Loader * loader);
		RawModel *  getQuad();
		int getDuDvTexture();
		int getNormalMap();

	private:
		void setUpVao(Loader * loader);

	};

} } }
