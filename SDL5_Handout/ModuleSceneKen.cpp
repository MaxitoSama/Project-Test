#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModuleSceneKen.h"
#include "ModuleSceneHonda.h"
#include "ModulePlayer.h"
#include "ModuleFadeToBlack.h"
#include "ModuleAudio.h"
#include "ModuleAudio1.h"
#include "Module.h"
#include "ModuleInput.h"



// Reference at https://www.youtube.com/watch?v=OEhmUuehGOA

ModuleSceneKen::ModuleSceneKen()
{
	// Background / sky
	backgroundx = 0;
	backgroundy = -2066+SCREEN_HEIGHT;
	background.w = 225;
	background.h = 2066;

}

ModuleSceneKen::~ModuleSceneKen()
{}

// Load assets
bool ModuleSceneKen::Start()
{
	LOG("Loading ken scene");
	
	graphics = App->textures->Load("Area1.png");

	// TODO 1: Enable (and properly disable) the player module
	
	App->music1->Disable();
	App->music->Enable();

	return true;
}


// UnLoad assets
bool ModuleSceneKen::CleanUp()
{
	LOG("Unloading ken scene");

	return true;
}

// Update: draw background
update_status ModuleSceneKen::Update()
{
	// Draw everything --------------------------------------
	App->render->Blit(graphics, backgroundx, backgroundy, &background, 0.75f);

	int speed = 3;

	if (App->input->keyboard[SDL_SCANCODE_W] == 1)
		if (backgroundy < 0)
			backgroundy += speed;

	if (App->input->keyboard[SDL_SCANCODE_S] == 1)
		if (backgroundy > -2066 + SCREEN_HEIGHT)
			backgroundy -= speed;


	// TODO 3: make so pressing SPACE the HONDA stage is loaded
	if (App->input->keyboard[SDL_SCANCODE_SPACE] == 1 && fading==false)
	{
		App->fade->FadeToBlack(this, App->scene_honda, 2.0f);
		fading == true;
		backgroundx = 0;
		backgroundy = -2066 + SCREEN_HEIGHT;
	}
	return UPDATE_CONTINUE;
}