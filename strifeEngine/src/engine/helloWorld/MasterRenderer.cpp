#include "MasterRenderer.h"

namespace engine
{
	namespace helloWorld
	{
		MasterRenderer::MasterRenderer(Window * window)
		{
			// enableCulling();
			m_ProjectionMatrix = createProjectionMatrix(window);
			m_EntityRenderer = new EntityRenderer(window, m_ProjectionMatrix);
			m_TerrainRenderer = new TerrainRenderer(window, m_ProjectionMatrix);
			m_WaterRenderer = new WaterRenderer(window, m_ProjectionMatrix);
		}

		void MasterRenderer::init(IScene * scene)
		{
			m_EntityRenderer->init(scene);
			m_TerrainRenderer->init(scene);
			m_WaterRenderer->init(scene);
		}

		glm::mat4 MasterRenderer::getProjectionMatrix(Window * window)
		{
			return m_ProjectionMatrix;
		}

		void MasterRenderer::prepare(Window * window)
		{
			glViewport(0, 0, window->getWidth(), window->getHeight());
			glEnable(GL_DEPTH_TEST);
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
			glClearColor(RED, GREEN, BLUE, 1.0f);
			m_EntityRenderer->prepare(window);
			m_TerrainRenderer->prepare(window);
			m_WaterRenderer->prepare(window);
		}

		void MasterRenderer::render(Window * window, IScene * scene)
		{
			prepare(window);
			m_ViewMatrix = Maths::createViewMatrix(scene->getCamera());
			m_EntityRenderer->render(window, scene, m_ViewMatrix);
			m_TerrainRenderer->render(window, scene, m_ViewMatrix);
			m_WaterRenderer->render(window, scene, m_ViewMatrix);
		}

		void MasterRenderer::enableCulling()
		{
			glEnable(GL_CULL_FACE);
			glCullFace(GL_BACK);
		}

		void MasterRenderer::disableCulling()
		{
			glDisable(GL_CULL_FACE);
		}

		glm::mat4 MasterRenderer::createProjectionMatrix(Window * window)
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

		void MasterRenderer::cleanUp()
		{
			m_EntityRenderer->cleanUp();
			m_TerrainRenderer->cleanUp();
			m_WaterRenderer->cleanUp();
		}

		MasterRenderer::~MasterRenderer()
		{
		}
	}
}
