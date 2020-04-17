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

}

ModuleEnemies::~ModuleEnemies() {

}


bool ModuleEnemies::Start()
{
	LOG("Loading player textures");
	fireballstexture = App->textures->Load("Assets/Enemies/Enemies2.png");

	/*if (playertexture == nullptr) {
		return false;
	}*/

	fireballs.x = 34;
	fireballs.y = 66;
	fireballs.w = 40;
	fireballs.h = 32;

	return true;
}

Update_Status ModuleEnemies::Update()
{
	return Update_Status::UPDATE_CONTINUE;
}

Update_Status ModuleEnemies::PostUpdate()
{
	App->render->Blit(fireballstexture, position.x, position.y, &fireballs, 0);
	return Update_Status::UPDATE_CONTINUE;
}

bool ModuleEnemies::CleanUp()
{
	return true;
}


