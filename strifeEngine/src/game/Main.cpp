#include <iostream>
#include <map>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "../engine/GameEngine.h"
#include "../engine/interfaces/IGameLogic.h"
#include "../engine/WindowOptions.h"
#include "../engine/helloWorld/HelloWorld.h"
#include "../engine/graph/Sprite.h"
#include "../engine/helloWorld/SimpleShader.h"

using namespace engine;
using namespace engine::interfaces;
using namespace engine::helloWorld;

int width = 0;
int height = 0;
std::string app = "HelloWorld"; // ThinMatrix

enum AppName
{
	Hello_World,
	Thin_Matrix,
};

static std::map<std::string, AppName> mapAppNames;

bool vSync = false;
IGameLogic* gameLogic;
GameEngine * gameEng;
WindowOptions* opts = new WindowOptions();

void InitAppNames()
{
	mapAppNames["HelloWorld"] = Hello_World;
	mapAppNames["ThinMatrix"] = Thin_Matrix;
}

int main(void)
{
	InitAppNames();

	opts->cullFace = true;
	opts->showFps = true;
	opts->compatibleProfile = true;

	switch (mapAppNames[app])
	{
		case Hello_World:
		{
			std::cout << "HelloWorld app name detected!" << std::endl;
			gameLogic = new engine::helloWorld::HelloWorld();
			opts->mode3D = true;
			opts->cullFace = false;
			opts->antialiasing = true;
			width = 1280;
			height = 720;
			break;
		}
		case Thin_Matrix:
		{
			std::cout << "ThinMatrix app name detected!" << std::endl;
			break;
		}
	}

	gameEng = new GameEngine(app, width, height, vSync, opts, gameLogic);
	gameEng->init();
	gameEng->start();

	Sprite sprite = Sprite("resources/assets/art/fortnite.png", 350, 100);

	std::string VERTEX_FILE = "resources/shaders/simpleVertex.glsl";
	std::string FRAGMENT_FILE = "resources/shaders/simpleFragment.glsl";
	SimpleShader * simpleShader = new SimpleShader(VERTEX_FILE, FRAGMENT_FILE);

	while (true)
	{
		gameEng->update(0.0f);
		sprite.Update();
		gameEng->BeginRender();
		sprite.Render();
		gameEng->EndRender();
	}

	return 0;
}
