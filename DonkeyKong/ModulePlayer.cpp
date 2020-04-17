#include "ModulePlayer.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleInput.h"
#include "ModuleRender.h"
#include "ModuleAudio.h"
#include "ModuleFadeToBlack.h"

#include "SDL_scancode.h"

ModulePlayer::ModulePlayer(bool startEnabled) : Module(startEnabled)
{
	position.x = { 46 };
	position.y = { 232 };
	// left idle
	leftidleAnim.PushBack({ 37, 68, 12, 26 });
	//right idle
	rightidleAnim.PushBack({ 207, 194, 12, 26 });
	// left animation
	leftAnim.PushBack({ 59, 78, 30, 16 });
	leftAnim.PushBack({ 101, 68, 13, 26 });
	leftAnim.PushBack({ 59, 78, 30, 16 });
	leftAnim.speed = 0.1f;


	//right animation
	rightAnim.PushBack({ 167, 204, 30, 16 });
	rightAnim.PushBack({ 142, 194, 13, 26 });
	rightAnim.PushBack({ 167, 204, 30, 16 });
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


	walkingFx = App->audio->LoadFx("Assets/Music/15 SFX (Wave).wav");

	return true;
}

Update_Status ModulePlayer::Update()
{
	
	if (currentAnimation == &rightAnim) {

		currentAnimation = &rightidleAnim;
	}

	if (currentAnimation == &leftAnim) {
		
		currentAnimation = &leftidleAnim;
	}

	if (App->input->keys[SDL_SCANCODE_UP] == KEY_REPEAT) {
		position.y--;
	}
	if (App->input->keys[SDL_SCANCODE_DOWN] == KEY_REPEAT) {
		position.y++;
	}
	if (App->input->keys[SDL_SCANCODE_RIGHT] == KEY_REPEAT && App->input->keys[SDL_SCANCODE_LEFT] == KEY_REPEAT) {
		currentAnimation = &rightidleAnim;
	}
	else if (App->input->keys[SDL_SCANCODE_LEFT] == KEY_REPEAT) {
		position.x--;
	
			currentAnimation = &leftAnim;
			App->audio->PlayFx(walkingFx);
	}

	else if (App->input->keys[SDL_SCANCODE_RIGHT] == KEY_REPEAT) {
		position.x++;
	
			currentAnimation = &rightAnim;
			App->audio->PlayFx(walkingFx);
	}
	

	leftAnim.Update();
	rightAnim.Update();
	leftidleAnim.Update();
	rightidleAnim.Update();

	return Update_Status::UPDATE_CONTINUE;
}

Update_Status ModulePlayer::PostUpdate()
{
	SDL_Rect rect = currentAnimation->GetCurrentFrame();
	if (currentAnimation == &rightidleAnim) {
		App->render->Blit(playertexture, position.x, position.y, &(rightidleAnim.GetCurrentFrame()), 0);
	
	}
	if (currentAnimation == &leftidleAnim) {
		App->render->Blit(playertexture, position.x, position.y, &(leftidleAnim.GetCurrentFrame()), 0);
	
	}

	if (App->input->keys[SDL_SCANCODE_LEFT] == KEY_REPEAT && currentAnimation != &rightidleAnim) {
		App->render->Blit(playertexture, position.x, position.y, &(leftAnim.GetCurrentFrame()), 0);
		
	}
	if (App->input->keys[SDL_SCANCODE_RIGHT] == KEY_REPEAT && currentAnimation != &rightidleAnim) {
		App->render->Blit(playertexture, position.x, position.y, &(rightAnim.GetCurrentFrame()), 0);
		
	}


	return Update_Status::UPDATE_CONTINUE;
}

bool ModulePlayer::CleanUp()
{
	return true;
}


