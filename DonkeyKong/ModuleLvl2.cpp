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
#include "ModuleObject.h"
#include "ModuleEnemies.h"
#include "ModuleCollisions.h"
#include "WinningScreen.h"
#include "IntroScreen.h"
#include "GameOver.h"
#include "ModuleLady.h"
#include "SDL.h"


int lives2[32][32]{ {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
				   {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
				   {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
				   {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
				   {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
				   {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
				   {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
				   {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
				   {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
				   {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
				   {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
				   {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
				   {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
				   {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
				   {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
				   {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
				   {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
				   {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
				   {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
				   {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
				   {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
				   {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
				   {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
				   {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
				   {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
				   {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
				   {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
				   {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
				   {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
				   {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
				   {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
				   {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
};

ModuleLvl2::ModuleLvl2(bool startEnabled) : Module(startEnabled)
{

}

ModuleLvl2::~ModuleLvl2()
{

}


bool ModuleLvl2::Start()
{
	change = false;

	App->player->isJumping = false;
	App->player->isFalling = false;

	App->object->hammer1exists = true;
	App->object->hammer2exists = true;
	App->object->bagexists = true;
	App->object->hatexists = true;
	App->object->paraguasexists = true;
	App->object->hammerOn = false;

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
	liveTexture = App->textures->Load("Assets/cositasfondo/MarioLive.png");

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
	App->collision->AddCollider({ 147, 54 , 2, 36 }, Collider::Type::LADDER);
	//special short boi
	leftLadcollidershort = App->collision->AddCollider({ 35, 109 , 2, 21 }, Collider::Type::LADDER);
	rightLadcollidershort = App->collision->AddCollider({ 219, 109 , 2, 21 }, Collider::Type::LADDER);

	//special long boi
	leftLadcolliderlong	= App->collision->AddCollider({ 35, 86 , 2, 44 }, Collider::Type::LADDER);
	rightLadcolliderlong= App->collision->AddCollider({ 219, 86 , 2, 44 }, Collider::Type::LADDER);
	

	//Falling colliders
	App->collision->AddCollider({ 71, 166 , 2, 10 }, Collider::Type::FALL);
	App->collision->AddCollider({ 176, 166 , 2, 10 }, Collider::Type::FALL);
	App->collision->AddCollider({ 135, 126 , 2, 10 }, Collider::Type::FALL);
	App->collision->AddCollider({ 119, 126 , 2, 10 }, Collider::Type::FALL);



	//Moving ladders
	ladVel = 1;
	count = 0;
	ladTexture = App->textures->Load("Assets/Enemies/EnemiesSprites.png");
	leftLad = {81, 194, 10, 16 };
	leftLadposition.x = 31;
	leftLadposition.y = 96;	
	
	rightLad = {81, 194, 10, 16 };
	rightLadposition.x = 216;
	rightLadposition.y = 96;

	// Enable Player
	App->object->Enable();
	App->score->Enable();
	App->player->Enable();
	App->donkey->Enable();
	App->enemies->Enable();
	App->lady->Enable();

	return true;
}

Update_Status ModuleLvl2::Update()
{
	// Lives
	for (int i = 0; i < 3; i++) {
		lives2[3][2 + i] = 0;
	}

	for (int i = 0; i < App->player->livecount; i++) {
		lives2[3][2 + i] = 1;
	}



	// Enemy spawn timer

	if (i % 50 == 0 && i % 100 != 0 && i % 150 != 0)
	{
		App->enemies->AddEnemy(ENEMY_TYPE::CAKES, 209, 120);
	}
	if (i % 50 == 0 && i % 100 != 0 && i % 150 == 0)
	{
		App->enemies->AddEnemy(ENEMY_TYPE::CAKES, 25, 120);
	}
	if (i % 100 == 0)
	{
		App->enemies->AddEnemy(ENEMY_TYPE::CAKES, 209, 200);
	}

	if (i == 1)
	{
		App->enemies->AddEnemy(ENEMY_TYPE::FIRESPARKS, 109, 105);
	}
	if (i % 150 == 0)
	{
		App->enemies->AddEnemy(ENEMY_TYPE::FIRESPARKS, 109, 105);
	}

	if (i % 200 == 0 )
	{
		change = true;
	}
	i++;
	
	//MovingLadders - necesito una imagen del trozo de escalera, con su rectangulo
	leftLadposition.y += ladVel;
	rightLadposition.y += ladVel;

	if (leftLadposition.y > 140 ) {
		ladVel = -1;
		leftLadcollidershort->SetPos(35, 109);
		leftLadcolliderlong->SetPos(0, 0);
		rightLadcollidershort->SetPos(219, 109);
		rightLadcolliderlong->SetPos(0, 0);
	}

	if (leftLadposition.y < 95) {
		ladVel = 0;
		leftLadcollidershort->SetPos(0, 0);
		leftLadcolliderlong->SetPos(35, 86);
		rightLadcollidershort->SetPos(0, 0);
		rightLadcolliderlong->SetPos(219, 86);

		if (j % 400 == 1) {
			ladVel = 1;
			j = 0;
			
		}
		
	}
	
	j++;


	return Update_Status::UPDATE_CONTINUE;
}

Update_Status ModuleLvl2::PostUpdate()
{

	App->render->Blit(background2Texture, 0, 0, &back, 0);

	int type = 0;
	for (int column = 0; column < 32; column++) {
		for (int row = 0; row < 32; row++) {
			type = lives2[column][row];
			switch (type) {
			case 0:
				App->render->Blit(backTexture, row * 8, column * 8, &tile, 0);
				break;
			case 1:
				App->render->Blit(liveTexture, row * 8, column * 8, &tile, 0);
				break;
			}
		}
	}

	if (cienpos.x != 0 && cienpos.y != 0) {

		App->render->Blit(cientexture, cienpos.x, cienpos.y, &cienrect);

	}
	App->render->Blit(backTexture, 0, 0, &back, 0);

	App->render->Blit(ladTexture, leftLadposition.x, leftLadposition.y, &leftLad);
	App->render->Blit(ladTexture, rightLadposition.x, rightLadposition.y, &rightLad);

	return Update_Status::UPDATE_CONTINUE;
}

bool ModuleLvl2::CleanUp()
{
	App->collision->CleanUp();


	App->player->Disable();
	App->object->Disable();
	App->donkey->Disable();
	App->hammer->Disable();
	App->enemies->Disable();
	App->lady->Disable();
	App->score->Disable();
	return true;
}