#include "ModuleLady.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleInput.h"
#include "ModuleRender.h"
#include "ModuleAudio.h"

#include "SDL_scancode.h"

ModuleLady::ModuleLady(bool startEnabled) : Module(startEnabled)
{

}

ModuleLady::~ModuleLady() {

}


bool ModuleLady::Start()
{
	LOG("Loading player textures");
	ladytexture = App->textures->Load("Assets/Donkey/DKAPaulineSprite.png");

	/*if (playertexture == nullptr) {
		return false;
	}*/

	lady.x = 0;
	lady.y = 0;
	lady.w = 12;
	lady.h = 16;

	return true;
}

Update_Status ModuleLady::Update()
{
	return Update_Status::UPDATE_CONTINUE;
}

Update_Status ModuleLady::PostUpdate()
{
	App->render->Blit(ladytexture, ladyPosition.x, ladyPosition.y, &lady, 0);

	return Update_Status::UPDATE_CONTINUE;
}


bool ModuleLady::CleanUp()
{
	return true;
}
