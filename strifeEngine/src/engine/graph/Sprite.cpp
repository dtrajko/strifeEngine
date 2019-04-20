#include "Sprite.h"

namespace engine
{
	namespace graph
	{
		Sprite::Sprite()
		{
			texture = Texture();
			xPos = 0;
			yPos = 0;
		}

		Sprite::Sprite(std::string imagePath)
		{
			texture = Texture(imagePath);
			xPos = 0;
			yPos = 0;
		}

		Sprite::Sprite(std::string imagePath, float _xPos, float _yPos)
		{
			texture = Texture(imagePath);
			xPos = _xPos;
			yPos = _yPos;
		}

		void Sprite::update()
		{

		}

		void Sprite::render()
		{
			glEnable(GL_TEXTURE_2D);
			glBindTexture(GL_TEXTURE_2D, texture.getID());
			glLoadIdentity();

			// Translate -> Rotate -> Scale
			glTranslatef(xPos, yPos, 0);

			// Rendering
			glColor4f(1, 1, 1, 1);
			glBegin(GL_QUADS);
			glTexCoord2f(0, 0);
			glVertex2f(0, 0);
			glTexCoord2f(1, 0);
			glVertex2f((GLfloat) texture.getWidth(), 0);
			glTexCoord2f(1, 1);
			glVertex2f((GLfloat) texture.getWidth(), (GLfloat) texture.getHeight());
			glTexCoord2f(0, 1);
			glVertex2f(0, (GLfloat) texture.getHeight());
			glEnd();

			glDisable(GL_TEXTURE_2D);
		}

		Sprite::~Sprite()
		{

		}
	}
}
