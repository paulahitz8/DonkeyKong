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
	ladytexture = App->textures->Load("Assets/Lady/PaulineSprites.png");

	/*if (playertexture == nullptr) {
		return false;
	}*/

	lady.x = 72;
	lady.y = 116;
	lady.w = 15;
	lady.h = 22;

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
