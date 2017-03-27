#include "Globals.h"
#include "Application.h"
#include "ModuleMap2.h"
#include "ModuleMap1.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModuleFadeToBlack.h"
#include "ModuleInput.h"
#include "ModuleAudio.h"

// Reference at https://youtu.be/6OlenbCC4WI?t=382

ModuleMap2::ModuleMap2()
{
	fons.h = 3262;
	fons.w = 360;
	fonsx = 0;
	fonsy = -3262 + SCREEN_HEIGHT;
}

ModuleMap2::~ModuleMap2()
{}

// Load assets
bool ModuleMap2::Start()
{
	LOG("Loading background assets");
	bool ret = true;
	graphics = App->textures->Load("Area2.png");

	// TODO 1: Enable (and properly disable) the player module

	App->music->Enable();

	return ret;
}

// Load assets
bool ModuleMap2::CleanUp()
{
	// TODO 5: Remove all memory leaks
	LOG("Unloading honda stage");

	return true;
}

// Update: draw background
update_status ModuleMap2::Update()
{
	// Draw everything --------------------------------------	
	App->render->Blit(graphics, 0, 160, &fons);
	

	// TODO 3: make so pressing SPACE the KEN stage is loaded

	if (App->input->keyboard[SDL_SCANCODE_SPACE] == 1 && fading == false)
	{
		App->fade->FadeToBlack(this, App->map1, App->music, App->music, 2.0f);
		fading == true;
	}

	return UPDATE_CONTINUE;
}