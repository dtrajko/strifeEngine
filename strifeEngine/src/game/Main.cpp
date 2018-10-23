#include <iostream>
#include <map>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "../engine/GameEngine.h"
#include "../engine/interfaces/IGameLogic.h"
#include "../engine/WindowOptions.h"
#include "../engine/helloWorld/HelloWorld.h"
#include "../engine/graph/Sprite.h"
#include "../engine/tm/models/CubeMeshSimple.h"

using namespace engine;
using namespace engine::interfaces;
using namespace engine::helloWorld;

int width = 0;
int height = 0;
std::string app = "HelloWorld";

enum AppName
{
	Hello_World
};

static std::map<std::string, AppName> mapAppNames;

bool vSync = false;
IGameLogic * gameLogic;
GameEngine * gameEng;
WindowOptions opts = WindowOptions();

void InitAppNames()
{
	mapAppNames["HelloWorld"] = Hello_World;
}

int main(void)
{
	InitAppNames();

	opts.cullFace = true;
	opts.showFps = true;
	opts.compatibleProfile = true;

	switch (mapAppNames[app])
	{
		case Hello_World:
		{
			std::cout << "HelloWorld app name detected!" << std::endl;
			gameLogic = new HelloWorld();
			opts.mode3D = false;
			opts.cullFace = false;
			opts.antialiasing = false;
			opts.showTriangles = false;
			width = 1280;
			height = 720;
			break;
		}
	}

	std::string appTitle = app.append(" [C++/OpenGL 3D graphics engine]");
	gameEng = new GameEngine(app, width, height, vSync, &opts, gameLogic);
	gameEng->start();
	gameEng->cleanUp();
	delete gameEng;

	return 0;
}
