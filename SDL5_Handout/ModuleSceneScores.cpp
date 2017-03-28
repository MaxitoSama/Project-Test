#include "Globals.h"
#include "Application.h"
#include "ModuleSceneHonda.h"
#include "ModuleSceneInit.h"
#include "ModuleSceneKen.h"
#include "ModuleSceneScores.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModuleFadeToBlack.h"
#include "ModuleInput.h"
#include "ModuleAudio.h"
#include "ModuleAudio1.h"
#include "ModulePlayer.h"


// Reference at https://youtu.be/6OlenbCC4WI?t=382

ModuleSceneScores::ModuleSceneScores()
{
	// Background / sky
	backgroundx = 0;
	backgroundy = -256 + SCREEN_HEIGHT;
	background.w = 224;
	background.h = 256;
}

ModuleSceneScores::~ModuleSceneScores()
{}

// Load assets
bool ModuleSceneScores::Start()
{
	LOG("Loading background assets");
	bool ret = true;
	graphics = App->textures->Load("ken_stage.png");

	// TODO 1: Enable (and properly disable) the player module

	App->music->Disable();
	App->music1->Enable();

	return ret;
}

// Load assets
bool ModuleSceneScores::CleanUp()
{
	// TODO 5: Remove all memory leaks
	LOG("Unloading honda stage");

	return true;
}

// Update: draw background
update_status ModuleSceneScores::Update()
{
	// Draw everything --------------------------------------	
	App->render->Blit(graphics, backgroundx, backgroundy, &background, 0.75f);

	int speed = 3;

	if (App->input->keyboard[SDL_SCANCODE_W] == 1)
		if (backgroundy < 0)
			backgroundy += speed;

	if (App->input->keyboard[SDL_SCANCODE_S] == 1)
		if (backgroundy > -256 + SCREEN_HEIGHT)
			backgroundy -= speed;

	// TODO 3: make so pressing SPACE the KEN stage is loaded

	if (App->input->keyboard[SDL_SCANCODE_SPACE] == 1 && fading == false)
	{
		App->fade->FadeToBlack(this, App->scene_init, 2.0f);
		fading == true;
		backgroundx = 0;
		backgroundy = -256 + SCREEN_HEIGHT;
	}

	return UPDATE_CONTINUE;
}