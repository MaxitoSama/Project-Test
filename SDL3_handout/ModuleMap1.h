#ifndef __MODULESCENEKEN_H__
#define __MODULESCENEKEN_H__

#include "Module.h"
#include "Globals.h"
#include "ModuleInput.h"
#include "SDL\include\SDL.h"


struct SDL_Texture;
struct SDL_Rect;

class ModuleMap1 : public Module
{
public:
	ModuleMap1();
	~ModuleMap1();

	bool Start();
	update_status Update();
	bool CleanUp();

public:

	SDL_Texture* graphics = nullptr;
	SDL_Rect fons;
	int fonsy, fonsx;
	bool fading;
	float foreground_pos;
	bool forward;
};

#endif // __MODULESCENEKEN_H__