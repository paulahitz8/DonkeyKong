#include "ModuleEnemies.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleInput.h"
#include "ModuleRender.h"
#include "ModuleAudio.h"
#include "ModuleCollisions.h"

#include "SDL_scancode.h"

ModuleEnemies::ModuleEnemies(bool startEnabled) : Module(startEnabled)
{
	leftAnim.PushBack({ 120, 160, 20, 20 });
	leftAnim.PushBack({ 145, 160, 20, 20 });
	leftAnim.speed = 0.2;
}

ModuleEnemies::~ModuleEnemies() {

}


bool ModuleEnemies::Start()
{
	LOG("Loading player textures");
	fireballstexture = App->textures->Load("Assets/Enemies/Enemies2.png");

	currentAnimation = &leftAnim;

	/*if (playertexture == nullptr) {
		return false;
	}*/

	fireballs.x = 120;
	fireballs.y = 160;
	fireballs.w = 20;
	fireballs.h = 20;

	destroyed = false;

	return true;
}

Update_Status ModuleEnemies::Update()
{
	currentAnimation = &leftAnim;

	currentAnimation->Update();

	return Update_Status::UPDATE_CONTINUE;
}

Update_Status ModuleEnemies::PostUpdate()
{
	if (!destroyed)
	{
		SDL_Rect rect = currentAnimation->GetCurrentFrame();
		App->render->Blit(fireballstexture, position.x, position.y, &rect);
	}

	return Update_Status::UPDATE_CONTINUE;
}

bool ModuleEnemies::CleanUp()
{
	return true;
}


