#include "Water.h"

namespace engine { namespace tm { namespace water {
	
	Water::Water(Loader * loader)
	{
	}

	RawModel Water::getQuad()
	{
		return RawModel(0, 0);
	}

	int Water::getDuDvTexture()
	{
		return 0;
	}

	int Water::getNormalMap()
	{
		return 0;
	}

	void Water::setUpVao(Loader * loader)
	{
	}

} } }
