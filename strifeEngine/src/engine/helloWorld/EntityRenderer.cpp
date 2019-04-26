#include "EntityRenderer.h"

namespace engine { namespace helloWorld {

	EntityRenderer::EntityRenderer(Window * window, glm::mat4 projectionMatrix)
	{
		m_Shader = new EntityShader(m_VertexFile, m_FragmentFile);
		m_Shader->start();
		m_Shader->bindAttributes();
		m_ProjectionMatrix = projectionMatrix;
		m_Shader->loadMatrix("projectionMatrix", m_ProjectionMatrix);
		m_Shader->stop();
	}

	void EntityRenderer::init(IScene * scene)
	{

	}

	glm::mat4 EntityRenderer::getProjectionMatrix(Window * window)
	{
		return m_ProjectionMatrix;
	}

	void EntityRenderer::render(Window * window, IScene * scene, glm::mat4 & viewMatrix, glm::vec4 clipPlane)
	{
		m_Shader->start();
		m_Shader->loadClipPlane(clipPlane);
		m_Shader->loadLight(scene->getLight());
		m_Shader->loadMatrix("viewMatrix", viewMatrix);
		std::vector<Entity *> entities = scene->getEntities();
		for (Entity * entity : entities)
		{
			renderModel(entity);
		}
		m_Shader->stop();
	}

	void EntityRenderer::prepare(Window * window)
	{
	}

	void EntityRenderer::renderModel(Entity * entity)
	{
		TexturedModel * texturedModel = entity->getTexturedModel();
		RawModel * model = texturedModel->getRawModel();
		glBindVertexArray(model->getVaoID());
		glEnableVertexAttribArray(0);
		glEnableVertexAttribArray(1);
		glEnableVertexAttribArray(2);

		m_TransformationMatrix = Maths::createTransformationMatrix(
			entity->getPosition(), entity->getRotation(), entity->getScale());
		m_Shader->loadMatrix("transformationMatrix", m_TransformationMatrix);


		ModelTexture * modelTexture = texturedModel->getTexture();
		m_Shader->loadShineVariables(modelTexture->getShineDumper(), modelTexture->getReflectivity());
		m_Shader->loadBool("useFakeLighting", modelTexture->usesFakeLighting());
		glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_2D, modelTexture->getID());

		glDrawElements(GL_TRIANGLES, model->getVertexCount(), GL_UNSIGNED_INT, 0);

		glDisableVertexAttribArray(0);
		glDisableVertexAttribArray(1);
		glDisableVertexAttribArray(2);
		glBindVertexArray(0);
	}

	void EntityRenderer::cleanUp()
	{
		m_Shader->cleanUp();
	}

	EntityRenderer::~EntityRenderer()
	{
	}

} }
