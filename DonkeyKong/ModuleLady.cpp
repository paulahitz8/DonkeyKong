#include "ModuleLady.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleInput.h"
#include "ModuleRender.h"
#include "ModuleAudio.h"

#include "SDL_scancode.h"

ModuleLady::ModuleLady(bool startEnabled) : Module(startEnabled)
{
	//lady idle
	ladyidleAnim.PushBack({ 72,116,15,22 });

	//lady moving
	ladyAnim1.PushBack({ 72,116,15,22 });
	ladyAnim2.PushBack({ 97,116,15,22 });
	ladyidleAnim.speed = 0.1f;
}

ModuleLady::~ModuleLady() {

}


bool ModuleLady::Start()
{
	LOG("Loading player textures");
	ladytexture = App->textures->Load("Assets/Lady/PaulineSprites.png");
	currentAnimation = &ladyidleAnim;

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

	if (i % 501 == 0)
	{
		currentAnimation = &ladyAnim1;

	}

	/*if (i % 50 == 0){
		currentAnimation = &donkeyidleAnim;
	}*/



	if (currentAnimation == &ladyAnim1) {
		if (i % 20 == 0) {
			currentAnimation = &ladyAnim2;
		}
	}



	currentAnimation->Update();
	//if (currentAnimation->HasFinished() == true) {
	//	currentAnimation->Reset();
	//}

	i++;

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
