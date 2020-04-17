#include "InitialScreen.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModuleAudio.h"
#include "ModuleInput.h"
#include "ModuleFadeToBlack.h"

InitialScreen::InitialScreen(bool startEnabled) : Module(startEnabled)
{

}

InitialScreen::~InitialScreen()
{

}

// Load assets
bool InitialScreen::Start()
{
	LOG("Loading background assets");

	bool ret = true;

	initialbackground.h = 256;
	initialbackground.w = 256;

	initialbackgroundtexture = App->textures->Load("Assets/cositasfondo/fondonegro.png");
	//App->audio->PlayMusic("Assets/Music/introTitle.ogg", 1.0f);
	App->audio->PlayMusic("Assets/Music/00 - Donkey Kong Main Theme (1).wav", 1.0f);


	return ret;
}

Update_Status InitialScreen::Update()
{
	if (App->input->keys[SDL_SCANCODE_SPACE] == Key_State::KEY_DOWN)
	{
		App->fade->FadeToBlack(this, (Module*)App->intro, 90);
	}

	return Update_Status::UPDATE_CONTINUE;
}

// Update: draw background
Update_Status InitialScreen::PostUpdate()
{
	// Draw everything --------------------------------------

	App->render->Blit(initialbackgroundtexture, 0, 0, &initialbackground, 0);

	return Update_Status::UPDATE_CONTINUE;
}

bool InitialScreen::CleanUp() {

	App->textures->Unload(initialbackgroundtexture);

	return true;
}