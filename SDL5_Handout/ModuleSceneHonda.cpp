#include "Globals.h"
#include "Application.h"
#include "ModuleSceneHonda.h"
#include "ModuleSceneKen.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModuleFadeToBlack.h"
#include "ModuleInput.h"
#include "ModuleAudio.h"
#include "ModulePlayer.h"

// Reference at https://youtu.be/6OlenbCC4WI?t=382

ModuleSceneHonda::ModuleSceneHonda()
{
	// Background / sky
	backgroundx = 0;
	backgroundy = -3256 + SCREEN_HEIGHT;
	background.w = 360;
	background.h = 3262;
}

ModuleSceneHonda::~ModuleSceneHonda()
{}

// Load assets
bool ModuleSceneHonda::Start()
{
	LOG("Loading background assets");
	bool ret = true;
	graphics = App->textures->Load("Area2.png");

	// TODO 1: Enable (and properly disable) the player module
	
	App->music->Enable();

	return ret;
}

// Load assets
bool ModuleSceneHonda::CleanUp()
{
	// TODO 5: Remove all memory leaks
	LOG("Unloading honda stage");

	return true;
}

// Update: draw background
update_status ModuleSceneHonda::Update()
{
	// Draw everything --------------------------------------	
	App->render->Blit(graphics, backgroundx, backgroundy, &background, 0.75f);

	int speed = 3;

	if (App->input->keyboard[SDL_SCANCODE_W] == 1)
		if (backgroundy < 0)
			backgroundy += speed;

	if (App->input->keyboard[SDL_SCANCODE_S] == 1)
		if (backgroundy > -3262 + SCREEN_HEIGHT)
			backgroundy -= speed;

	// TODO 3: make so pressing SPACE the KEN stage is loaded

	if (App->input->keyboard[SDL_SCANCODE_SPACE] == 1 && fading==false)
	{
		App->fade->FadeToBlack(this, App->scene_ken, App->music, App->music, 2.0f);
		fading == true;
		backgroundx = 0;
		backgroundy = -3256 + SCREEN_HEIGHT;
	}

	return UPDATE_CONTINUE;
}