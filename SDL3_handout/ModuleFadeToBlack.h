#ifndef __MODULEFADETOBLACK_H__
#define __MODULEFADETOBLACK_H__

#include "Module.h"
#include "SDL\include\SDL_rect.h"

class ModuleFadeToBlack : public Module
{
public:
	ModuleFadeToBlack();
	~ModuleFadeToBlack();

	bool Start();
	update_status Update();
	bool FadeToBlack(Module* module_off, Module* module_on, Module* music_on, Module* music_off, float time);

private:

	enum fade_step
	{
		none,
		fade_to_black,
		fade_from_black
	} current_step = fade_step::none;

	Uint32 start_time = 0;
	Uint32 total_time = 0;
	SDL_Rect screen;
	Module* module1;
	Module* module2;
	Module* music1;
	Module* music2;
};

#endif //__MODULEFADETOBLACK_H__