#ifndef _SKYBOX_H
#define _SKYBOX_H

#include <string>
#include "../../../engine/graph/Pawn.h"

namespace engine { namespace minecraft { namespace skybox {

	class SkyBox : public Pawn
	{
	private:

	public:
		SkyBox(std::string objModel, std::string textureFile);
		~SkyBox();

	};

} } }

#endif
