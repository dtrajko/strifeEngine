#include "TerrainRenderer.h"

namespace engine
{
	namespace helloWorld
	{
		TerrainRenderer::TerrainRenderer(Window * window, glm::mat4 projectionMatrix)
		{
			m_Shader = new TerrainShader(m_VertexFile, m_FragmentFile);
			m_Shader->start();
			m_Shader->bindAttributes();
			m_ProjectionMatrix = projectionMatrix;
			m_Shader->loadMatrix("projectionMatrix", m_ProjectionMatrix);
			m_Shader->stop();
		}

		void TerrainRenderer::init(IScene * scene)
		{

		}

		glm::mat4 TerrainRenderer::getProjectionMatrix(Window * window)
		{
			return m_ProjectionMatrix;
		}

		void TerrainRenderer::render(Window * window, IScene * scene)
		{
			std::vector<ITerrain *> terrains = scene->getTerrains();

			m_Shader->start();
			m_Shader->loadLight(scene->getLight());
			m_Shader->loadMatrix("viewMatrix", Maths::createViewMatrix(scene->getCamera()));

			for (ITerrain * terrain : terrains) {
				renderTerrain(terrain, scene);
			}

			m_Shader->stop();
		}

		void TerrainRenderer::renderTerrain(ITerrain * terrain, IScene * scene)
		{
			RawModel * model = terrain->getModel();
			m_TransformationMatrix = Maths::createTransformationMatrix(
				glm::vec3(terrain->getX(), 0, terrain->getZ()), 0, 0, 0, 1);
			m_Shader->loadMatrix("transformationMatrix", m_TransformationMatrix);
		}

		void TerrainRenderer::prepare(Window * window)
		{
		}

		void TerrainRenderer::cleanUp()
		{
			m_Shader->cleanUp();
		}

		TerrainRenderer::~TerrainRenderer()
		{
		}
	}
}
