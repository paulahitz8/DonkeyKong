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
	ladyAnim1.PushBack({ 97,116,15,22 });
	ladyAnim2.PushBack({ 72,116,15,22 });
	ladyAnim3.PushBack({ 97,116,15,22 });
	ladyAnim4.PushBack({ 72,116,15,22 });
	ladyAnim5.PushBack({ 97,116,15,22 });

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
	else if (currentAnimation == &ladyAnim1) {
		if (i % 20 == 0) {
			currentAnimation = &ladyAnim2;
		}
	}
	else if (currentAnimation == &ladyAnim2) {
		if (i % 20 == 0) {
			currentAnimation = &ladyAnim3;
		}
	}
	else if (currentAnimation == &ladyAnim3) {
		if (i % 20 == 0) {
			currentAnimation = &ladyAnim4;
		}
	}
	else if (currentAnimation == &ladyAnim4) {
		if (i % 20 == 0) {
			currentAnimation = &ladyAnim5;
		}
	}
	//else if (currentAnimation == &ladyAnim1) {
	//	if (i % 20 == 0) {
	//		currentAnimation = &ladyAnim2;
	//	}
	//}
	//else if (currentAnimation == &ladyAnim2) {
	//	if (i % 20 == 0) {
	//		currentAnimation = &ladyAnim1;
	//	}
	//}
	//else if (currentAnimation == &ladyAnim1) {
	//	if (i % 20 == 0) {
	//		currentAnimation = &ladyAnim2;
	//	}
	//}
	else if (currentAnimation == &ladyAnim5) {
		if (i % 20 == 0) {
			currentAnimation = &ladyidleAnim;
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
	SDL_Rect rect = currentAnimation->GetCurrentFrame();
	App->render->Blit(ladytexture, ladyPosition.x, ladyPosition.y, &rect);

	return Update_Status::UPDATE_CONTINUE;
}


bool ModuleLady::CleanUp()
{
	return true;
}
