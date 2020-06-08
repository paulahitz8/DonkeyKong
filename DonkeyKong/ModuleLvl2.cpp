#include "ModuleLvl2.h"
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
#include "IntroScreen.h"
#include "GameOver.h"
#include "ModuleLady.h"
#include "SDL.h"


int lvl2Initial[32][32]{ {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
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

ModuleLvl2::ModuleLvl2(bool startEnabled) : Module(startEnabled)
{

}

ModuleLvl2::~ModuleLvl2()
{

}


bool ModuleLvl2::Start()
{
	i = 1;
	App->player->activelevel = 2;

	if (App->gameover->gameover == true)
	{
		lvl2score = true;
		App->player->n = 0;
		App->gameover->gameover = false;
	}

	App->winning->win = false;
	App->intro->intro = false;

	// FUnciona mas o menos pero la zanahoria que coges justo antes de morir no spawnea otra vez

	for (int a = 0; a < 32; a++) {
		for (int b = 0; b < 32; b++) {
			lvl2[a][b] = lvl2Initial[a][b];
		}
	}

	cienpos.x = 0;
	cienpos.y = 0;

	App->audio->PlayMusic("Assets/Music/stage2.ogg", 1.0f);

	//TILEMAP

	tile.w = 8;
	tile.h = 8;
	back.w = 256;
	back.h = 256;
	cienrect = { 59,104,15,7 };


	backTexture = App->textures->Load("Assets/cositasfondo/backgroundconcosas.png");
	cientexture = App->textures->Load("Assets/Lady/RandomSprites.png");

	background2Texture = App->textures->Load("Assets/cositasfondo/background2.png");
	floorTexture = App->textures->Load("Assets/cositasfondo/suelo.png");
	floorCarrotTexture = App->textures->Load("Assets/cositasfondo/sueloencimazanahoria.png");
	carrotTexture = App->textures->Load("Assets/cositasfondo/zanahoria.png");
	ladderTexture = App->textures->Load("Assets/cositasfondo/escalera.png");
	floorLadderTexture = App->textures->Load("Assets/cositasfondo/sueloescalera.png");
	leftPoleTexture = App->textures->Load("Assets/cositasfondo/barraizquierda.png");
	rightPoleTexture = App->textures->Load("Assets/cositasfondo/barraderecha.png");
	liveTexture = App->textures->Load("Assets/cositasfondo/MarioLive.png");

	// Level 2 colliders:
	// Walls and ground by floor
	App->collision->AddCollider({ 0, 245, 14, 11 }, Collider::Type::WALL);
	App->collision->AddCollider({ 16, 247, 224, 9 }, Collider::Type::GROUND);
	App->collision->AddCollider({ 16 + 223 + 3, 246, 14, 11 }, Collider::Type::WALL);

	App->collision->AddCollider({ 0, 205, 22, 11 }, Collider::Type::WALL);
	App->collision->AddCollider({ 24, 207, 208, 9 }, Collider::Type::GROUND);
	App->collision->AddCollider({ 79 + 97 + 6 + 49 + 3, 205, 22, 11 }, Collider::Type::WALL);

	App->collision->AddCollider({ 0, 165, 22, 11 }, Collider::Type::WALL);
	App->collision->AddCollider({ 24, 167, 40, 9 }, Collider::Type::GROUND);
	App->collision->AddCollider({ 80, 167, 88, 9 }, Collider::Type::GROUND);
	App->collision->AddCollider({ 184, 167, 48, 9 }, Collider::Type::GROUND);
	App->collision->AddCollider({ 184 + 48 + 2 , 165, 22, 11 }, Collider::Type::WALL);

	App->collision->AddCollider({ 0, 125, 14, 11 }, Collider::Type::WALL);
	App->collision->AddCollider({ 16, 127, 96, 9 }, Collider::Type::GROUND);
	App->collision->AddCollider({ 144, 127, 96, 9 }, Collider::Type::GROUND);
	App->collision->AddCollider({ 144 + 96 + 2, 125, 14, 11 }, Collider::Type::WALL);

	App->collision->AddCollider({ 0, 85, 22, 11 }, Collider::Type::WALL);
	App->collision->AddCollider({ 24, 87, 208, 9 }, Collider::Type::GROUND);
	App->collision->AddCollider({ 24+208+2, 85, 22, 11 }, Collider::Type::WALL);

	App->collision->AddCollider({ 0, 52, 102, 11 }, Collider::Type::WALL);
	App->collision->AddCollider({ 104, 55, 48, 9 }, Collider::Type::GROUND);
	App->collision->AddCollider({ 104+48 + 3, 52, 72, 11 }, Collider::Type::WALL);


	// Ladders by floor
	App->collision->AddCollider({ 43, 206 , 2, 44 }, Collider::Type::LADDER);
	App->collision->AddCollider({ 99, 206 , 2, 44 }, Collider::Type::LADDER);
	App->collision->AddCollider({ 155, 206 , 2, 44 }, Collider::Type::LADDER);
	App->collision->AddCollider({ 211, 206 , 2, 44 }, Collider::Type::LADDER);
	App->collision->AddCollider({ 83, 166 , 2, 44 }, Collider::Type::LADDER);
	App->collision->AddCollider({ 163, 166 , 2, 44 }, Collider::Type::LADDER);
	App->collision->AddCollider({ 43, 126 , 2, 44 }, Collider::Type::LADDER);
	App->collision->AddCollider({ 99, 126 , 2, 44 }, Collider::Type::LADDER);
	App->collision->AddCollider({ 155, 126 , 2, 44 }, Collider::Type::LADDER);
	App->collision->AddCollider({ 211, 126 , 2, 44 }, Collider::Type::LADDER);
	App->collision->AddCollider({ 219, 109 , 2, 21 }, Collider::Type::LADDER);
	App->collision->AddCollider({ 35, 109 , 2, 21 }, Collider::Type::LADDER);
	App->collision->AddCollider({ 147, 54 , 2, 36 }, Collider::Type::LADDER);
	


	// Enable Player
	App->score->Enable();
	App->player->Enable();
	App->donkey->Enable();
	App->hammer->Enable();
	App->enemies->Enable();
	App->lady->Enable();

	return true;
}

Update_Status ModuleLvl2::Update()
{
	// Lives
	for (int ilive = 0; ilive < 3; ilive++) {

		lvl2[3][2 + ilive] = 0;

	}

	for (int ilive = 0; ilive < App->player->livecount; ilive++) {

		lvl2[3][2 + ilive] = 8;

	}

	// Carrots
	if (App->player->carrotDeletey == 193) {
		cienpos.y = 216;
		if (App->player->carrotDeletex == 75) {
			lvl2[26][9] = 0;
			lvl2[25][9] = 0;
			cienpos.x = 69;
		}
		else if (App->player->carrotDeletex == 179) {
			lvl2[26][22] = 0;
			lvl2[25][22] = 0;
			cienpos.x = 173;
		}
		App->player->colliderDelete->pendingToDelete = true;
	}
	else if (App->player->carrotDeletey == 153) {
		cienpos.y = 176;
		if (App->player->carrotDeletex == 75) {
			lvl2[21][9] = 0;
			lvl2[20][9] = 0;
			cienpos.x = 69;
		}
		else if (App->player->carrotDeletex == 179) {
			lvl2[21][22] = 0;
			lvl2[20][22] = 0;
			cienpos.x = 173;
		}
		App->player->colliderDelete->pendingToDelete = true;
	}
	else if (App->player->carrotDeletey == 113) {
		cienpos.y = 136;
		if (App->player->carrotDeletex == 75) {
			lvl2[16][9] = 0;
			lvl2[15][9] = 0;
			cienpos.x = 69;
		}
		else if (App->player->carrotDeletex == 179) {
			lvl2[16][22] = 0;
			lvl2[15][22] = 0;
			cienpos.x = 173;
		}
		App->player->colliderDelete->pendingToDelete = true;
	}
	else if (App->player->carrotDeletey == 73) {
		cienpos.y = 96;
		if (App->player->carrotDeletex == 75) {
			lvl2[11][9] = 0;
			lvl2[10][9] = 0;
			cienpos.x = 69;
		}
		else if (App->player->carrotDeletex == 179) {
			lvl2[11][22] = 0;
			lvl2[10][22] = 0;
			cienpos.x = 173;
		}
		App->player->colliderDelete->pendingToDelete = true;
	}


	// Enemy spawn timer

	if (i % 1002 == 0)
	{
		App->enemies->AddEnemy(ENEMY_TYPE::FIREBALLS, 209, 156);
	}
	else if (i % 501 == 0 && (i % 1002 != 0) && (i % 1503 != 0) && (i % 2505 != 0))
	{
		App->enemies->AddEnemy(ENEMY_TYPE::FIREBALLS, 217, 196);
	}
	else if ((i % 1503 == 0) || (i % 2505 == 0))
	{
		App->enemies->AddEnemy(ENEMY_TYPE::FIREBALLS, 201, 116);
	}
	i++;

	return Update_Status::UPDATE_CONTINUE;
}

Update_Status ModuleLvl2::PostUpdate()
{

	int type = 0;

	/*for (int column = 0; column < 32; column++) {
		for (int row = 0; row < 32; row++) {

			type = lvl2[column][row];

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
	}*/
	//App->render->Blit(backTexture, 0, 0, &back, 0);
	App->render->Blit(background2Texture, 0, 0, &back, 0);


	if (cienpos.x != 0 && cienpos.y != 0) {

		App->render->Blit(cientexture, cienpos.x, cienpos.y, &cienrect);

	}


	return Update_Status::UPDATE_CONTINUE;
}

bool ModuleLvl2::CleanUp()
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