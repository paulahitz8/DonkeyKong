#include "GameOver.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModuleAudio.h"
#include "ModuleInput.h"
#include "ModuleFadeToBlack.h"
#include "ModulePlayer.h"
#include "SDL.h"

int map[32][32]{ {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
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

GameOver::GameOver(bool startEnabled) : Module(startEnabled)
{
}


GameOver::~GameOver()
{
}


bool GameOver::Start()
{
	LOG("Loading background assets");

	//TILEMAP

	tile.w = 8;
	tile.h = 8;


	//backgroundTexture = App->textures->Load("Assets/cositasfondo/background.png");
	floorTexture = App->textures->Load("Assets/cositasfondo/suelo.png");
	floorCarrotTexture = App->textures->Load("Assets/cositasfondo/sueloencimazanahoria.png");
	carrotTexture = App->textures->Load("Assets/cositasfondo/zanahoria.png");
	ladderTexture = App->textures->Load("Assets/cositasfondo/escalera.png");
	floorLadderTexture = App->textures->Load("Assets/cositasfondo/sueloescalera.png");
	leftPoleTexture = App->textures->Load("Assets/cositasfondo/barraizquierda.png");
	rightPoleTexture = App->textures->Load("Assets/cositasfondo/barraderecha.png");
	

	return true;
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
	int b = 0;

	for (int column = 0; column < 32; column++) {
		for (int row = 0; row < 32; row++) {

			b = map[column][row];

			switch (b) {

		/*	case 0:
				App->render->Blit(backgroundTexture, row * 8, column * 8, &tile, 0);
				break;*/

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


bool GameOver::CleanUp() {

	return true;
}