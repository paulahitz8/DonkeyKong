#include "WinningScreen.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModuleAudio.h"
#include "ModuleInput.h"
#include "ModuleFadeToBlack.h"
#include "ModuleCollisions.h"
#include "ModulePlayer.h"


WinningScreen::WinningScreen(bool startEnabled) : Module(startEnabled)
{
	//donkey idle
	donkeyidleAnim.PushBack({ 22,46,40,32 });

	//angry anim
	angryAnim1.PushBack({ 70,46,46,32 });
	angryAnim2.PushBack({ 124,46,46,32 });
	

	//down anim
	downAnim.PushBack({ 178,46,40,32 });


	//dizzy anim
	dizzyAnim.PushBack({ 97,116,15,22 });
	dizzyAnim.loop = true;
	dizzyAnim.speed = 0.1f;

	

	
}

WinningScreen::~WinningScreen()
{
}

// Load assets
bool WinningScreen::Start()
{
	LOG("Loading background assets");

	currentAnimation = &donkeyidleAnim;
	bool ret = true;

	back.x = 0;
	back.y = 0;
	back.w = 256;
	back.h = 256;

	pauline = {8, 189, 16, 22};
	mario = {34, 195, 12, 16};
	heart = {57, 189, 15, 13};
	donkey = {22, 46, 40, 32};
	
	App->audio->PlayMusic("Assets/Music/endingsounds.wav", 1.0f);
	spritesTexture = App->textures->Load("Assets/Ending/sprites.png");
	backgroundTexture = App->textures->Load("Assets/Ending/one.png");
	happybackgroundTexture = App->textures->Load("Assets/Ending/happyending.png");
	

	return ret;
}

Update_Status WinningScreen::Update()
{
	if (App->input->keys[SDL_SCANCODE_SPACE] == Key_State::KEY_DOWN)
	{
		App->fade->FadeToBlack(this, (Module*)App->intro, 30);
	}


	if (i < 50) {
		a = 1;
		
	}

	if (i < 300 && i % 201 == 0) {
		a = 2;
		currentAnimation = &angryAnim1;

	}
	if (currentAnimation == &angryAnim1) {
		if (i % 10 == 0) {
			currentAnimation = &angryAnim2;
		}
	}
	else if (currentAnimation == &angryAnim2) {
		if (i % 10 == 0) {
			currentAnimation = &angryAnim1;
		}
	}
	else if (currentAnimation == &angryAnim1) {
		if (i % 10 == 0) {
			currentAnimation = &angryAnim2;
		}
	}
	else if (currentAnimation == &angryAnim2) {
		if (i % 10 == 0) {
			currentAnimation = &donkeyidleAnim;
		}
	}
	if (i > 400 && i < 600) {
		a = 3;
		currentAnimation = &downAnim;
	}
	currentAnimation->Update();
	
	i++;


	return Update_Status::UPDATE_CONTINUE;
}



Update_Status WinningScreen::PostUpdate()
{
	SDL_Rect rect = currentAnimation->GetCurrentFrame();
	
	if (a == 1) {
		
		App->render->Blit(backgroundTexture, 0, 0, &back);
		App->render->Blit(spritesTexture, 120, 26, &pauline);
		App->render->Blit(spritesTexture, 108, 56, &donkey);
		App->render->Blit(spritesTexture, App->player->position.x + 17, App->player->position.y + 10, &mario);
	}
	else if (a == 2) {
		App->render->Blit(backgroundTexture, 0, 0, &back);
		App->render->Blit(spritesTexture, 120, 26, &pauline);
		App->render->Blit(spritesTexture, 108, 56, &rect);
		App->render->Blit(spritesTexture, App->player->position.x + 17, App->player->position.y + 10, &mario);
	}

	else if (a == 3) {
		App->render->Blit(backgroundTexture, 0, 0, &back);
		App->render->Blit(spritesTexture, 120, 26, &pauline);
		App->render->Blit(spritesTexture, 108, 56, &rect);
		App->render->Blit(spritesTexture, App->player->position.x + 17, App->player->position.y + 10, &mario);

	}
	
	//else if (a == 4) {
	//	App->render->Blit(happybackgroundTexture, 0, 0, &back, 0);
	//}

	return Update_Status::UPDATE_CONTINUE;
}

bool WinningScreen::CleanUp() {

	App->textures->Unload(backgroundTexture);

	return true;
}

// orden
//1. imagen cambiada con musica
//2. donkey enfadado con sonido
//3. donkey se cae con sonido
//4. donkey se golpea con sonido + pauline baja 
//5. mario sube
//6. corazon y musiquita