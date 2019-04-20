#ifndef _SKYBOX_H
#define _SKYBOX_H

#include <string>
#include "../../../engine/tm/loaders/Loader.h"
#include "../../../engine/tm/loaders/OBJLoader.h"
#include "../../../engine/graph/Pawn.h"

using namespace engine::tm::loaders;

namespace engine { namespace minecraft { namespace skybox {

	class SkyBox : public Pawn
	{
	private:

	public:
		SkyBox(std::string objModel, std::string textureFile, Loader * loader);
		~SkyBox();

	};

} } }

#endif
