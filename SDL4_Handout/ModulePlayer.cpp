#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleInput.h"
#include "ModuleRender.h"
#include "ModulePlayer.h"

// Reference at https://www.youtube.com/watch?v=OEhmUuehGOA

ModulePlayer::ModulePlayer()
{
	position.x = 100;
	position.y = 220;

	// idle animation (arcade sprite sheet)
	idle.PushBack({7, 14, 60, 90});
	idle.PushBack({95, 15, 60, 89});
	idle.PushBack({184, 14, 60, 90});
	idle.PushBack({276, 11, 60, 93});
	idle.PushBack({366, 12, 60, 92});
	idle.speed = 0.2f;

	// walk forward animation (arcade sprite sheet)
	//forward.frames.PushBack({9, 136, 53, 83});
	forward.PushBack({78, 131, 60, 88});
	forward.PushBack({162, 128, 64, 92});
	forward.PushBack({259, 128, 63, 90});
	forward.PushBack({352, 128, 54, 91});
	forward.PushBack({432, 131, 50, 89});
	forward.speed = 0.1f;

	//Backward
	backward.PushBack({ 536, 127, 76, 94 });
	backward.PushBack({ 625, 126, 76, 94 });
	backward.PushBack({ 710, 126, 76, 94 });
	backward.PushBack({ 796, 126, 76, 94 });
	backward.PushBack({ 882, 126, 76, 94 });
	backward.PushBack({ 973, 126, 76, 94 });
	backward.speed = 0.1f;

	//Punch
	Punch.PushBack({ 13, 270, 79, 94 });
	Punch.PushBack({ 107, 270, 94, 94 });
	Punch.speed = 0.07f;

	//Jump
	Jump.PushBack({ 17, 798, 56, 134 });
	Jump.PushBack({ 100, 798, 56, 134 });
	Jump.PushBack({ 176, 798, 56, 134 });
	Jump.PushBack({ 251, 798, 56, 134 });
	Jump.PushBack({ 327, 798, 56, 134 });
	Jump.PushBack({ 397, 798, 56, 134 });
	Jump.PushBack({ 465, 798, 56, 134 });
	Jump.speed = 0.1f;

	// TODO 4: Make ryu walk backwards with the correct animations
}

ModulePlayer::~ModulePlayer()
{}

// Load assets
bool ModulePlayer::Start()
{
	LOG("Loading player textures");
	bool ret = true;
	graphics = App->textures->Load("ryu.png"); // arcade version
	return ret;
}

// Update: draw background
update_status ModulePlayer::Update()
{
	Animation* current_animation = &idle;

	int speed = 1;

	if (App->input->keyboard[SDL_SCANCODE_Q] == 1)
	{
		punch = true;
	}
	if (App->input->keyboard[SDL_SCANCODE_SPACE] == 1)
	{
		jump = true;
	}
	if (App->input->keyboard[SDL_SCANCODE_D] == 1)
	{
		current_animation = &forward;
		position.x += speed;
	}
	if (App->input->keyboard[SDL_SCANCODE_A] == 1)
	{
		current_animation = &backward;
		position.x -= speed;
	}
	
	if (punch)
	{
		current_animation = &Punch;
		time_counter++;
		if(time_counter==29)
		{
			time_counter = 0;
			punch = false;
		}
	}
	else if (jump)
	{
		current_animation = &Jump;
		time_counter++;
		if (time_counter == 72)
		{
			time_counter = 0;
			jump = false;
		}
	}
	
		

	
	// Draw everything --------------------------------------
	
	SDL_Rect r = current_animation->GetCurrentFrame();
	App->render->Blit(graphics, position.x, position.y - r.h, &r);
	
	
	
	return UPDATE_CONTINUE;
}
