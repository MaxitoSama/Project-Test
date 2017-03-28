#pragma once
#ifndef _ModuleAudio1_H_
#define _ModuleAudio1_H_

#include "Module.h"
#include "Globals.h"
#include "SDL_mixer\include\SDL_mixer.h"

#define MAX_TRACKS 50

class ModuleAudio1 : public Module
{
public:
	ModuleAudio1();
	virtual~ModuleAudio1();

	bool Start();
	bool CleanUp();
	Mix_Music* const Load(const char* path);
	void Close();

public:
	Mix_Music* musica[MAX_TRACKS];
	int last_track = 0;
};
#endif