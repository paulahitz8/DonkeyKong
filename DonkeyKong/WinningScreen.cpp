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
	angryAnim.PushBack({ 70,46,46,32 });
	angryAnim.PushBack({ 124,46,46,32 });
	angryAnim.loop = true;
	angryAnim.speed = 0.1f;

	//down anim
	downAnim.PushBack({ 178,46,40,32 });

	//dizzy anim
	dizzyAnim.PushBack({ 51,87,40,40 });
	dizzyAnim.PushBack({ 99,87,40,40 });
	dizzyAnim.PushBack({ 147,87,40,40 });
	dizzyAnim.PushBack({ 52,133,40,40 });
	dizzyAnim.PushBack({ 100,133,40,40 });
	dizzyAnim.PushBack({ 148,133,40,40 });
	dizzyAnim.loop = true;
	dizzyAnim.speed = 0.1f;

}

WinningScreen::~WinningScreen()
{
}


bool WinningScreen::Start()
{
	LOG("Loading background assets");

	currentAnimation = &donkeyidleAnim;
	bool ret = true;

	back.x = 0;
	back.y = 0;
	back.w = 256;
	back.h = 256;

	donkeypos.x = 108;
	donkeypos.y = 56;

	pauline = {8, 189, 16, 22};
	mario = {34, 195, 12, 16};
	heart = {57, 189, 15, 13};
	donkey = {22, 46, 40, 32};
	
	
	spritesTexture = App->textures->Load("Assets/Ending/sprites.png");
	backgroundTexture = App->textures->Load("Assets/Ending/one.png");
	happybackgroundTexture = App->textures->Load("Assets/Ending/happyending.png");
	
	App->audio->PlayMusic("Assets/Music/try.ogg", 1.0f);

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
	if (i > 50 && i < 200) {
		a = 2;
		currentAnimation = &angryAnim;
	}

	if (i > 200 && i < 300) {
		a = 3;
		currentAnimation = &downAnim;
		donkeypos.y += 1.3;
	}

	if (i > 300) {
		a = 4;
		currentAnimation = &dizzyAnim;
		donkeypos.y = 184;

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
		App->render->Blit(spritesTexture, donkeypos.x, donkeypos.y, &donkey);
		App->render->Blit(spritesTexture, App->player->position.x + 17, App->player->position.y + 10, &mario);
	}
	else if (a == 2) {
		App->render->Blit(backgroundTexture, 0, 0, &back);
		App->render->Blit(spritesTexture, 120, 26, &pauline);
		App->render->Blit(spritesTexture, donkeypos.x, donkeypos.y, &rect);
		App->render->Blit(spritesTexture, App->player->position.x + 17, App->player->position.y + 10, &mario);
	}

	else if (a == 3) {
		App->render->Blit(backgroundTexture, 0, 0, &back);
		App->render->Blit(spritesTexture, 120, 26, &pauline);
		App->render->Blit(spritesTexture, donkeypos.x, donkeypos.y, &rect);
		App->render->Blit(spritesTexture, App->player->position.x + 17, App->player->position.y + 10, &mario);

	}
	
	else if (a == 4) {
		App->render->Blit(happybackgroundTexture, 0, 0, &back);
		App->render->Blit(spritesTexture, 120, 66, &pauline);
		App->render->Blit(spritesTexture, donkeypos.x, donkeypos.y, &rect);
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