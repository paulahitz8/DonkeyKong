#include "ModuleLvl4.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModuleInput.h"
#include "ModuleAudio.h"
#include "ModulePlayer.h"
#include "ModuleHammer.h"
#include "ModuleScore.h"
#include "ModuleDonkey.h"
#include "ModuleEnemies.h"
#include "ModuleCollisions.h"
#include "WinningScreen.h"
#include "ModuleLady.h"
#include "SDL.h"


int lvl4Initial[32][32]{{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
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
					{0,0,0,0,0,0,5,1,1,3,5,1,1,1,1,1,1,1,1,1,1,5,3,1,1,5,0,0,0,0,0,0}, //
					{0,0,0,0,0,0,4,0,0,0,4,0,0,0,0,0,0,0,0,0,0,4,0,0,0,4,0,0,0,0,0,0},
					{0,0,0,0,0,0,4,0,0,0,4,0,0,0,0,0,0,0,0,0,0,4,0,0,0,4,0,0,0,0,0,0},
					{0,0,0,0,0,0,4,0,0,0,4,0,0,0,0,0,0,0,0,0,0,4,0,0,0,4,0,0,0,0,0,0},
					{0,0,0,0,0,0,4,0,0,2,4,0,0,0,0,0,0,0,0,0,0,4,2,0,0,4,0,0,0,0,0,0},
					{0,0,0,0,0,5,5,1,1,3,5,1,1,1,1,5,1,1,1,1,1,5,3,1,1,5,5,0,0,0,0,0}, //15
					{0,0,0,0,0,4,0,0,0,0,0,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,4,0,0,0,0,0},
					{0,0,0,0,0,4,0,0,0,0,0,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,4,0,0,0,0,0},
					{0,0,0,0,0,4,0,0,0,0,0,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,4,0,0,0,0,0},
					{0,0,0,0,0,4,0,0,0,2,0,0,0,0,0,4,0,0,0,0,0,0,2,0,0,0,4,0,0,0,0,0},
					{0,0,0,0,5,5,1,1,1,3,1,5,1,1,1,5,1,1,1,1,5,1,3,1,1,1,5,5,0,0,0,0}, // 20
					{0,0,0,0,4,0,0,0,0,0,0,4,0,0,0,0,0,0,0,0,4,0,0,0,0,0,0,4,0,0,0,0},
					{0,0,0,0,4,0,0,0,0,0,0,4,0,0,0,0,0,0,0,0,4,0,0,0,0,0,0,4,0,0,0,0},
					{0,0,0,0,4,0,0,0,0,0,0,4,0,0,0,0,0,0,0,0,4,0,0,0,0,0,0,4,0,0,0,0},
					{0,0,0,0,4,0,0,0,0,2,0,4,0,0,0,0,0,0,0,0,4,0,2,0,0,0,0,4,0,0,0,0},
					{0,0,0,5,5,1,1,1,1,3,1,5,1,1,1,1,1,1,1,1,5,1,3,1,1,1,1,5,5,0,0,0}, // 25
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
	i = 1;
	j = 0;

	App->winning->win = false;
	App->player->n = 0;
	// FUnciona mas o menos pero la zanahoria que coges justo antes de morir no spawnea otra vez

	for (int a = 0; a < 32; a++) {
		for (int b = 0; b < 32; b++) {
			lvl4[a][b] = lvl4Initial[a][b];
		}
	}

	App->audio->PlayMusic("Assets/Music/10 Stage 4 BGM.ogg", 1.0f);

	//TILEMAP

	tile.w = 8;
	tile.h = 8;
	back.w = 256;
	back.h = 256;
	cienrect = { 59,104,15,7 };


	backTexture = App->textures->Load("Assets/cositasfondo/backgroundconcosas.png");
	cientexture = App->textures->Load("Assets/Lady/RandomSprites.png");

	backgroundTexture = App->textures->Load("Assets/cositasfondo/background.png");
	floorTexture = App->textures->Load("Assets/cositasfondo/suelo.png");
	floorCarrotTexture = App->textures->Load("Assets/cositasfondo/sueloencimazanahoria.png");
	carrotTexture = App->textures->Load("Assets/cositasfondo/zanahoria.png");
	ladderTexture = App->textures->Load("Assets/cositasfondo/escalera.png");
	floorLadderTexture = App->textures->Load("Assets/cositasfondo/sueloescalera.png");
	leftPoleTexture = App->textures->Load("Assets/cositasfondo/barraizquierda.png");
	rightPoleTexture = App->textures->Load("Assets/cositasfondo/barraderecha.png");
	liveTexture = App->textures->Load("Assets/cositasfondo/MarioLive.png");

	// Level 4 colliders:
	// Walls and ground by floor
	App->collision->AddCollider({ 0, 245, 14, 11 }, Collider::Type::WALL);
	App->collision->AddCollider({ 16, 247, 224, 9 }, Collider::Type::GROUND); 
	App->collision->AddCollider({ 16 + 223 + 3, 246, 16, 11 }, Collider::Type::WALL);

	App->collision->AddCollider({ 0, 207, 21, 11 }, Collider::Type::WALL);
	App->collision->AddCollider({ 24, 207, 49, 9 }, Collider::Type::GROUND); 
	App->collision->AddCollider({ 79, 207, 98, 9 }, Collider::Type::GROUND);  
	App->collision->AddCollider({ 79 + 98 + 6, 207, 49, 9 }, Collider::Type::GROUND); 
	App->collision->AddCollider({ 79 + 97 + 6 + 49 + 3, 207, 24, 10 }, Collider::Type::WALL);

	App->collision->AddCollider({ 0, 167, 29, 10 }, Collider::Type::WALL);
	App->collision->AddCollider({ 32, 168, 41, 8 }, Collider::Type::GROUND); 
	App->collision->AddCollider({ 79, 168, 98, 8 }, Collider::Type::GROUND); 
	App->collision->AddCollider({ 79 + 98 + 6, 168, 41, 9 }, Collider::Type::GROUND); 
	App->collision->AddCollider({ 79 + 98 + 5 + 41 + 3, 168, 32, 10 }, Collider::Type::WALL);

	App->collision->AddCollider({ 0, 127, 37, 10 }, Collider::Type::WALL);
	App->collision->AddCollider({ 40, 128, 33, 8 }, Collider::Type::GROUND); 
	App->collision->AddCollider({ 79, 128, 98, 8 }, Collider::Type::GROUND); 
	App->collision->AddCollider({ 79 + 98 + 6, 128, 33, 9 }, Collider::Type::GROUND); 
	App->collision->AddCollider({ 79 + 97 + 6 + 33 + 3, 128, 40, 10 }, Collider::Type::WALL);

	App->collision->AddCollider({ 0, 87, 45, 10 }, Collider::Type::WALL);
	App->collision->AddCollider({ 48, 88, 25, 8 }, Collider::Type::GROUND); 
	App->collision->AddCollider({ 79, 88, 98, 8 }, Collider::Type::GROUND); 
	App->collision->AddCollider({ 79 + 98 + 6, 88, 25, 9 }, Collider::Type::GROUND); 
	App->collision->AddCollider({ 79 + 97 + 6 + 25 + 3, 88, 48, 10 }, Collider::Type::WALL);

	App->collision->AddCollider({ 0, 47, 69, 10 }, Collider::Type::WALL);
	App->collision->AddCollider({ 72, 48, 112, 9 }, Collider::Type::GROUND); 
	App->collision->AddCollider({ 72 + 111 + 3, 48, 72, 10 }, Collider::Type::WALL);

	//Donkey walls
	App->collision->AddCollider({ 90, 56, 2, 32 }, Collider::Type::WALL);
	App->collision->AddCollider({ 164, 56, 2, 32 }, Collider::Type::WALL);
																	  
	// Ladders by floor
	App->collision->AddCollider({ 27, 206 , 2, 44 }, Collider::Type::LADDER);
	App->collision->AddCollider({ 123, 206 , 2, 44 }, Collider::Type::LADDER);
	App->collision->AddCollider({ 227, 206 , 2, 44 }, Collider::Type::LADDER);

	App->collision->AddCollider({ 35, 166 , 2, 44 }, Collider::Type::LADDER);
	App->collision->AddCollider({ 91, 166 , 2, 44 }, Collider::Type::LADDER);
	App->collision->AddCollider({ 163, 166 , 2, 44 }, Collider::Type::LADDER);
	App->collision->AddCollider({ 219, 166 , 2, 44 }, Collider::Type::LADDER);

	App->collision->AddCollider({ 43, 126 , 2, 44 }, Collider::Type::LADDER);
	App->collision->AddCollider({ 123, 126 , 2, 44 }, Collider::Type::LADDER);
	App->collision->AddCollider({ 211, 126 , 2, 44 }, Collider::Type::LADDER);

	App->collision->AddCollider({ 51, 86 , 2, 44 }, Collider::Type::LADDER);
	App->collision->AddCollider({ 83, 86 , 2, 44 }, Collider::Type::LADDER);
	App->collision->AddCollider({ 171, 86 , 2, 44 }, Collider::Type::LADDER);
	App->collision->AddCollider({ 203, 86 , 2, 44 }, Collider::Type::LADDER);

	// Carrots
	App->collision->AddCollider({ 75, 193, 2, 15 }, Collider::Type::CARROT);
	App->collision->AddCollider({ 179, 193, 2, 15 }, Collider::Type::CARROT);

	App->collision->AddCollider({ 75,  153, 2, 15 }, Collider::Type::CARROT);
	App->collision->AddCollider({ 179, 153, 2, 15 }, Collider::Type::CARROT);

	App->collision->AddCollider({ 75, 113, 2, 15 }, Collider::Type::CARROT);
	App->collision->AddCollider({ 179, 113, 2, 15 }, Collider::Type::CARROT);

	App->collision->AddCollider({ 75, 73, 2, 15 }, Collider::Type::CARROT);
	App->collision->AddCollider({ 179, 73, 2, 15 }, Collider::Type::CARROT);

	// Enable Player
	App->score->Enable();
	App->player->Enable();
	App->donkey->Enable();
	App->hammer->Enable();
	App->enemies->Enable();
	App->lady->Enable();

	return true;
}

Update_Status ModuleLvl4::Update()
{
	// Lives
	for (int ilive = 0; ilive < 3; ilive++) {

		lvl4[3][2 + ilive] = 0;

	}

	for (int ilive = 0; ilive < App->player->livecount; ilive++) {
		
		lvl4[3][2 + ilive] = 8;

	}

	// Carrots
	if (App->player->carrotDeletey == 193) {
		cienpos.y = 216;
		if (App->player->carrotDeletex == 75) {
			lvl4[26][9] = 0;
			lvl4[25][9] = 0;
			cienpos.x = 69;
		}
		if (App->player->carrotDeletex == 179) {
			lvl4[26][22] = 0;
			lvl4[25][22] = 0;
			cienpos.x = 173;
		}
		App->player->colliderDelete->pendingToDelete = true;
	}
	if (App->player->carrotDeletey == 153) {
		cienpos.y = 176;
		if (App->player->carrotDeletex == 75) {
			lvl4[21][9] = 0;
			lvl4[20][9] = 0;
			cienpos.x = 69;
		}
		if (App->player->carrotDeletex == 179) {
			lvl4[21][22] = 0;
			lvl4[20][22] = 0;
			cienpos.x = 173;
		}
		App->player->colliderDelete->pendingToDelete = true;
	}
	if (App->player->carrotDeletey == 113) {
		cienpos.y = 136;
		if (App->player->carrotDeletex == 75) {
			lvl4[16][9] = 0;
			lvl4[15][9] = 0;
			cienpos.x = 69;
		}
		if (App->player->carrotDeletex == 179) {
			lvl4[16][22] = 0;
			lvl4[15][22] = 0;
			cienpos.x = 173;
		}
		App->player->colliderDelete->pendingToDelete = true;
	}
	if (App->player->carrotDeletey == 73) {
		cienpos.y = 96;
		if (App->player->carrotDeletex == 75) {
			lvl4[11][9] = 0;
			lvl4[10][9] = 0;
			cienpos.x = 69;
		}
		if (App->player->carrotDeletex == 179) {
			lvl4[11][22] = 0;
			lvl4[10][22] = 0;
			cienpos.x = 173;
		}
		App->player->colliderDelete->pendingToDelete = true;
	}
	

	// Enemy spawn timer
	if (i % 500 == 0 && j < 5)
	{
		App->enemies->AddEnemy(ENEMY_TYPE::FIREBALLS, 217, 196);
		j++;
	}
	i++;

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
			case 8:
				App->render->Blit(liveTexture, row * 8, column * 8, &tile, 0);
				break;

			}
		}
	}
	App->render->Blit(backTexture, 0, 0, &back, 0);

	
	if (cienpos.x != 0 && cienpos.y != 0) {

		App->render->Blit(cientexture, cienpos.x, cienpos.y, &cienrect);
		
	}
	

	return Update_Status::UPDATE_CONTINUE;
}

bool ModuleLvl4::CleanUp()
{
	App->collision->CleanUp();


	App->player->Disable();
	App->donkey->Disable();
	App->hammer->Disable();
	App->enemies->Disable();
	App->lady->Disable();
	App->score->Disable();
	return true;
}
