#ifndef __APPLICATION_H__
#define __APPLICATION_H__

#include "Globals.h"

#define NUM_MODULES 12

class ModuleWindow;
class ModuleInput;
class ModuleTextures;
class ModuleRender;
class ModuleSceneKen;
class ModuleSceneHonda;
class ModuleSceneInit;
class ModuleSceneScores;
class ModuleInit;
class ModulePlayer;
class ModuleFadeToBlack;
class ModuleAudio;
class ModuleAudio1;
class Module;

class Application
{
public:

	Module* modules[NUM_MODULES];
	ModuleWindow* window;
	ModuleRender* render;
	ModuleInput* input;
	ModuleTextures* textures;
	ModuleSceneKen* scene_ken;
	ModuleSceneHonda* scene_honda;
	ModuleSceneInit* scene_init;
	ModuleSceneScores* scene_scores;
	ModulePlayer* player;
	ModuleFadeToBlack* fade;
	ModuleAudio* music;
	ModuleAudio1* music1;
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