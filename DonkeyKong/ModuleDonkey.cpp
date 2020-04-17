#include "ModuleDonkey.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleInput.h"
#include "ModuleRender.h"
#include "ModuleAudio.h"
#include "ModuleCollisions.h"

#include "SDL_scancode.h"

ModuleDonkey::ModuleDonkey(bool startEnabled) : Module(startEnabled)
{

}

ModuleDonkey::~ModuleDonkey() {

}


bool ModuleDonkey::Start()
{
	LOG("Loading player textures");
	donkeytexture = App->textures->Load("Assets/Donkey/DonkeyKongSprites2.png");

	/*if (playertexture == nullptr) {
		return false;
	}*/

	donkey.x = 34;
	donkey.y = 66;
	donkey.w = 40;
	donkey.h = 32;

	colliderD = App->collision->AddCollider({ donkeyPosition.x, donkeyPosition.y, 40, 32 }, Collider::Type::ENEMY, this);

	return true;
}

Update_Status ModuleDonkey::Update()
{
	return Update_Status::UPDATE_CONTINUE;
}

Update_Status ModuleDonkey::PostUpdate()
{
	App->render->Blit(donkeytexture, donkeyPosition.x, donkeyPosition.y, &donkey, 0);

	return Update_Status::UPDATE_CONTINUE;
}


bool ModuleDonkey::CleanUp()
{
	return true;
}


