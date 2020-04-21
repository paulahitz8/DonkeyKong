#include "GameOver.h"

#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModuleAudio.h"
#include "ModuleInput.h"
#include "ModuleFadeToBlack.h"
#include "ModuleScore.h"
#include "ModulePlayer.h"
#include "SDL.h"


GameOver::GameOver(bool startEnabled) : Module(startEnabled)
{
}

GameOver::~GameOver()
{
}

bool GameOver::Start()
{
	LOG("Loading background assets");
	if (App->score->a > b) {
		b = App->score->a;
	}
	bool ret = true;

	backgroundgameover.h = 256;
	backgroundgameover.w = 256;

	backgroundgameoverTexture = App->textures->Load("Assets/cositasfondo/gameover.png");
	
	App->audio->PlayMusic("Assets/Music/silence.wav", 1.0f);
	
	App->score->Enable();
	return ret;
}

Update_Status GameOver::Update()
{
	if (App->input->keys[SDL_SCANCODE_SPACE] == Key_State::KEY_DOWN)
	{
		App->fade->FadeToBlack(this, (Module*)App->lvl4, 30);
	}

	return Update_Status::UPDATE_CONTINUE;
}


Update_Status GameOver::PostUpdate()
{
	App->render->Blit(backgroundgameoverTexture, 0, 0, &backgroundgameover, 0);

	return Update_Status::UPDATE_CONTINUE;
}

bool GameOver::CleanUp() {

	App->textures->Unload(backgroundgameoverTexture);
	App->score->Disable();
	return true;
}