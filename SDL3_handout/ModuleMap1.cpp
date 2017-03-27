#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModuleMap1.h"
#include "ModuleMap2.h"
#include "ModuleFadeToBlack.h"
#include "ModuleAudio.h"
#include "Module.h"
#include "ModuleInput.h"



// Reference at https://www.youtube.com/watch?v=OEhmUuehGOA

ModuleMap1::ModuleMap1()
{
	fons.h = 3262;
	fons.w = 360;
	fonsx = 0;
	fonsy = -3262 + SCREEN_HEIGHT;
}

ModuleMap1::~ModuleMap1()
{}

// Load assets
bool ModuleMap1::Start()
{
	LOG("Loading ken scene");

	graphics = App->textures->Load("Area1.png");

	// TODO 1: Enable (and properly disable) the player module

	App->music->Enable();

	return true;
}

// UnLoad assets
bool ModuleMap1::CleanUp()
{
	LOG("Unloading ken scene");
	Disable();

	return true;
}

// Update: draw background
update_status ModuleMap1::Update()
{
	// Draw everything --------------------------------------
	App->render->Blit(graphics, 0, 0, &fons); // sea and sky
	

	// TODO 3: make so pressing SPACE the HONDA stage is loaded
	if (App->input->keyboard[SDL_SCANCODE_SPACE] == 1 && fading == false)
	{
		App->fade->FadeToBlack(this, App->map2, App->music, App->music, 2.0f);
		fading == true;
	}
	return UPDATE_CONTINUE;
}