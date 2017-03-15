#include "Globals.h"
#include "Application.h"
#include "SDL/include/SDL.h"
#include "ModuleWindow.h"

// TODO 2: Init the library and check for possible error
// using SDL_GetError()

bool ModuleWindow::Init()
{
	bool ret = true;
	SDL_Window* window;

	if (SDL_Init(SDL_INIT_VIDEO) != 0)
	{
		LOG("Could not create window: %s\n", SDL_GetError());
		ret = false;
	}
	else {

		window = SDL_CreateWindow("Max", 0, 0, 400, 400, SDL_WINDOW_OPENGL);
	}
	return ret;
}
// TODO 3: pick the width and height and experiment with flags: borderless / fullscreen / resizable,
// then create the window and check for errors

// TODO 4: Finally create a screen surface and keep it as a public variable

// TODO 5: Fill with code CleanUp() method :)

