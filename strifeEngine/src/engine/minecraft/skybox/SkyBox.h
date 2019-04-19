#ifndef _SKYBOX_H
#define _SKYBOX_H

#include <string>

namespace engine { namespace minecraft { namespace skybox {

	class SkyBox
	{
	private:
		float m_Scale;

	public:
		SkyBox(std::string objModel, std::string textureFile);
		SkyBox * setScale(float skyBoxScale);
		~SkyBox();

	};

} } }

#endif
