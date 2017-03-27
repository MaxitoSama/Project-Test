#ifndef __MODULESCENEHONDA_H__
#define __MODULESCENEHONDA_H__

#include "Module.h"
#include "Globals.h"
#include "ModuleInput.h"
#include "SDL\include\SDL.h"

struct SDL_Texture;

class ModuleMap2 : public Module
{
public:
	ModuleMap2();
	~ModuleMap2();

	bool Start();
	update_status Update();
	bool CleanUp();

public:

	SDL_Texture* graphics = nullptr;
	SDL_Rect fons;
	int fonsy, fonsx;
	bool fading;
};

#endif // __MODULESCENEHONDA_H__