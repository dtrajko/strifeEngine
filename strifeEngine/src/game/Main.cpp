#include <iostream>
#include <map>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "../engine/GameEngine.h"
#include "../engine/interfaces/IGameLogic.h"
#include "../engine/WindowOptions.h"
#include "../engine/helloWorld/HelloWorld.h"
#include "../engine/helloWorld/Cherno.h"
#include "../engine/graph/Sprite.h"
#include "../engine/tm/models/CubeMeshSimple.h"

using namespace engine;
using namespace engine::interfaces;

int width = 0;
int height = 0;
std::string app = "TheCherno"; // TheCherno, HelloWorld, ThinMatrix

enum AppName
{
	Hello_World,
	Thin_Matrix,
	The_Cherno,
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
	mapAppNames["TheCherno"] = The_Cherno;
}

int main(void)
{
	InitAppNames();

	opts->cullFace = true;
	opts->showFps = true;
	opts->compatibleProfile = true;

	switch (mapAppNames[app])
	{
		case The_Cherno:
		{
			std::cout << "Cherno app name detected!" << std::endl;
			gameLogic = new engine::helloWorld::Cherno();
			opts->mode3D = true;
			opts->cullFace = false;
			opts->antialiasing = true;
			opts->showTriangles = true;
			width = 1280;
			height = 720;
			break;
		}
		case Hello_World:
		{
			std::cout << "HelloWorld app name detected!" << std::endl;
			gameLogic = new engine::helloWorld::HelloWorld();
			opts->mode3D = true;
			opts->cullFace = false;
			opts->antialiasing = true;
			opts->showTriangles = true;
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
	gameEng->start();

	return 0;
}
