#include "WaterFrameBuffers.h"

namespace engine
{
	namespace helloWorld
	{
		WaterFrameBuffers::WaterFrameBuffers(Window * window)
		{
			m_ReflectionWidth = window->getWidth();
			m_ReflectionHeight = window->getHeight();
			initializeFrameBufferReflection(window);
		}

		WaterFrameBuffers::~WaterFrameBuffers()
		{

		}

		void WaterFrameBuffers::initializeFrameBufferReflection(Window * window)
		{
			m_FrameBufferReflection = createFrameBuffer();
			m_TextureReflection = createTextureAttachment(m_ReflectionWidth, m_ReflectionHeight);
			m_DepthBufferReflection = createDepthBufferAttachment(m_ReflectionWidth, m_ReflectionHeight);
			unbindCurrentFrameBuffer(window);
		}

		unsigned int WaterFrameBuffers::createFrameBuffer()
		{
			unsigned int frameBuffer;
			glGenFramebuffers(1, &frameBuffer);
			// generate name for frame buffer
			glBindFramebuffer(GL_FRAMEBUFFER, frameBuffer);
			// create the frame buffer
			glDrawBuffer(GL_COLOR_ATTACHMENT0);
			// indicate that we will always render to color attachment 0
			return frameBuffer;
		}

		unsigned int WaterFrameBuffers::createTextureAttachment(unsigned int width, unsigned int height)
		{
			unsigned int textureID;
			glGenTextures(1, &textureID);
			glBindTexture(GL_TEXTURE_2D, textureID);
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, nullptr);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
			glFramebufferTexture(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, textureID, 0);
			return textureID;
		}

		unsigned int WaterFrameBuffers::createDepthBufferAttachment(unsigned int width, unsigned int height)
		{
			unsigned int textureID;
			glGenTextures(1, &textureID);
			glBindTexture(GL_TEXTURE_2D, textureID);
			glTexImage2D(GL_TEXTURE_2D, 0, GL_DEPTH_COMPONENT32, width, height, 0, GL_DEPTH_COMPONENT, GL_FLOAT, nullptr);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
			glFramebufferTexture(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, textureID, 0);
			return textureID;
		}

		/*
		 * call to switch to default frame buffer
		 */
		void WaterFrameBuffers::unbindCurrentFrameBuffer(Window * window)
		{
			glBindFramebuffer(GL_FRAMEBUFFER, 0);
			glViewport(0, 0, window->getWidth(), window->getHeight());
		}

		/*
         * call before rendering to this FBO
         */
		void WaterFrameBuffers::bindReflectionFrameBuffer()
		{
			bindFrameBuffer(m_FrameBufferReflection, m_ReflectionWidth, m_ReflectionHeight);
		}

		void WaterFrameBuffers::bindFrameBuffer(unsigned int frameBuffer, unsigned int width, unsigned int height)
		{
			glBindTexture(GL_TEXTURE_2D, 0); // to make sure the texture is not bound
			glBindFramebuffer(GL_FRAMEBUFFER, frameBuffer);
			glViewport(0, 0, width, height);
		}

		unsigned int WaterFrameBuffers::getReflectionTexture() const
		{
			return m_TextureReflection;
		}

		/*
		 * call when closing the game
		 */
		void WaterFrameBuffers::cleanUp()
		{
			glDeleteFramebuffers(1, &m_FrameBufferReflection);
			glDeleteTextures(1, &m_TextureReflection);
			glDeleteRenderbuffers(1, &m_DepthBufferReflection);
		}
	}
}
