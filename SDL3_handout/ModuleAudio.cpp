#include "Globals.h"
#include "Application.h"
#include "ModuleAudio.h"
#include "SDL/include/SDL.h"


ModuleAudio::ModuleAudio():Module()
{
}


ModuleAudio::~ModuleAudio()
{
}

bool ModuleAudio::Init()
{
	LOG("Init Image library");
	bool ret = true;

	// load support for the PNG image format
	int flags = IMG_INIT_PNG;
	int init = IMG_Init(flags);

	if ((init & flags) != flags)
	{
		LOG("Could not initialize Image lib. IMG_Init: %s", IMG_GetError());
		ret = false;
	}
	bool ModuleTextures::CleanUp()
	{
		LOG("Freeing textures and Image library");
		// TODO 6: Free all textures
		for (int i = 0; i <= last_texture; i++)
			SDL_DestroyTexture(textures[i]);


		IMG_Quit();
		return true;
	}

	return ret;
}