#include "ModuleLvl4.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModuleInput.h"
#include "ModuleAudio.h"
#include "ModulePlayer.h"
#include "ModuleDonkey.h"


int lvl4[32][32]{	 {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
					{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
					{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
					{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
					{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}, 
					{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
					{0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0},
					{0,0,0,0,0,0,0,0,0,0,7,6,0,0,0,0,0,0,0,0,7,6,0,0,0,0,0,0,0,0,0,0},
					{0,0,0,0,0,0,0,0,0,0,7,6,0,0,0,0,0,0,0,0,7,6,0,0,0,0,0,0,0,0,0,0},
					{0,0,0,0,0,0,0,0,0,0,7,6,0,0,0,0,0,0,0,0,7,6,0,0,0,0,0,0,0,0,0,0},
					{0,0,0,0,0,0,0,0,0,2,7,6,0,0,0,0,0,0,0,0,7,6,2,0,0,0,0,0,0,0,0,0},
					{0,0,0,0,0,0,5,1,1,3,5,1,1,1,1,1,1,1,1,1,1,5,3,1,1,5,0,0,0,0,0,0},
					{0,0,0,0,0,0,4,0,0,0,4,0,0,0,0,0,0,0,0,0,0,4,0,0,0,4,0,0,0,0,0,0},
					{0,0,0,0,0,0,4,0,0,0,4,0,0,0,0,0,0,0,0,0,0,4,0,0,0,4,0,0,0,0,0,0},
					{0,0,0,0,0,0,4,0,0,0,4,0,0,0,0,0,0,0,0,0,0,4,0,0,0,4,0,0,0,0,0,0},
					{0,0,0,0,0,0,4,0,0,2,4,0,0,0,0,0,0,0,0,0,0,4,2,0,0,4,0,0,0,0,0,0},
					{0,0,0,0,0,5,5,1,1,3,5,1,1,1,1,5,1,1,1,1,1,5,3,1,1,5,5,0,0,0,0,0},
					{0,0,0,0,0,4,0,0,0,0,0,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,4,0,0,0,0,0},
					{0,0,0,0,0,4,0,0,0,0,0,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,4,0,0,0,0,0},
					{0,0,0,0,0,4,0,0,0,0,0,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,4,0,0,0,0,0},
					{0,0,0,0,0,4,0,0,0,2,0,0,0,0,0,4,0,0,0,0,0,0,2,0,0,0,4,0,0,0,0,0},
					{0,0,0,0,5,5,1,1,1,3,1,5,1,1,1,5,1,1,1,1,5,1,3,1,1,1,5,5,0,0,0,0},
					{0,0,0,0,4,0,0,0,0,0,0,4,0,0,0,0,0,0,0,0,4,0,0,0,0,0,0,4,0,0,0,0},
					{0,0,0,0,4,0,0,0,0,0,0,4,0,0,0,0,0,0,0,0,4,0,0,0,0,0,0,4,0,0,0,0},
					{0,0,0,0,4,0,0,0,0,0,0,4,0,0,0,0,0,0,0,0,4,0,0,0,0,0,0,4,0,0,0,0},
					{0,0,0,0,4,0,0,0,0,2,0,4,0,0,0,0,0,0,0,0,4,0,2,0,0,0,0,4,0,0,0,0},
					{0,0,0,5,5,1,1,1,1,3,1,5,1,1,1,1,1,1,1,1,5,1,3,1,1,1,1,5,5,0,0,0},
					{0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,4,0,0,0},
					{0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,4,0,0,0},
					{0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,4,0,0,0},
					{0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,4,0,0,0},
					{0,0,1,5,1,1,1,1,1,1,1,1,1,1,1,5,1,1,1,1,1,1,1,1,1,1,1,1,5,1,0,0},
};

ModuleLvl4::ModuleLvl4(bool startEnabled) : Module(startEnabled)
{

}

ModuleLvl4::~ModuleLvl4()
{

}


bool ModuleLvl4::Start()
{
	App->audio->PlayMusic("Assets/Music/10 Stage 4 BGM.ogg", 1.0f);

	//if (texture == nullptr) {
	//	return false;
	//}


	//TILEMAP

	tile.w = 8;
	tile.h = 8;

	backgroundTexture = App->textures->Load("Assets/cositasfondo/background.png");
	floorTexture = App->textures->Load("Assets/cositasfondo/suelo.png");
	floorCarrotTexture = App->textures->Load("Assets/cositasfondo/sueloencimazanahoria.png");
	carrotTexture = App->textures->Load("Assets/cositasfondo/zanahoria.png");
	ladderTexture = App->textures->Load("Assets/cositasfondo/escalera.png");
	floorLadderTexture = App->textures->Load("Assets/cositasfondo/sueloescalera.png");
	leftPoleTexture = App->textures->Load("Assets/cositasfondo/barraizquierda.png");
	rightPoleTexture = App->textures->Load("Assets/cositasfondo/barraderecha.png");

	// Enable Player?

	App->player->Enable();
	App->donkey->Enable();


	return true;
}

Update_Status ModuleLvl4::Update()
{
	return Update_Status::UPDATE_CONTINUE;
}

Update_Status ModuleLvl4::PostUpdate()
{

	int type = 0;

	for (int column = 0; column < 32; column++) {
		for (int row = 0; row < 32; row++) {

			type = lvl4[column][row];

			switch (type) {

			case 0:
				App->render->Blit(backgroundTexture, row * 8, column * 8, &tile, 0);
				break;

			case 1:
				App->render->Blit(floorTexture, row * 8, column * 8, &tile, 0);
				break;

			case 2:
				App->render->Blit(floorCarrotTexture, row * 8, column * 8, &tile, 0);
				break;

			case 3:
				App->render->Blit(carrotTexture, row * 8, column * 8, &tile, 0);
				break;

			case 4:
				App->render->Blit(ladderTexture, row * 8, column * 8, &tile, 0);
				break;

			case 5:
				App->render->Blit(floorLadderTexture, row * 8, column * 8, &tile, 0);
				break;

			case 6:
				App->render->Blit(leftPoleTexture, row * 8, column * 8, &tile, 0);
				break;

			case 7:
				App->render->Blit(rightPoleTexture, row * 8, column * 8, &tile, 0);
				break;

			}
		}
	}

	return Update_Status::UPDATE_CONTINUE;
}

bool ModuleLvl4::CleanUp()
{
	//Disable player?
	App->player->Disable();
	App->donkey->Disable();
	return true;
}
