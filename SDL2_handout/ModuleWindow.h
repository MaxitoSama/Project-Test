#ifndef __ModuleWindow_H__
#define __ModuleWindow_H__

#include "SDL/include/SDL.h"

// TODO 1: Create the declaration of ModuleWindow class

//class SDL_Window;

class ModuleWindow: public Module
{
public:
	bool Init();
	bool CleanUp() { return true; }

private:
	SDL_Window*window = nullptr;
};

#endif // __ModuleWindow_H__