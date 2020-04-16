#include "ModuleLvl4.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModuleInput.h"
#include "ModuleAudio.h"

ModuleLvl4::ModuleLvl4(bool startEnabled) : Module(startEnabled)
{

}

ModuleLvl4::~ModuleLvl4()
{

}


bool ModuleLvl4::Start()
{
	texture = App->textures->Load("Assets/cositasfondo/background.png");
	App->audio->PlayMusic("Assets/Music/10 Stage 4 BGM.ogg", 1.0f);

		// comprueba esto 

	//if (texture == nullptr) {
	//	return false;
	//}
	
	background.x = 0;
	background.y = 0;
	background.w = 256;
	background.h = 256;

	return true;
}

Update_Status ModuleLvl4::Update()
{
	return Update_Status::UPDATE_CONTINUE;
}

Update_Status ModuleLvl4::PostUpdate()
{
	App->render->Blit(texture, position.x, position.y, &background, 0);
	return Update_Status::UPDATE_CONTINUE;
}

bool ModuleLvl4::CleanUp()
{
	return true;
}
