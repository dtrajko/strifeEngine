#include "WaterFrameBuffers.h"

namespace engine { namespace tm { namespace water {

	WaterFrameBuffers::WaterFrameBuffers(Window * window)
	{
		m_ReflectionWidth = window->getWidth();
		m_ReflectionHeight = window->getHeight();
		m_RefractionWidth = window->getWidth();
		m_RefractionHeight = window->getHeight();
		initializeFrameBufferReflection(window);
		initializeFrameBufferRefraction(window);
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

	void WaterFrameBuffers::initializeFrameBufferRefraction(Window * window)
	{
		m_FrameBufferRefraction = createFrameBuffer();
		m_TextureRefraction = createTextureAttachment(m_RefractionWidth, m_RefractionHeight);
		m_DepthTextureRefraction = createDepthTextureAttachment(m_RefractionWidth, m_RefractionHeight);
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

	unsigned int WaterFrameBuffers::createDepthTextureAttachment(unsigned int width, unsigned int height)
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

	unsigned int WaterFrameBuffers::createDepthBufferAttachment(unsigned int width, unsigned int height)
	{
		unsigned int depthBufferID;
		glGenRenderbuffers(1, &depthBufferID);
		glBindRenderbuffer(GL_RENDERBUFFER, depthBufferID);
		glRenderbufferStorage(GL_RENDERBUFFER, GL_DEPTH_COMPONENT, width, height);
		glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, GL_RENDERBUFFER, depthBufferID);
		return depthBufferID;
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
	void WaterFrameBuffers::bindFrameBufferReflection()
	{
		bindFrameBuffer(m_FrameBufferReflection, m_ReflectionWidth, m_ReflectionHeight);
	}

	/*
		* call before rendering to this FBO
		*/
	void WaterFrameBuffers::bindFrameBufferRefraction()
	{
		bindFrameBuffer(m_FrameBufferRefraction, m_RefractionWidth, m_RefractionHeight);
	}

	void WaterFrameBuffers::bindFrameBuffer(unsigned int frameBuffer, unsigned int width, unsigned int height)
	{
		glBindTexture(GL_TEXTURE_2D, 0); // to make sure the texture is not bound
		glBindFramebuffer(GL_FRAMEBUFFER, frameBuffer);
		glViewport(0, 0, width, height);
	}

	unsigned int WaterFrameBuffers::getTextureReflection() const
	{
		return m_TextureReflection;
	}

	unsigned int WaterFrameBuffers::getTextureRefraction() const
	{
		return m_TextureRefraction;
	}

	unsigned int WaterFrameBuffers::getDepthTextureRefraction() const
	{
		return m_DepthTextureRefraction;
	}

	/*
		* call when closing the game
		*/
	void WaterFrameBuffers::cleanUp()
	{
		glDeleteFramebuffers(1, &m_FrameBufferReflection);
		glDeleteTextures(1, &m_TextureReflection);
		glDeleteRenderbuffers(1, &m_DepthBufferReflection);
		glDeleteFramebuffers(1, &m_FrameBufferRefraction);
		glDeleteTextures(1, &m_TextureRefraction);
		glDeleteTextures(1, &m_DepthTextureRefraction);
	}

} } }
