#include "PierdeVida.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModuleAudio.h"
#include "ModuleInput.h"
#include "ModuleFadeToBlack.h"

PierdeVida::PierdeVida(bool startEnabled) : Module(startEnabled)
{
}

PierdeVida::~PierdeVida()
{
}

// Load assets
bool PierdeVida::Start()
{
	LOG("Loading background assets");

	bool ret = true;

	background.h = 256;
	background.w = 256;

	backgroundTexture = App->textures->Load("Assets/cositasfondo/R5.png");
	App->audio->PlayMusic("Assets/Music/05 How high can you get.ogg", 1.0f);
	
	

	return ret;
}

Update_Status PierdeVida::Update()
{

	if (i % 161 == 0)
	{
		App->fade->FadeToBlack(this, (Module*)App->lvl4, 10);
	}
	i++;
	return Update_Status::UPDATE_CONTINUE;
}

// Update: draw background
Update_Status PierdeVida::PostUpdate()
{

	App->render->Blit(backgroundTexture, 0, 0, &background, 0);

	return Update_Status::UPDATE_CONTINUE;
}

bool PierdeVida::CleanUp() {

	App->textures->Unload(backgroundTexture);

	return true;
}