#include "ModuleLvl4.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModuleInput.h"
#include "ModuleAudio.h"
#include "ModulePlayer.h"
#include "ModuleDonkey.h"
#include "ModuleEnemies.h"
#include "ModuleCollisions.h"
#include "ModuleLady.h"
#include "SDL.h"


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

	// Level 4 colliders:
	// Base
	App->collision->AddCollider({ 0, 247, 16, 9 }, Collider::Type::WALL);
	App->collision->AddCollider({ 16, 247, 224, 9 }, Collider::Type::GROUND); 
	App->collision->AddCollider({ 16 + 224, 247, 16, 9 }, Collider::Type::WALL);

	// First floor
	App->collision->AddCollider({ 0, 206, 22, 10 }, Collider::Type::WALL);
	App->collision->AddCollider({ 24, 207, 49, 9 }, Collider::Type::GROUND); 
	App->collision->AddCollider({ 79, 207, 98, 9 }, Collider::Type::GROUND);  
	App->collision->AddCollider({ 79 + 98 + 6, 207, 49, 9 }, Collider::Type::GROUND); 
	App->collision->AddCollider({ 79 + 98 + 6 + 49, 207, 24, 9 }, Collider::Type::WALL);

	// Second floor
	App->collision->AddCollider({ 0, 168, 30, 9 }, Collider::Type::WALL);
	App->collision->AddCollider({ 32, 168, 41, 8 }, Collider::Type::GROUND); 
	App->collision->AddCollider({ 79, 168, 98, 8 }, Collider::Type::GROUND); 
	App->collision->AddCollider({ 79 + 98 + 6, 168, 41, 9 }, Collider::Type::GROUND); 
	App->collision->AddCollider({ 79 + 98 + 6 + 41, 168, 32, 9 }, Collider::Type::WALL);

	// Third floor
	App->collision->AddCollider({ 0, 128, 38, 9 }, Collider::Type::WALL);
	App->collision->AddCollider({ 40, 128, 33, 8 }, Collider::Type::GROUND); 
	App->collision->AddCollider({ 79, 128, 98, 8 }, Collider::Type::GROUND); 
	App->collision->AddCollider({ 79 + 98 + 6, 128, 33, 9 }, Collider::Type::GROUND); 
	App->collision->AddCollider({ 79 + 98 + 6 + 33, 128, 40, 9 }, Collider::Type::WALL);

	// Fourth floor
	App->collision->AddCollider({ 0, 88, 46, 9 }, Collider::Type::WALL);
	App->collision->AddCollider({ 48, 88, 25, 8 }, Collider::Type::GROUND); 
	App->collision->AddCollider({ 79, 88, 98, 8 }, Collider::Type::GROUND); 
	App->collision->AddCollider({ 79 + 98 + 6, 88, 25, 9 }, Collider::Type::GROUND); 
	App->collision->AddCollider({ 79 + 98 + 6 + 25, 88, 48, 9 }, Collider::Type::WALL);

	// Fifth floor
	App->collision->AddCollider({ 0, 48, 70, 9 }, Collider::Type::WALL);
	App->collision->AddCollider({ 72, 48, 112, 9 }, Collider::Type::GROUND); 
	App->collision->AddCollider({ 72 + 112, 48, 72, 9 }, Collider::Type::WALL);
	
																			  
	// Base floor ladders
	App->collision->AddCollider({ 24, 205 , 8, 44 }, Collider::Type::LADDER);
	App->collision->AddCollider({ 120, 205 , 8, 44 }, Collider::Type::LADDER);
	App->collision->AddCollider({ 224, 205 , 8, 44 }, Collider::Type::LADDER);

	App->collision->AddCollider({ 32, 166 , 8, 44 }, Collider::Type::LADDER);
	App->collision->AddCollider({ 88, 166 , 8, 44 }, Collider::Type::LADDER);
	App->collision->AddCollider({ 160, 166 , 8, 44 }, Collider::Type::LADDER);
	App->collision->AddCollider({ 216, 166 , 8, 44 }, Collider::Type::LADDER);

	App->collision->AddCollider({ 40, 126 , 8, 44 }, Collider::Type::LADDER);
	App->collision->AddCollider({ 120, 126 , 8, 44 }, Collider::Type::LADDER);
	App->collision->AddCollider({ 208, 126 , 8, 44 }, Collider::Type::LADDER);

	App->collision->AddCollider({ 48, 86 , 8, 44 }, Collider::Type::LADDER);
	App->collision->AddCollider({ 80, 86 , 8, 44 }, Collider::Type::LADDER);
	App->collision->AddCollider({ 168, 86 , 8, 44 }, Collider::Type::LADDER);
	App->collision->AddCollider({ 200, 86 , 8, 44 }, Collider::Type::LADDER);


	// Enable Player?

	App->player->Enable();
	App->donkey->Enable();
	App->enemies->Enable();
	App->lady->Enable();
	App->enemies->AddEnemy(ENEMY_TYPE::FIREBALLS, 217, 196);
	return true;
}

Update_Status ModuleLvl4::Update()
{
	if (i % 500 == 0 && j <= 5)
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
	App->enemies->Disable();
	App->lady->Disable();
	return true;
}
