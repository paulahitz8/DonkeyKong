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


	//backTexture = App->textures->Load("Assets/cositasfondo/backgroundconcosas.png");
	cientexture = App->textures->Load("Assets/Lady/RandomSprites.png");

	background2Texture = App->textures->Load("Assets/cositasfondo/background2.png");
	ladderTexture = App->textures->Load("Assets/cositasfondo/escalera.png");

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
	App->collision->AddCollider({ 35, 111 , 2, 21 }, Collider::Type::LADDER);
	App->collision->AddCollider({ 147, 54 , 2, 36 }, Collider::Type::LADDER);
	
	//Moving ladders
	ladVel = 1;
	count = 0;
	ladTexture = App->textures->Load("Assets/cositasfondo/escalera.png");
	leftLad = {0, 0, 9, 10 };
	leftLadposition.x = 31;
	leftLadposition.y = 96;

	leftLadcollider = App->collision->AddCollider({ leftLadposition.x + 3, leftLadposition.y - 9, 2, 25 }, Collider::Type::LADDER);

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

	
	//MovingLadders - necesito una imagen del trozo de escalera, con su rectangulo
	leftLadposition.y += ladVel;

	/*if (leftLadposition.y > 140) {
		leftLadposition.y--;
		ladVel = 0;
		count = 0;
	}

	if (leftLadposition.y < 95) {
		leftLadposition.y++;
		ladVel = 0;
		count = 0;
	}
	
	if (count == 50) {
		ladVel++;
	}*/

	if (leftLadposition.y > 140 || leftLadposition.y < 95) {
		ladVel = -ladVel;
	}

	//count++;

	leftLadcollider->SetPos(leftLadposition.x + 3, leftLadposition.y - 9);


	return Update_Status::UPDATE_CONTINUE;
}

Update_Status ModuleLvl2::PostUpdate()
{

	int type = 0;


	App->render->Blit(background2Texture, 0, 0, &back, 0);

	if (cienpos.x != 0 && cienpos.y != 0) {

		App->render->Blit(cientexture, cienpos.x, cienpos.y, &cienrect);

	}

	App->render->Blit(ladTexture, leftLadposition.x, leftLadposition.y, &leftLad);

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