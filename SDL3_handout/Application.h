#ifndef __APPLICATION_H__
#define __APPLICATION_H__

#include "Globals.h"

#define NUM_MODULES 8

class ModuleWindow;
class ModuleInput;
class ModuleTextures;
class ModuleRender;
class ModuleMap1;
class ModuleMap2;
class ModulePlayer;
class ModuleFadeToBlack;
class ModuleAudio;
class Module;

class Application
{
public:

	Module* modules[NUM_MODULES];
	ModuleWindow* window;
	ModuleRender* render;
	ModuleInput* input;
	ModuleTextures* textures;
	ModuleMap1* map1;
	ModuleMap2* map2;
	ModulePlayer* player;
	ModuleFadeToBlack* fade;
	ModuleAudio* music;

public:

	Application();
	~Application();

	bool Init();
	update_status Update();
	bool CleanUp();

};

// Global var made extern for Application ---
extern Application* App;

#endif // __APPLICATION_H__