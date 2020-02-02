#include "MasterRendererMC.h"

namespace engine
{
	namespace minecraft
	{
		MasterRendererMC::MasterRendererMC(Window * window)
		{
			// enableCulling();
			m_ProjectionMatrix = createProjectionMatrix(window);
			m_SkyBoxRenderer = new SkyBoxRenderer(window, m_ProjectionMatrix);
		}

		void MasterRendererMC::init(IScene * scene)
		{
			m_SkyBoxRenderer->init(scene);
		}

		glm::mat4 MasterRendererMC::getProjectionMatrix(Window * window)
		{
			return m_ProjectionMatrix;
		}

		void MasterRendererMC::prepare(Window * window)
		{
			glViewport(0, 0, window->getWidth(), window->getHeight());
			glEnable(GL_DEPTH_TEST);
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
			glClearColor(RED, GREEN, BLUE, 1.0f);
			m_SkyBoxRenderer->prepare(window);
		}

		void MasterRendererMC::render(Window * window, IScene * scene)
		{
			glm::vec4 clipPlane;
			ICamera * camera = scene->getCamera();

			// render to screen
			clipPlane = glm::vec4(0, 0, 0, 0);
			glDisable(GL_CLIP_DISTANCE0);
			prepare(window);
			m_ViewMatrix = Maths::createViewMatrix(camera);
			m_SkyBoxRenderer->render(window, scene, m_ViewMatrix);

			glDisable(GL_CLIP_DISTANCE0);
		}

		void MasterRendererMC::enableCulling()
		{
			glEnable(GL_CULL_FACE);
			glCullFace(GL_BACK);
		}

		void MasterRendererMC::disableCulling()
		{
			glDisable(GL_CULL_FACE);
		}

		glm::mat4 MasterRendererMC::createProjectionMatrix(Window * window)
		{
			glm::mat4 projectionMatrix;
			float aspectRatio = (float)window->getWidth() / (float)window->getHeight();
			float scaleY = (1.0f / glm::tan(glm::radians(FOV / 2.0f))) * aspectRatio;
			float scaleX = scaleY / aspectRatio;
			float frustrumLength = FAR_PLANE - NEAR_PLANE;
			projectionMatrix[0][0] = scaleX;
			projectionMatrix[1][1] = scaleY;
			projectionMatrix[2][2] = -((FAR_PLANE - NEAR_PLANE) / frustrumLength);
			projectionMatrix[2][3] = -1;
			projectionMatrix[3][2] = -((2 * NEAR_PLANE * FAR_PLANE) / frustrumLength);
			projectionMatrix[3][3] = 0;
			return projectionMatrix;
		}

		void MasterRendererMC::cleanUp()
		{
			m_SkyBoxRenderer->cleanUp();
		}

		MasterRendererMC::~MasterRendererMC()
		{
		}
	}
}
