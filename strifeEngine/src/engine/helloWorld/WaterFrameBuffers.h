#ifndef _WATER_FRAME_BUFFERS_H
#define _WATER_FRAME_BUFFERS_H

#include "../../engine/GameEngine.h"

namespace engine
{
	namespace helloWorld
	{
		class WaterFrameBuffers
		{
		private:
			// reflection attributes
			unsigned int m_ReflectionWidth;
			unsigned int m_ReflectionHeight;
			unsigned int m_FrameBufferReflection;
			unsigned int m_TextureReflection;
			unsigned int m_DepthBufferReflection;
			// refraction attributes
			unsigned int m_RefractionWidth;
			unsigned int m_RefractionHeight;
			unsigned int m_FrameBufferRefraction;
			unsigned int m_TextureRefraction;
			unsigned int m_DepthTextureRefraction;

		public:
			WaterFrameBuffers(Window * window);
			unsigned int getTextureReflection() const;
			unsigned int getTextureRefraction() const;
			unsigned int getDepthTextureRefraction() const;
			void bindFrameBufferReflection();
			void bindFrameBufferRefraction();
			void unbindCurrentFrameBuffer(Window * window);
			~WaterFrameBuffers();

		private:
			void initializeFrameBufferReflection(Window * window);
			void initializeFrameBufferRefraction(Window * window);
			unsigned int createFrameBuffer();
			unsigned int createTextureAttachment(unsigned int width, unsigned int height);
			unsigned int createDepthBufferAttachment(unsigned int width, unsigned int height);
			unsigned int createDepthTextureAttachment(unsigned int width, unsigned int height);
			void bindFrameBuffer(unsigned int frameBuffer, unsigned int width, unsigned int height);
			void cleanUp();
		};
	}
}

#endif
