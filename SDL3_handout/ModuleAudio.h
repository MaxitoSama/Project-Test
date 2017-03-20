#ifndef _ModuleAudio_H_
#define _ModuleAudio_H_

#include "Module.h"
#include "Globals.h"

#define MAX_TRACKS 50

struct MIX_Music;

class ModuleAudio: public Module
{
public:
	ModuleAudio();
	~ModuleAudio();

	bool Init();
	bool CleanUp();
	Mix_Music* const Load(const char* path);

public:
	Mix_Music* musica[MAX_TRACKS];
	int last_track = 0;
};

#endif