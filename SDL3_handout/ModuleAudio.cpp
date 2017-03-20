#include "Globals.h"
#include "Application.h"
#include "ModuleAudio.h"
#include "ModuleRender.h"
#include "SDL/include/SDL.h"

#include "SDL_mixer\include\SDL_mixer.h"

#pragma comment( lib, "SDL_mixer/libx86/SDL2_mixer.lib" )


ModuleAudio::ModuleAudio():Module()
{
	for (int i = 0; i <= MAX_TRACKS; i++)
		musica[i] = nullptr;
}


ModuleAudio::~ModuleAudio()
{
}

bool ModuleAudio::Init()
{
	LOG("Init Image library");
	bool ret = true;

	// load support for the PNG image format
	int flags = MIX_INIT_OGG;
	Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);

	if ((flags) != flags)
	{
		LOG("Could not initialize MUSIC lib. MIX_INIT_OGG: %s", SDL_GetError());
		ret = false;
	}
	return ret;
}
bool ModuleAudio::CleanUp()
{
	LOG("Freeing textures and Image library");
	// TODO 6: Free all textures
	for (int i = 0; i <= last_track; i++)
		Mix_FreeMusic(musica[i]);
	
	Mix_CloseAudio();
	Mix_Quit();
	return true;
}

Mix_Music* const ModuleAudio::Load(const char* path)
{
	Mix_Music* music = Mix_LoadMUS(path);
	if (music == nullptr)
	{
		LOG("Error with the music %s", path);
	}
	else {
		musica[last_track++] = music;
	}
	return nullptr;
}