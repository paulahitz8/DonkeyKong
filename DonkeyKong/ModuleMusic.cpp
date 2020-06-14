#include "ModuleMusic.h"
#include "PierdeVida.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModuleAudio.h"
#include "ModuleInput.h"
#include "ModuleLvl4.h"
#include "ModuleLvl3.h"
#include "ModuleObject.h"
#include "ModuleFadeToBlack.h"
#include "ModulePlayer.h"
#include "ModuleScore.h"



ModuleMusic::ModuleMusic(bool startEnabled) : Module(startEnabled)
{
}

ModuleMusic::~ModuleMusic()
{
}


bool ModuleMusic::Start()
{


	bool ret = true;

	//lvl2
	if (App->player->activelevel == 2) {
		App->audio->PlayMusic("Assets/Music/stage2.ogg", 1.0f);
	}
	
	if (App->player->activelevel == 3) {

		App->audio->PlayMusic("Assets/Music/silence.wav", 1.0f);
	}
 	//lvl4
	if (App->player->activelevel == 4) {
		App->audio->PlayMusic("Assets/Music/10 Stage 4 BGM.ogg", 1.0f);
	}
	

	return ret;
}


Update_Status ModuleMusic::Update()
{
	

	return Update_Status::UPDATE_CONTINUE;
}


Update_Status ModuleMusic::PostUpdate()
{
	


	return Update_Status::UPDATE_CONTINUE;
}


bool ModuleMusic::CleanUp() {



	return true;
}