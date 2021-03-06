#include "ModuleDonkey.h"

#include "Application.h"

#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModulePlayer.h"
#include "ModuleAudio.h"
#include "ModuleCollisions.h"
#include "SDL_scancode.h"


ModuleDonkey::ModuleDonkey(bool startEnabled) : Module(startEnabled)
{
	//donkey idle
	donkeyidleAnim.PushBack({ 34,66,40,32 });

	//donkey moving
	donkeyAnim1.PushBack({ 82,66,46,32 });
	donkeyAnim2.PushBack({ 136,66,46,32 });
	donkeyAnim3.PushBack({ 82,66,46,32 });
}

ModuleDonkey::~ModuleDonkey() {

}


bool ModuleDonkey::Start()
{
	i = 1;
	LOG("Loading player textures");
	donkeytexture = App->textures->Load("Assets/Donkey/DonkeyKongSprites2.png");
	currentAnimation = &donkeyidleAnim; 
	
	/*if (playertexture == nullptr) {
		return false;
	}*/

	stompFx = App->audio->LoadFx("Assets/Music/17 SFX (Stomp).wav");
	
	donkey = { 34, 66, 40, 32 };
	
	


	return true;
}

Update_Status ModuleDonkey::Update()
{	
	
	if (i % 501 == 0)
	{
		currentAnimation = &donkeyAnim1;
		App->audio->PlayFx(stompFx);
	}


	if (currentAnimation == &donkeyAnim1) {
		if (i % 20 == 0) {
			currentAnimation = &donkeyAnim2;
			App->audio->PlayFx(stompFx);

		}
	}

	else if (currentAnimation == &donkeyAnim2) {
		if (i % 20 == 0) {
			currentAnimation = &donkeyAnim3;
			App->audio->PlayFx(stompFx);

		}
	}

	else if (currentAnimation == &donkeyAnim3) {
		if (i % 20 == 0) {
			currentAnimation = &donkeyidleAnim;
		}
	}

	currentAnimation->Update();

	i++;

	return Update_Status::UPDATE_CONTINUE;
}

Update_Status ModuleDonkey::PostUpdate()
{
	SDL_Rect rect = currentAnimation->GetCurrentFrame();
	if (App->player->activelevel == 2) {
		App->render->Blit(donkeytexture, 99, 56, &rect);
	}
	
	if (App->player->activelevel == 3) {
		App->render->Blit(donkeytexture, 40, 56, &rect);
	}

	if (App->player->activelevel == 4) {
		App->render->Blit(donkeytexture, 108, 56, &rect);
	}
	
	

	return Update_Status::UPDATE_CONTINUE;
}


bool ModuleDonkey::CleanUp()
{

	return true;
}


