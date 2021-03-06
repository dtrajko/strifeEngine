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

#include "../engine/minecraft/Minecraft.h"

using namespace engine;
using namespace engine::interfaces;
using namespace engine::helloWorld;
using namespace engine::minecraft;

int width = 0;
int height = 0;
std::string app = "HelloWorld";

enum AppName
{
	Hello_World,
	Minecraft,
};

static std::map<std::string, AppName> mapAppNames;

bool vSync = false;
IGameLogic * gameLogic = nullptr;
GameEngine * gameEng = nullptr;
WindowOptions opts = WindowOptions();

void InitAppNames()
{
	mapAppNames["HelloWorld"] = AppName::Hello_World;
	mapAppNames["Minecraft"] = AppName::Minecraft;
}

int main(void)
{
	InitAppNames();

	opts.cullFace = true;
	opts.showFps = true;
	opts.compatibleProfile = true;
	opts.maximized = false;

	switch (mapAppNames[app])
	{
		case AppName::Hello_World:
		{
			std::cout << "HelloWorld app name detected!" << std::endl;
			gameLogic = &helloWorld::HelloWorld();
			opts.mode3D = true;
			opts.cullFace = false;
			opts.antialiasing = false;
			opts.showTriangles = false;
			opts.maximized = true;
			width = 1920;
			height = 1020;
			break;
		}

		case AppName::Minecraft:
		{
			std::cout << "Minecraft app name detected!" << std::endl;
			gameLogic = &minecraft::Minecraft();
			opts.mode3D = true;
			opts.cullFace = false;
			opts.antialiasing = false;
			opts.showTriangles = false;
			opts.maximized = true;
			width = 1920;
			height = 1020;
			break;
		}

	}

	std::string appTitle = app.append(" [C++/OpenGL 3D graphics engine]");
	gameEng = &GameEngine(app, width, height, vSync, &opts, gameLogic);
	gameEng->start();
	gameEng->cleanUp();

	return 0;
}
