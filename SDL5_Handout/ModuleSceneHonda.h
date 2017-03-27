#ifndef __MODULESCENEHONDA_H__
#define __MODULESCENEHONDA_H__

#include "Module.h"
#include "Animation.h"
#include "Globals.h"

struct SDL_Texture;

class ModuleSceneHonda : public Module
{
public:
	ModuleSceneHonda();
	~ModuleSceneHonda();

	bool Start();
	update_status Update();
	bool CleanUp();

public:

	SDL_Texture* graphics = nullptr;
	SDL_Rect background;
	int backgroundx = 0;
	int backgroundy = 0;
	bool fading;
};

#endif // __MODULESCENEHONDA_H__