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
			unsigned int m_ReflectionWidth;
			unsigned int m_ReflectionHeight;
			unsigned int m_FrameBufferReflection;
			unsigned int m_TextureReflection;
			unsigned int m_DepthBufferReflection;

		public:
			WaterFrameBuffers(Window * window);
			unsigned int getReflectionTexture() const;
			void bindReflectionFrameBuffer();
			void unbindCurrentFrameBuffer(Window * window);
			~WaterFrameBuffers();

		private:
			void initializeFrameBufferReflection(Window * window);
			unsigned int createFrameBuffer();
			unsigned int createTextureAttachment(unsigned int width, unsigned int height);
			unsigned int createDepthBufferAttachment(unsigned int width, unsigned int height);
			void bindFrameBuffer(unsigned int frameBuffer, unsigned int width, unsigned int height);
			void cleanUp();
		};
	}
}

#endif
