#ifndef __MODULESCENESCORES_H__
#define __MODULESCENESCORES__

#include "Module.h"
#include "Animation.h"
#include "Globals.h"

struct SDL_Texture;

class ModuleSceneScores : public Module
{
public:
	ModuleSceneScores();
	~ModuleSceneScores();

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

#endif // __MODULESCESCORES_H__