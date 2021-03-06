#include "WinningLvl3.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModuleAudio.h"
#include "ModuleInput.h"
#include "ModuleFadeToBlack.h"
#include "ModuleCollisions.h"
#include "ModulePlayer.h"
#include "ModuleScore.h"

int life2[32][32]{ {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
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

WinningLvl3::WinningLvl3(bool startEnabled) : Module(startEnabled)
{
	//donkey idle
	donkeyidleAnim.PushBack({ 34,66,40,32 });

	donkeyupAnim.PushBack({ 190,62,33,36 });
	donkeyupAnim.PushBack({ 60,112,33,36 });
	donkeyupAnim.speed = 0.1f;

	donkeywithoutladyAnim.PushBack({ 101,112,38,36 });
	donkeywithoutladyAnim.PushBack({ 147,116,43,32 });
	donkeywithoutladyAnim.speed = 0.1f;

	donkeywithladyAnim.PushBack({ 87,158,38,36 });
	donkeywithladyAnim.PushBack({ 133,162,43,32 });
	donkeywithladyAnim.speed = 0.1f;

	//heart anims
	heartAnim.PushBack({ 93, 77, 16, 13 });

	heartAnim1.PushBack({ 116, 77, 16, 13 });

	//lady anims
	rightidleladyAnim.PushBack({ 98,145,15,22 });

	ladyvoidAnim.PushBack({ 0,0,10,10 });

	//Mario anims
	leftmarioAnim.PushBack({ 0, 264, 50, 26 });
}

WinningLvl3::~WinningLvl3()
{
}


bool WinningLvl3::Start()
{
	LOG("Loading background assets");

	currentAnimation = &donkeyidleAnim;
	currentheartAnim = &heartAnim;
	currentladyAnim = &rightidleladyAnim;
	currentmarioAnim = &leftmarioAnim;
	bool ret = true;

	back = { 0, 0, 256, 256 };

	donkeypos.x = 40;
	donkeypos.y = 56;

	tile.w = 8;
	tile.h = 8;

	backgroundtileTexture = App->textures->Load("Assets/cositasfondo/background.png");
	liveTexture = App->textures->Load("Assets/cositasfondo/MarioLive.png");
	spritesTexture = App->textures->Load("Assets/Donkey/DonkeyKongSprites2.png");
	backgroundTexture = App->textures->Load("Assets/cositasfondo/background3.png");
	heartTexture = App->textures->Load("Assets/objects/RandomSprites.png");
	ladyTexture = App->textures->Load("Assets/Lady/PaulineSprites.png");
	marioTexture = App->textures->Load("Assets/Mario/MarioSprites.png");

	App->audio->PlayMusic("Assets/Music/08 Stage Clear 1.ogg", 1.0f);

	//Enable
	App->score->Enable();


	return ret;
}

Update_Status WinningLvl3::Update()
{
	//life count
	for (int j = 0; j < 3; j++) {
		life2[3][2 + j] = 0;
	}

	for (int j = 0; j < App->player->livecount; j++) {
		life2[3][2 + j] = 1;
	}

	if (donkeypos.x < 75)
	{
		donkeypos.x++;
	}
	if (donkeypos.x == 75)
	{
		if (donkeypos.y > 30)
		{
			currentAnimation = &donkeyupAnim;
		}
		else if (donkeypos.y > 25 && donkeypos.y < 30)
		{
			currentAnimation = &donkeywithoutladyAnim;
			currentheartAnim = &heartAnim1;
		}
		else
		{
			currentAnimation = &donkeywithladyAnim;
			currentladyAnim = &ladyvoidAnim;
		}
		if (i % 2 == 0)
		{
			donkeypos.y--;
		}
	}

	if (i % 240 == 0) {
		App->fade->FadeToBlack(this, (Module*)App->lvl4, 0);
	}

	currentAnimation->Update();
	currentheartAnim->Update();
	currentladyAnim->Update();
	currentmarioAnim->Update();
	i++;

	return Update_Status::UPDATE_CONTINUE;
}



Update_Status WinningLvl3::PostUpdate()
{
	int type = 0;
	for (int column = 0; column < 32; column++) {
		for (int row = 0; row < 32; row++) {
			type = life2[column][row];
			switch (type) {
			case 0:
				App->render->Blit(backgroundtileTexture, row * 8, column * 8, &tile, 0);
				break;
			case 1:
				App->render->Blit(liveTexture, row * 8, column * 8, &tile, 0);
				break;
			}
		}
	}

	SDL_Rect rectdonkey = currentAnimation->GetCurrentFrame();
	SDL_Rect rectheart = currentheartAnim->GetCurrentFrame();
	SDL_Rect rectlady = currentladyAnim->GetCurrentFrame();
	SDL_Rect rectmario = currentmarioAnim->GetCurrentFrame();

	App->render->Blit(backgroundTexture, 0, 0, &back);
	App->render->Blit(spritesTexture, donkeypos.x, donkeypos.y, &rectdonkey);
	App->render->Blit(heartTexture, 120, 28, &rectheart);
	App->render->Blit(ladyTexture, 104, 34, &rectlady);
	App->render->Blit(marioTexture, 125, 30, &rectmario);


	return Update_Status::UPDATE_CONTINUE;
}

bool WinningLvl3::CleanUp() {

	App->textures->Unload(backgroundTexture);
	App->score->Disable();


	return true;
}
