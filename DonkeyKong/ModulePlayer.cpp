#include "ModulePlayer.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleInput.h"
#include "ModuleRender.h"
#include "ModuleAudio.h"
#include "SDL_scancode.h"

ModulePlayer::ModulePlayer(bool startEnabled) : Module(startEnabled)
{
	// left idle
	leftidleAnim.PushBack({ 56, 2, 12, 16 });

	//right idle
	rightidleAnim.PushBack({ 188, 128, 12, 16 });

	// left animation
	leftAnim.PushBack({ 79, 2, 15, 16 });
	leftAnim.PushBack({ 103, 2, 15, 15 });
	leftAnim.loop = false;
	leftAnim.speed = 0.1f;


	//right animation
	rightAnim.PushBack({ 162, 128, 15, 16 });
	rightAnim.PushBack({ 138, 128, 15, 15 });
	rightAnim.loop = false;
	rightAnim.pingpong = true;
	rightAnim.speed = 0.1f;
}

ModulePlayer::~ModulePlayer() {

}


bool ModulePlayer::Start()
{
	LOG("Loading player textures");
	playertexture = App->textures->Load("Assets/Mario/mariosprites.png");
	currentAnimation = &rightAnim; //mario empieza mirando a la derecha
	
								   
	 /*if (playertexture == nullptr) {
		return false;
	}*/

	player.x = 56;
	player.y = 2;
	player.w = 12;
	player.h = 16;

	return true;
}

Update_Status ModulePlayer::Update()
{
	if (currentAnimation == &rightAnim) {
		rightAnim.Reset();
		currentAnimation = &rightidleAnim;
	}

	if (currentAnimation == &leftAnim) {
		leftAnim.Reset();
		currentAnimation = &leftidleAnim;
	}

	if (App->input->keys[SDL_SCANCODE_UP] == KEY_REPEAT) {
		position.y--;
	}
	if (App->input->keys[SDL_SCANCODE_DOWN] == KEY_REPEAT) {
		position.y++;
	}
	if (App->input->keys[SDL_SCANCODE_LEFT] == KEY_REPEAT) {
		position.x--;
		if (currentAnimation != &leftAnim) {
			leftAnim.Reset();
			currentAnimation = &leftAnim;
			
		}
	}

	if (App->input->keys[SDL_SCANCODE_RIGHT] == KEY_REPEAT) {
		position.x++;
		if (currentAnimation != &rightAnim) {
			rightAnim.Reset();
			currentAnimation = &rightAnim;
		}
	}

	currentAnimation->Update();

	return Update_Status::UPDATE_CONTINUE;
}

Update_Status ModulePlayer::PostUpdate()
{
	SDL_Rect rect = currentAnimation->GetCurrentFrame();
	App->render->Blit(playertexture, position.x, position.y, &rect, 0);
	
	return Update_Status::UPDATE_CONTINUE;
}

bool ModulePlayer::CleanUp()
{
	return true;
}


