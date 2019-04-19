#include "SkyBox.h"

namespace engine { namespace minecraft { namespace skybox {

	SkyBox::SkyBox(std::string objModel, std::string textureFile)
	{

	}

	SkyBox * SkyBox::setScale(float skyBoxScale)
	{
		m_Scale = skyBoxScale;
		return this;
	}

	SkyBox::~SkyBox()
	{

	}

} } }
