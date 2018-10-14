#include <iostream>
#include <map>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "../engine/GameEngine.h"
#include "../engine/interfaces/IGameLogic.h"
#include "../engine/WindowOptions.h"
#include "../engine/helloWorld/HelloWorld.h"

int width = 0;
int height = 0;
std::string app = "HelloWorld"; // ThinMatrix

enum AppName
{
	HelloWorld,
	ThinMatrix,
};

static std::map<std::string, AppName> mapAppNames;

bool vSync = false;
engine::interfaces::IGameLogic* gameLogic;
engine::GameEngine* gameEng;
engine::WindowOptions* opts = new engine::WindowOptions();

void InitAppNames()
{
	mapAppNames["HelloWorld"] = HelloWorld;
	mapAppNames["ThinMatrix"] = ThinMatrix;
}

int main(void)
{
	InitAppNames();

	opts->cullFace = true;
	opts->showFps = true;
	opts->compatibleProfile = true;

	switch (mapAppNames[app])
	{
		case HelloWorld:
		{
			std::cout << "HelloWorld app name detected!" << std::endl;
			break;
		}
		case ThinMatrix:
		{
			std::cout << "ThinMatrix app name detected!" << std::endl;
			gameLogic = new engine::helloWorld::HelloWorld();
			opts->mode3D = true;
			opts->cullFace = false;
			opts->antialiasing = true;
			width = height = 0;
			break;
		}
	}

	gameEng = new engine::GameEngine(app, width, height, vSync, opts, gameLogic);

	std::cin.get();
}
