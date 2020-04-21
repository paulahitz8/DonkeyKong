#include "WinningScreen.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModuleAudio.h"
#include "ModuleInput.h"
#include "ModuleFadeToBlack.h"
#include "ModuleCollisions.h"
#include "ModulePlayer.h"
#include "ModuleScore.h"

int life[32][32]{ {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
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

WinningScreen::WinningScreen(bool startEnabled) : Module(startEnabled)
{
	//donkey idle
	donkeyidleAnim.PushBack({ 22,46,40,32 });

	//angry anim
	angryAnim.PushBack({ 70,46,46,32 });
	angryAnim.PushBack({ 124,46,46,32 });
	angryAnim.loop = true;
	angryAnim.speed = 0.1f;

	//down anim
	downAnim.PushBack({ 178,46,40,32 });

	//dizzy anim
	dizzyAnim.PushBack({ 51,87,40,40 });
	dizzyAnim.PushBack({ 99,87,40,40 });
	dizzyAnim.PushBack({ 147,87,40,40 });
	dizzyAnim.PushBack({ 52,133,40,40 });
	dizzyAnim.PushBack({ 100,133,40,40 });
	dizzyAnim.PushBack({ 148,133,40,40 });
	dizzyAnim.loop = true;
	dizzyAnim.speed = 0.1f;


}

WinningScreen::~WinningScreen()
{
}


bool WinningScreen::Start()
{
	LOG("Loading background assets");

	currentAnimation = &donkeyidleAnim;
	bool ret = true;

	back = { 0, 0, 256, 256 };

	donkeypos.x = 108;
	donkeypos.y = 56;

	pauline = {8, 189, 16, 22};
	mario = {34, 195, 12, 16};
	heart = {57, 189, 15, 13};
	donkey = {22, 46, 40, 32};

	tile.w = 8;
	tile.h = 8;

	backgroundtileTexture = App->textures->Load("Assets/cositasfondo/background.png");
	liveTexture = App->textures->Load("Assets/cositasfondo/MarioLive.png");
	spritesTexture = App->textures->Load("Assets/Ending/sprites.png");
	backgroundTexture = App->textures->Load("Assets/Ending/one.png");
	happybackgroundTexture = App->textures->Load("Assets/Ending/happyending.png");
	
	App->audio->PlayMusic("Assets/Music/try.ogg", 1.0f);

	//Enable
	App->score->Enable();


	return ret;
}

Update_Status WinningScreen::Update()
{
	//life count
	for (int j = 0; j < 3; j++) {
		life[3][2 + j] = 0;
	}

	for (int j = 0; j < App->player->livecount; j++) {
		life[3][2 + j] = 1;
	}


	//animation times
	if (i < 50) {
		a = 1;
		
	}
	if (i > 50 && i < 200) {
		a = 2;
		currentAnimation = &angryAnim;
	}

	if (i > 200 && i < 300) {
		a = 3;
		currentAnimation = &downAnim;
		donkeypos.y += 1.3;
	}

	if (i > 300 && i < 370) {
		a = 4;
		currentAnimation = &dizzyAnim;
		donkeypos.y = 184;

	}

	if (i > 370 && i < 400) {
		a = 5;
		currentAnimation = &dizzyAnim;
		donkeypos.y = 184;
	}

	if (i > 400) {
		a = 6;
		currentAnimation = &dizzyAnim;
		donkeypos.y = 184;
	}

	if (i > 730) {
		App->fade->FadeToBlack(this, (Module*)App->intro, 30);
	}

	currentAnimation->Update();
	i++;


	return Update_Status::UPDATE_CONTINUE;
}



Update_Status WinningScreen::PostUpdate()
{
	int type = 0;
	for (int column = 0; column < 32; column++) {
		for (int row = 0; row < 32; row++) {
			type = life[column][row];
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

	SDL_Rect rect = currentAnimation->GetCurrentFrame();
	
	if (a == 1) {
		
		App->render->Blit(backgroundTexture, 0, 0, &back);
		App->render->Blit(spritesTexture, 120, 26, &pauline);
		App->render->Blit(spritesTexture, donkeypos.x, donkeypos.y, &donkey);
		App->render->Blit(spritesTexture, App->player->position.x + 17, App->player->position.y + 10, &mario);
	}
	else if (a == 2) {
		App->render->Blit(backgroundTexture, 0, 0, &back);
		App->render->Blit(spritesTexture, 120, 26, &pauline);
		App->render->Blit(spritesTexture, donkeypos.x, donkeypos.y, &rect);
		App->render->Blit(spritesTexture, App->player->position.x + 17, App->player->position.y + 10, &mario);
	}

	else if (a == 3) {
		App->render->Blit(backgroundTexture, 0, 0, &back);
		App->render->Blit(spritesTexture, 120, 26, &pauline);
		App->render->Blit(spritesTexture, donkeypos.x, donkeypos.y, &rect);
		App->render->Blit(spritesTexture, App->player->position.x + 17, App->player->position.y + 10, &mario);

	}
	
	else if (a == 4) {
		App->render->Blit(happybackgroundTexture, 0, 0, &back);
		App->render->Blit(spritesTexture, 120, 66, &pauline);
		App->render->Blit(spritesTexture, donkeypos.x, donkeypos.y, &rect);
		App->render->Blit(spritesTexture, App->player->position.x + 17, App->player->position.y + 10, &mario);

	}

	else if (a == 5) {
		App->render->Blit(happybackgroundTexture, 0, 0, &back);
		App->render->Blit(spritesTexture, 120, 66, &pauline);
		App->render->Blit(spritesTexture, donkeypos.x, donkeypos.y, &rect);
		App->render->Blit(spritesTexture, 154, 72, &mario);

	}

	else if (a == 6) {
		App->render->Blit(happybackgroundTexture, 0, 0, &back);
		App->render->Blit(spritesTexture, 120, 66, &pauline);
		App->render->Blit(spritesTexture, donkeypos.x, donkeypos.y, &rect);
		App->render->Blit(spritesTexture, 154, 72, &mario);
		App->render->Blit(spritesTexture, 138, 59, &heart);

	}

	
	return Update_Status::UPDATE_CONTINUE;
}

bool WinningScreen::CleanUp() {

	App->textures->Unload(backgroundTexture);
	App->score->Disable();

	return true;
}
