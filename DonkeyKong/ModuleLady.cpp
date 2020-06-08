#include "ModuleLady.h"

#include "Application.h"
#include "ModuleTextures.h"
#include "ModulePlayer.h"
#include "ModuleRender.h"
#include "ModuleAudio.h"



ModuleLady::ModuleLady(bool startEnabled) : Module(startEnabled)
{
	//lady moving left
	leftladyAnim.PushBack({ 97,116,15,22 });
	leftladyAnim.PushBack({ 72,116,15,22 });
	leftladyAnim.speed = 0.1f;

	//lady moving right
	rightladyAnim.PushBack({ 98, 145, 15, 22 });
	rightladyAnim.PushBack({ 73, 145, 15, 22 });
	rightladyAnim.speed = 0.1f;

	//idle lady left
	leftidleladyAnim.PushBack({ 72,116,15,22 });

	//idlw lady right
	rightidleladyAnim.PushBack({ 98,145,15,22 });

	//left help
	lefthelpAnim.PushBack({ 65, 51, 24, 8 });

	//right help
	righthelpAnim.PushBack({ 33, 51, 23 , 8 });

	//idle help
	helpidleAnim.PushBack({ 0, 0, 23, 8 });
}

ModuleLady::~ModuleLady() {

}


bool ModuleLady::Start()
{
	i = 1;
	LOG("Loading player textures");
	ladytexture = App->textures->Load("Assets/Lady/PaulineSprites.png");
	helptexture = App->textures->Load("Assets/Lady/RandomSprites.png");
	currentAnimation = &leftidleladyAnim;
	currentAnimationhelp = &helpidleAnim;

	/*if (playertexture == nullptr) {
		return false;
	}*/

	lady = { 72, 116, 15, 22 };

	return true;
}

Update_Status ModuleLady::Update()
{

	if (i % 351 == 0)
	{
		if (currentAnimation == &leftidleladyAnim)
		{
			currentAnimation = &rightidleladyAnim;
		}
		else if (currentAnimation == &rightidleladyAnim)
		{
			currentAnimation = &leftidleladyAnim;
		}
		if (currentAnimation == &leftladyAnim)
		{
			currentAnimation = &rightladyAnim;
			currentAnimationhelp = &righthelpAnim;
			if (App->player->activelevel == 4) {
				helpPosition.x = 90;
			}
			if (App->player->activelevel == 2 || App->player->activelevel == 3) {
				helpPosition.x = 74;
			}
			

		}
		else if (currentAnimation == &rightladyAnim)
		{
			currentAnimation = &leftladyAnim;
			currentAnimationhelp = &lefthelpAnim;
			
			if (App->player->activelevel == 4) {
				helpPosition.x = 140;
			}
			if (App->player->activelevel == 2 || App->player->activelevel == 3) {
				helpPosition.x = 124;
			}
		}
	}

	if (i % 501 == 0)
	{
		if (currentAnimation == &leftidleladyAnim)
		{
			currentAnimation = &leftladyAnim;
			currentAnimationhelp = &lefthelpAnim;
			if (App->player->activelevel == 4) {
				helpPosition.x = 140;
			}
			if (App->player->activelevel == 2 || App->player->activelevel == 3) {
				helpPosition.x = 124;
			}
		}
		if (currentAnimation == &rightidleladyAnim)
		{
			currentAnimation = &rightladyAnim;
			currentAnimationhelp = &righthelpAnim;
			if (App->player->activelevel == 4) {
				helpPosition.x = 90;
			}
			if (App->player->activelevel == 2 || App->player->activelevel == 3) {
				helpPosition.x = 74;
			}
		}
		j = 0;
	}
	if (currentAnimation == &leftladyAnim || currentAnimation == &rightladyAnim)
	{
		j++;
	}
	if (j % 71 == 0)
	{
		currentAnimationhelp = &helpidleAnim;
		if (currentAnimation == &leftladyAnim)
		{
			currentAnimation = &leftidleladyAnim;
		}
		if (currentAnimation == &rightladyAnim)
		{
			currentAnimation = &rightidleladyAnim;
		}
	}

	currentAnimation->Update();

	i++;

	return Update_Status::UPDATE_CONTINUE;
}

Update_Status ModuleLady::PostUpdate()
{
	if (App->player->activelevel == 2) {
		SDL_Rect rect = currentAnimation->GetCurrentFrame();
		App->render->Blit(ladytexture, 104, 34, &rect);
		SDL_Rect recthelp = currentAnimationhelp->GetCurrentFrame();
		App->render->Blit(helptexture, helpPosition.x, helpPosition.y, &recthelp);
	}

	if (App->player->activelevel == 3) {
		SDL_Rect rect = currentAnimation->GetCurrentFrame();
		App->render->Blit(ladytexture, 104, 34, &rect);
		SDL_Rect recthelp = currentAnimationhelp->GetCurrentFrame();
		App->render->Blit(helptexture, helpPosition.x, helpPosition.y, &recthelp);
	}

	if (App->player->activelevel == 4) {
		SDL_Rect rect = currentAnimation->GetCurrentFrame();
		App->render->Blit(ladytexture, 120, 26, &rect);
		SDL_Rect recthelp = currentAnimationhelp->GetCurrentFrame();
		App->render->Blit(helptexture, helpPosition.x, helpPosition.y, &recthelp);
	}






	return Update_Status::UPDATE_CONTINUE;
}


bool ModuleLady::CleanUp()
{
	return true;
}
