#include "ModuleCarrots.h"

#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleInput.h"
#include "ModuleRender.h"
#include "ModuleAudio.h"
#include "ModuleCollisions.h"

#include "SDL_scancode.h"


ModuleCarrot::ModuleCarrot(bool startEnabled) : Module(startEnabled)
{

}

ModuleCarrot::~ModuleCarrot() {

}


bool ModuleCarrot::Start()
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


	//añadir sonido con la animacion

	return true;
}

Update_Status ModuleCarrot::Update()
{

	return Update_Status::UPDATE_CONTINUE;
}

Update_Status ModuleCarrot::PostUpdate()
{
	//SDL_Rect rect; ??????
	App->render->Blit(carrottexture, carrotPosition.x, carrotPosition.y, &carrot);

	return Update_Status::UPDATE_CONTINUE;
}


bool ModuleCarrot::CleanUp()
{
	return true;
}