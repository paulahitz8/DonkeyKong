#include "ModuleCarrots.h"

#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleInput.h"
#include "ModuleRender.h"
#include "ModuleAudio.h"
#include "ModuleCollisions.h"

#include "SDL_scancode.h"


ModuleCarrots::ModuleCarrots(bool startEnabled) : Module(startEnabled)
{

}

ModuleCarrots::~ModuleCarrots() {

}


bool ModuleCarrots::Start()
{
	LOG("Loading player textures");
	carrottexture = App->textures->Load("Assets/Donkey/zanahoria.png");

	/*if (playertexture == nullptr) {
		return false;
	}*/

	carrot.x = 34;
	carrot.y = 66;
	carrot.w = 40;
	carrot.h = 32;

	//colliderC = App->collision->AddCollider({ carrotPosition.x, carrotPosition.y, 40, 32 }, Collider::Type::WALL, this);


	//a�adir sonido con la animacion

	return true;
}

Update_Status ModuleCarrots::Update()
{

	return Update_Status::UPDATE_CONTINUE;
}

Update_Status ModuleCarrots::PostUpdate()
{
	//SDL_Rect rect; ??????
	App->render->Blit(carrottexture, carrotPosition.x, carrotPosition.y, &carrot);

	return Update_Status::UPDATE_CONTINUE;
}


bool ModuleCarrots::CleanUp()
{
	return true;
}