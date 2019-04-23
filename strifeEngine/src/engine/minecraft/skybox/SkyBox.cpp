#include "SkyBox.h"

namespace engine { namespace minecraft { namespace skybox {

	SkyBox::SkyBox(std::string objModel, std::string textureFile, Loader * loader) : Pawn()
	{
		Mesh * skyBoxMesh = (Mesh *) OBJLoader::loadOBJModel(objModel, loader);
		TextureAtlas * skyBoxTexture = new TextureAtlas(textureFile);
		Material * skyBoxMaterial = new Material(skyBoxTexture, 1.0f);
		skyBoxMesh->setMaterial(skyBoxMaterial);
		setMesh(skyBoxMesh);
		std::cout << "SkyBox mesh vertext count: " << skyBoxMesh->getVertexCount() << std::endl;
		std::cout << "SkyBox textureID: " << getMesh()->getMaterial()->getTexture()->getID() << std::endl;
		setPosition(0.0f, 0.0f, 0.0f);
	}

	SkyBox::~SkyBox()
	{

	}

} } }
