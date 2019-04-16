#ifndef _TEXTURE_ATLAS_H
#define _TEXTURE_ATLAS_H

#include <string>
#include "Texture.h"

namespace engine { namespace graph {

	class TextureAtlas : protected Texture
	{
	private:
		unsigned int m_Rows;
		unsigned int m_Columns;

	public:
		TextureAtlas(std::string fileName);
		TextureAtlas(std::string fileName, unsigned int columns, unsigned int rows);
		void bind();
		unsigned int getRows() const;
		unsigned int getColumns() const;
		unsigned int loadTexture(std::string fileName);

		virtual ~TextureAtlas();

	};

} }

#endif
