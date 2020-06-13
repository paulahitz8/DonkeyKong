#include "ModuleLvl3.h"
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


int lvl3Initial[32][32]{ {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
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

ModuleLvl3::ModuleLvl3(bool startEnabled) : Module(startEnabled)
{

}

ModuleLvl3::~ModuleLvl3()
{

}


bool ModuleLvl3::Start()
{

	App->object->bagexists = true;
	App->object->hatexists = true;
	App->object->paraguasexists = true;
	


	i = 1;
	App->player->activelevel = 3;
	lvl3status = true;

	if (App->gameover->gameover == true)
	{
		lvl3score = true;
		App->player->n = 0;
		App->gameover->gameover = false;
	}
	App->winning->win = false;
	App->intro->intro = false;

	// FUnciona mas o menos pero la zanahoria que coges justo antes de morir no spawnea otra vez

	for (int a = 0; a < 32; a++) {
		for (int b = 0; b < 32; b++) {
			lvl3[a][b] = lvl3Initial[a][b];
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

	background3Texture = App->textures->Load("Assets/cositasfondo/background3.png");
	floorTexture = App->textures->Load("Assets/cositasfondo/suelo.png");
	floorCarrotTexture = App->textures->Load("Assets/cositasfondo/sueloencimazanahoria.png");
	carrotTexture = App->textures->Load("Assets/cositasfondo/zanahoria.png");
	ladderTexture = App->textures->Load("Assets/cositasfondo/escalera.png");
	floorLadderTexture = App->textures->Load("Assets/cositasfondo/sueloescalera.png");
	leftPoleTexture = App->textures->Load("Assets/cositasfondo/barraizquierda.png");
	rightPoleTexture = App->textures->Load("Assets/cositasfondo/barraderecha.png");
	liveTexture = App->textures->Load("Assets/cositasfondo/MarioLive.png");

	// Level 3 colliders:
	// Walls and ground by floor
	App->collision->AddCollider({ 0, 245, 14, 11 }, Collider::Type::WALL);
	App->collision->AddCollider({ 16, 247, 224, 9 }, Collider::Type::GROUND);
	App->collision->AddCollider({ 16 + 223 + 3, 246, 16, 11 }, Collider::Type::WALL);

	App->collision->AddCollider({ 0, 319, 14, 11 }, Collider::Type::WALL);
	App->collision->AddCollider({ 16, 321, 24, 9 }, Collider::Type::GROUND);


	App->collision->AddCollider({ 0, 189, 14, 11 }, Collider::Type::WALL);
	App->collision->AddCollider({ 16, 191, 24, 9 }, Collider::Type::GROUND);

	App->collision->AddCollider({ 0, 133, 14, 11 }, Collider::Type::WALL);
	App->collision->AddCollider({ 16, 135, 24, 9 }, Collider::Type::GROUND);

	App->collision->AddCollider({ 0, 85, 14, 11 }, Collider::Type::WALL);
	App->collision->AddCollider({ 16, 87, 168, 9 }, Collider::Type::GROUND);




	App->collision->AddCollider({ 80, 207, 24, 9 }, Collider::Type::GROUND);
	App->collision->AddCollider({ 72, 135, 32, 9 }, Collider::Type::GROUND);
	App->collision->AddCollider({ 136, 231, 24, 9 }, Collider::Type::GROUND);
	App->collision->AddCollider({ 168, 223, 16, 9 }, Collider::Type::GROUND);
	App->collision->AddCollider({ 192, 215, 16, 9 }, Collider::Type::GROUND);
	App->collision->AddCollider({ 216, 207, 24, 9 }, Collider::Type::GROUND);
	App->collision->AddCollider({ 224, 183, 16, 9 }, Collider::Type::GROUND);
	App->collision->AddCollider({ 200, 175, 16, 9 }, Collider::Type::GROUND);
	App->collision->AddCollider({ 152, 159, 16, 9 }, Collider::Type::GROUND);
	App->collision->AddCollider({ 200, 143, 40, 9 }, Collider::Type::GROUND);
	App->collision->AddCollider({ 144, 127, 24, 9 }, Collider::Type::GROUND);
	App->collision->AddCollider({ 176, 119, 16, 9 }, Collider::Type::GROUND);
	App->collision->AddCollider({ 200, 111, 16, 9 }, Collider::Type::GROUND);
	App->collision->AddCollider({ 224, 103, 16, 9 }, Collider::Type::GROUND);
	App->collision->AddCollider({ 104, 55, 48, 9 }, Collider::Type::GROUND);
	App->collision->AddCollider({ 176, 167, 16, 9 }, Collider::Type::GROUND);
	App->collision->AddCollider({ 16, 231, 24, 9 }, Collider::Type::GROUND);


	



	// Ladders by floor
	App->collision->AddCollider({ 27, 190 , 2, 44 }, Collider::Type::LADDER);
	App->collision->AddCollider({ 35, 134 , 2, 60 }, Collider::Type::LADDER);
	App->collision->AddCollider({ 83, 134 , 2, 76 }, Collider::Type::LADDER);
	App->collision->AddCollider({ 99, 134 , 2, 76 }, Collider::Type::LADDER);
	App->collision->AddCollider({ 227, 182 , 2, 28 }, Collider::Type::LADDER);
	App->collision->AddCollider({ 203, 142 , 2, 36 }, Collider::Type::LADDER);
	App->collision->AddCollider({ 227, 102 , 2, 44 }, Collider::Type::LADDER);
	App->collision->AddCollider({ 179, 86 , 2, 36 }, Collider::Type::LADDER);
	App->collision->AddCollider({ 147, 54 , 2, 36 }, Collider::Type::LADDER);


	//Moving floors 104
	//LEFT
	movingFloorTex = App->textures->Load("Assets/cositasfondo/suelo.png");
	leftFloorRectA = { 0, 0, 9, 10 };
	leftFloorA.x = 51;
	leftFloorA.y = 238;
	leftFloorCoA = App->collision->AddCollider({ leftFloorA.x, leftFloorA.y, 10, 9 }, Collider::Type::LEFTFLOOR);

	leftFloorRectB = { 0, 0, 9, 10 };
	leftFloorB.x = 51;
	leftFloorB.y = 190;
	leftFloorCoB = App->collision->AddCollider({ leftFloorB.x, leftFloorB.y, 10, 9 }, Collider::Type::LEFTFLOOR);

	leftFloorRectC = { 0, 0, 9, 10 };
	leftFloorC.x = 51;
	leftFloorC.y = 140;
	leftFloorCoC = App->collision->AddCollider({ leftFloorC.x, leftFloorC.y, 10, 9 }, Collider::Type::LEFTFLOOR);

	//RIGHT
	movingFloorTex = App->textures->Load("Assets/cositasfondo/suelo.png");
	rightFloorRectA = { 0, 0, 9, 10 };
	rightFloorA.x = 115;
	rightFloorA.y = 238;
	rightFloorCoA = App->collision->AddCollider({ rightFloorA.x, rightFloorA.y, 10, 9 }, Collider::Type::GROUND);

	rightFloorRectB = { 0, 0, 9, 10 };
	rightFloorB.x = 115;
	rightFloorB.y = 190;
	rightFloorCoB = App->collision->AddCollider({ rightFloorB.x, rightFloorB.y, 10, 9 }, Collider::Type::GROUND);

	rightFloorRectC = { 0, 0, 9, 10 };
	rightFloorC.x = 115;
	rightFloorC.y = 140;
	rightFloorCoC = App->collision->AddCollider({ rightFloorC.x, rightFloorC.y, 10, 9 }, Collider::Type::GROUND);


	// Enable Player
	App->object->Enable();
	App->score->Enable();
	App->player->Enable();
	App->donkey->Enable();
	//App->hammer->Enable();
	App->enemies->Enable();
	App->lady->Enable();

	return true;
}

Update_Status ModuleLvl3::Update()
{
	// Lives
	for (int ilive = 0; ilive < 3; ilive++) {

		lvl3[3][2 + ilive] = 0;

	}

	for (int ilive = 0; ilive < App->player->livecount; ilive++) {

		lvl3[3][2 + ilive] = 8;

	}



	// Enemy spawn timer

	if (i % 120 == 0)
	{
		App->enemies->AddEnemy(ENEMY_TYPE::JUMPER, 16, 57);
	}
	if (i == 1)
	{
		App->enemies->AddEnemy(ENEMY_TYPE::FIRESPARKS, 217, 190);
		App->enemies->AddEnemy(ENEMY_TYPE::FIRESPARKS, 217, 196);
	}
	i++;


	//MovingFloors
	//LEFT
	/*leftFloorA.y--;
	if (leftFloorA.y == 94) {
		leftFloorA.y = 248;
	}
	leftFloorCoA->SetPos(leftFloorA.x, leftFloorA.y);

	leftFloorB.y--;
	if (leftFloorB.y == 94) {
		leftFloorB.y = 248;
	}
	leftFloorCoB->SetPos(leftFloorB.x, leftFloorB.y);

	leftFloorC.y--;
	if (leftFloorC.y == 94) {
		leftFloorC.y = 248;
	}
	leftFloorCoC->SetPos(leftFloorC.x, leftFloorC.y);

	//RIGHT
	rightFloorA.y++;
	if (rightFloorA.y == 248) {
		rightFloorA.y = 94;
	}
	rightFloorCoA->SetPos(rightFloorA.x, rightFloorA.y);

	rightFloorB.y++;
	if (rightFloorB.y == 248) {
		rightFloorB.y = 94;
	}
	rightFloorCoB->SetPos(rightFloorB.x, rightFloorB.y);

	rightFloorC.y++;
	if (rightFloorC.y == 248) {
		rightFloorC.y = 94;
	}
	rightFloorCoC->SetPos(rightFloorC.x, rightFloorC.y);*/



	return Update_Status::UPDATE_CONTINUE;
}

Update_Status ModuleLvl3::PostUpdate()
{

	int type = 0;

	App->render->Blit(background3Texture, 0, 0, &back, 0);


	if (cienpos.x != 0 && cienpos.y != 0) {

		App->render->Blit(cientexture, cienpos.x, cienpos.y, &cienrect);

	}

	App->render->Blit(movingFloorTex, leftFloorA.x, leftFloorA.y, &leftFloorRectA);
	App->render->Blit(movingFloorTex, leftFloorB.x, leftFloorB.y, &leftFloorRectB);
	App->render->Blit(movingFloorTex, leftFloorC.x, leftFloorC.y, &leftFloorRectC);

	App->render->Blit(movingFloorTex, rightFloorA.x, rightFloorA.y, &rightFloorRectA);
	App->render->Blit(movingFloorTex, rightFloorB.x, rightFloorB.y, &rightFloorRectB);
	App->render->Blit(movingFloorTex, rightFloorC.x, rightFloorC.y, &rightFloorRectC);
	App->render->Blit(backTexture, 0, 0, &back, 0);
	return Update_Status::UPDATE_CONTINUE;
}

bool ModuleLvl3::CleanUp()
{
	App->collision->CleanUp();

	App->object->Disable();
	App->player->Disable();
	App->donkey->Disable();
	App->hammer->Disable();
	App->enemies->Disable();
	App->lady->Disable();
	App->score->Disable();
	return true;
}
