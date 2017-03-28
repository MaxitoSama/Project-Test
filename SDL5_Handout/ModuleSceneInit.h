#ifndef __MODULESCENEINIT_H__
#define __MODULESCENEINIT__

#include "Module.h"
#include "Animation.h"
#include "Globals.h"

struct SDL_Texture;

class ModuleSceneInit : public Module
{
public:
	ModuleSceneInit();
	~ModuleSceneInit();

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

#endif // __MODULESCENEINIT_H__