#include "ModuleScore.h"

#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModuleAudio.h"
#include "ModuleInput.h"
#include "IntroScreen.h"
#include "ModuleFadeToBlack.h"
#include "ModulePlayer.h"
#include "GameOver.h"
#include "WinningScreen.h"

int score[32][32]{	{10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10},
					{10,10,10,0,0,0,0,0,0,10,10,10,10,0,0,0,0,0,0,10,10,10,10,10,10,10,10,10,10,10,10,10},
					{10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10},
					{10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10},
					{10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10},
					{10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10},
					{10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10},
					{10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10},
					{10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10},
					{10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10},
					{10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10},
					{10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10},
					{10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10},
					{10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10},
					{10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10},
					{10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10},
					{10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10},
					{10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10},
					{10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10},
					{10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10},
					{10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10},
					{10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10},
					{10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10},
					{10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10},
					{10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10},
					{10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10},
					{10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10},
					{10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10},
					{10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10},
					{10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10},
					{10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10},
					{10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10},
};


ModuleScore::ModuleScore(bool startEnabled) : Module(startEnabled)
{

}

ModuleScore::~ModuleScore()
{

}


bool ModuleScore::Start()
{
	LOG("Loading background assets");



	//for (int a = 0; a < 32; a++) {
	//	for (int b = 0; b < 32; b++) {
	//		score[a][b] = scoreinitial[a][b];
	//	}
	//}




	bool ret = true;

	number.w = 8;
	number.h = 8;

	backkTexture = App->textures->Load("Assets/cositasfondo/R1.png");
	Texture0 = App->textures->Load("Assets/cositasfondo/R1.png");
	Texture1 = App->textures->Load("Assets/cositasfondo/R1.png");
	Texture2 = App->textures->Load("Assets/cositasfondo/R1.png");
	Texture3 = App->textures->Load("Assets/cositasfondo/R1.png");
	Texture4 = App->textures->Load("Assets/cositasfondo/R1.png");
	Texture5 = App->textures->Load("Assets/cositasfondo/R1.png");
	Texture6 = App->textures->Load("Assets/cositasfondo/R1.png");
	Texture7 = App->textures->Load("Assets/cositasfondo/R1.png");
	Texture8 = App->textures->Load("Assets/cositasfondo/R1.png");
	Texture9 = App->textures->Load("Assets/cositasfondo/R1.png");
	return ret;
}

Update_Status ModuleScore::Update()
{
	//if (App->input->keys[SDL_SCANCODE_SPACE] == Key_State::KEY_DOWN)
	//{
	//	App->fade->FadeToBlack(this, (Module*)App->intro, 30);
	//}
	if (App->player->n < 10)
	{
		score[1][6] = App->player->n;
	}
	else
	{
		App->player->n = App->player->n % 10;
		score[1][6] = App->player->n;
		score[1][5]++;
		if (score[1][5] >= 10)
		{
			score[1][5] = score[1][5] % 10;
			score[1][4]++;
			if (score[1][4] >= 10)
			{
				score[1][4] = score[1][4] % 10;
				score[1][3]++;
			}
		}
	}
	//score[1][16] = App->player->n;
//	int a = score[1][16];
	a = App->player->n;

	if (a > App->gameover->b) {
		App->gameover->b = a;
		score[1][16] = App->gameover->b;
	}
	else {
		score[1][16] = App->gameover->b;
	}

	/*if (App->winning->win == true) {
		score[1][6] = 0;
		score[1][5] = 0;
		score[1][4] = 0;
	}*/

	if (App->intro->intro == true) {
		score[1][6] = 0;
		score[1][5] = 0;
		score[1][4] = 0;
	}

	return Update_Status::UPDATE_CONTINUE;
}


Update_Status ModuleScore::PostUpdate()
{
	
	int whichnumber = 0;

	for (int column = 0; column < 32; column++) {

		for (int row = 0; row < 32; row++) {

			whichnumber = score[column][row];

			switch (whichnumber) {

			case 0:
				number.x = 176;
				number.y = 252;
				App->render->Blit(Texture0, row * 8, column * 8, &number, 0);
				break;

			case 1:
				number.x = 192;
				number.y = 252;
				App->render->Blit(Texture1, row * 8, column * 8, &number, 0);
				break;

			case 2:
				number.x = 208;
				number.y = 252;
				App->render->Blit(Texture2, row * 8, column * 8, &number, 0);
				break;

			case 3:
				number.x = 224;
				number.y = 252;
				App->render->Blit(Texture3, row * 8, column * 8, &number, 0);
				break;

			case 4:
				number.x = 240;
				number.y = 252;
				App->render->Blit(Texture4, row * 8, column * 8, &number, 0);
				break;

			case 5:
				number.x = 256;
				number.y = 252;
				App->render->Blit(Texture5, row * 8, column * 8, &number, 0);
				break;

			case 6:
				number.x = 272;
				number.y = 252;
				App->render->Blit(Texture6, row * 8, column * 8, &number, 0);
				break;

			case 7:
				number.x = 288;
				number.y = 252;
				App->render->Blit(Texture7, row * 8, column * 8, &number, 0);
				break;

			case 8:
				number.x = 304;
				number.y = 252;
				App->render->Blit(Texture8, row * 8, column * 8, &number, 0);
				break;

			case 9:
				number.x = 320;
				number.y = 252;
				App->render->Blit(Texture9, row * 8, column * 8, &number, 0);
				break;

			case 10:
				number.x = 0;
				number.y = 0;
				App->render->Blit(backkTexture, row * 8, column * 8, &number, 0);
				break;

			}
		}

	}

	return Update_Status::UPDATE_CONTINUE;
	
}

bool ModuleScore::CleanUp() {

	App->textures->Unload(backkTexture);

	return true;
}