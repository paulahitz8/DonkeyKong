#include "GameOver.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModuleAudio.h"
#include "ModuleInput.h"
#include "ModuleFadeToBlack.h"
#include "ModulePlayer.h"

GameOver::GameOver(bool startEnabled) : Module(startEnabled)
{
}


GameOver::~GameOver()
{
}


bool GameOver::Start()
{
	LOG("Loading background assets");

	bool ret = true;
	background.h = 256;
	background.w = 256;
	backgroundTexture = App->textures->Load("Assets/cositasfondo/fondonegro.png");
	
	return ret;
}


Update_Status GameOver::Update()
{
	if (App->input->keys[SDL_SCANCODE_SPACE] == Key_State::KEY_DOWN)
	{
		App->player->livecount = 3;
		App->fade->FadeToBlack(this, (Module*)App->lvl4, 30);
	}

	// en teoria se acaba el juego aunque podriamos poner un try again o algo
	// si pulsa una tecla
	return Update_Status::UPDATE_CONTINUE;
}


Update_Status GameOver::PostUpdate()
{
	App->render->Blit(backgroundTexture, 0, 0, &background, 0);

	return Update_Status::UPDATE_CONTINUE;
}


bool GameOver::CleanUp() {

	App->textures->Unload(backgroundTexture);

	return true;
}