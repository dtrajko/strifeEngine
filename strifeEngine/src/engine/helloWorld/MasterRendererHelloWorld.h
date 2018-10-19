#pragma once

#include "../interfaces/IMasterRenderer.h"
#include "../interfaces/IScene.h"
#include "../helloWorld/SimpleShader.h"
#include "../tm/toolbox/Maths.h"
#include "../../engine/tm/entities/Entity.h"
#include "../../vendor/glm/glm.hpp"
#include "../../vendor/glm/gtc/matrix_transform.hpp"

using namespace engine::interfaces;
using namespace engine::tm::entities;
using namespace engine::tm::toolbox;

#define ASSERT(x) if (!(x)) __debugbreak();
#define GLCall(x) GLClearError();\
	x;\
	ASSERT(GLLogCall(#x, __FILE__, __LINE__));

void GLClearError();
bool GLLogCall(const char* function, const char* file, int line);

namespace engine
{
	namespace helloWorld
	{
		class MasterRendererHelloWorld : public IMasterRenderer
		{
		private:
			float RED = 0.2f;
			float GREEN = 0.3f;
			float BLUE = 0.6f;
			SimpleShader * shader;
			glm::mat4 projectionMatrix;

		public:
			MasterRendererHelloWorld(Window * window);
			void init(IScene * scene);
			glm::mat4 createProjectionMatrix(Window * window);
			glm::mat4 getProjectionMatrix(Window * window);
			void prepare(Window * window);
			void render(Window * window, IScene * scene);
			void renderModel(Entity * entity);
			void cleanUp();
			virtual ~MasterRendererHelloWorld();
		};
	}
}
