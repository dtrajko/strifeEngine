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
			m_Shader->start();
			m_Shader->loadLight(scene->getLight());
			m_Shader->loadMatrix("viewMatrix", Maths::createViewMatrix(scene->getCamera()));
			renderModel(scene->getEntity(), scene);
			m_Shader->stop();
		}

		void TerrainRenderer::prepare(Window * window)
		{
		}

		void TerrainRenderer::renderModel(Entity * entity, IScene * scene)
		{
			TexturedModel * texturedModel = entity->getTexturedModel();
			RawModel * model = texturedModel->getRawModel();
			ModelTexture * modelTexture = texturedModel->getTexture();
			glBindVertexArray(model->getVaoID());
			glEnableVertexAttribArray(0);
			glEnableVertexAttribArray(1);
			glEnableVertexAttribArray(2);
			m_TransformationMatrix = Maths::createTransformationMatrix(
				entity->getPosition(), entity->getRotX(), entity->getRotY(), entity->getRotZ(), entity->getScale());
			m_Shader->loadMatrix("transformationMatrix", m_TransformationMatrix);
			m_Shader->loadShineVariables(modelTexture->getShineDumper(), modelTexture->getReflectivity());
			glActiveTexture(GL_TEXTURE0);
			glBindTexture(GL_TEXTURE_2D, modelTexture->getID());
			glDrawElements(GL_TRIANGLES, model->getVertexCount(), GL_UNSIGNED_INT, 0);
			glDisableVertexAttribArray(0);
			glDisableVertexAttribArray(1);
			glDisableVertexAttribArray(2);
			glBindVertexArray(0);
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
