#include "IntroScreen.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModuleAudio.h"
#include "ModuleScore.h"
#include "ModuleInput.h"
#include "ModuleScore.h"
#include "ModuleFadeToBlack.h"

IntroScreen::IntroScreen(bool startEnabled) : Module(startEnabled)
{

}

IntroScreen::~IntroScreen()
{

}

// Load assets
bool IntroScreen::Start()
{
	LOG("Loading background assets");

	bool ret = true;

	background.h = 256;
	background.w = 256;

	introBackground = App->textures->Load("Assets/cositasfondo/introobackground.png");
	App->audio->PlayMusic("Assets/Music/00 - Donkey Kong Main Theme (1).wav", 1.0f);

	App->score->Enable();

	

	return ret;
}

Update_Status IntroScreen::Update()
{
	

	if (App->input->keys[SDL_SCANCODE_SPACE] == Key_State::KEY_DOWN)
	{
		App->fade->FadeToBlack(this, (Module*)App->lvl2, 30);
	}

	intro = true;

	return Update_Status::UPDATE_CONTINUE;
}


Update_Status IntroScreen::PostUpdate()
{

	App->render->Blit(introBackground, 0, 0, &background, 0);

	return Update_Status::UPDATE_CONTINUE;
}

bool IntroScreen::CleanUp() {

	App->textures->Unload(introBackground);
	App->score->Disable();
	

	return true;
}