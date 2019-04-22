#include "TextureAtlas.h"

namespace engine { namespace graph {

	TextureAtlas::TextureAtlas(std::string fileName) : Texture(fileName)
	{
		m_Rows = 1;
		m_Columns = 1;

		std::cout << "TextureAtlas constuctor: m_ID: " << m_ID << " Width: " << m_Width << " Height: " << m_Height << std::endl;
	}

	TextureAtlas::TextureAtlas(std::string fileName, unsigned int columns, unsigned int rows) : TextureAtlas(fileName)
	{
		m_Columns = columns;
		m_Rows = rows;
	}

	void TextureAtlas::bind()
	{
		glBindTexture(GL_TEXTURE_2D, m_ID);
	}

	unsigned int TextureAtlas::getRows() const
	{
		return m_Rows;
	}

	unsigned int TextureAtlas::getColumns() const
	{
		return m_Columns;
	}

	unsigned int TextureAtlas::loadTexture(std::string fileName)
	{
		// TODO
		return 0;
	}

	TextureAtlas::~TextureAtlas()
	{

	}

} }
