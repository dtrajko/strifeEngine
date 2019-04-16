#ifndef _MATERIAL_H
#define _MATERIAL_H

#include <string>
#include "TextureAtlas.h"

namespace engine { namespace graph {

	class Material
	{
	private:

	public:
		Material();
		Material(TextureAtlas * texture);
		virtual ~Material();

	};

} }

#endif
