#include "InitialScreen.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModuleAudio.h"
#include "ModuleInput.h"
#include "ModuleFadeToBlack.h"

int text[36][36]{	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
					{0,0,0,0,0,0,0,4,0,15,0,14,0,11,0,5,0,25,0,0,0,0,11,0,15,0,14,0,7,0,0,0,0,0,0,0}, //DONKEY KONG
					{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
					{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
					{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
					{0,0,0,0,0,0,0,16,0,18,0,15,0,10,0,5,0,3,0,20,0,0,0,0,15,0,14,0,5,0,0,0,0,0,0,0}, //PROJECT ONE
					{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
					{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
					{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
					{0,0,0,0,0,0,0,0,0,22,0,9,0,4,0,5,0,15,0,7,0,1,0,13,0,5,0,0,0,0,0,0,0,0,0}, //VIDEOGAME
					{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
					{0,0,0,0,0,0,0,0,4,0,5,0,22,0,5,0,12,0,15,0,16,0,13,0,5,0,14,0,20,0,0,0,0,0,0,0}, //DEVELOPMENT
					{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
					{0,0,0,0,0,0,0,0,1,0,14,0,4,0,0,0,0,4,0,5,0,19,0,9,0,7,0,14,0,0,0,0,0,0,0,0}, // AND DESIGN
					{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
					{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
					{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
					{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,0,9,0,20,0,13,0,0,0,0,0,0,0,0,0,0,0,0,0,0}, //CITM
					{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
					{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
					{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
					{0,0,0,0,0,0,13,0,1,0,18,0,3,0,0,0,0,7,0,1,0,18,0,18,0,9,0,7,0,15,0,0,0,0,0,0}, //MARC GARRIGO
					{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
					{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
					{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
					{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
					{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
					{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
					{0,0,0,0,0,0,0,0,16,0,1,0,21,0,12,0,1,0,0,0,0,8,0,9,0,20,0,26,0,0,0,0,0,0,0,0},
					{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
					{0,0,0,0,0,0,0,13,0,1,0,18,0,9,0,1,0,0,0,0,3,0,1,0,12,0,12,0,5,0,0,0,0,0,0,0},
					{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
					{0,0,0,9,0,18,0,5,0,14,0,5,0,0,0,0,8,0,5,0,18,0,14,0,1,0,14,0,4,0,5,0,26,0,0,0},
					{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
					{0, 0,0,0,1,0,4,0,18,0,9,0,1,0,0,0,0,2,0,5,0,12,0,13,0,15,0,14,0,20,0,5,0,0,0,0},
				
};




InitialScreen::InitialScreen(bool startEnabled) : Module(startEnabled)
{

}

InitialScreen::~InitialScreen()
{

}

// Load assets
bool InitialScreen::Start()
{
	LOG("Loading background assets");

	bool ret = true;

	//initialbackground.h = 256;
	//initialbackground.w = 256;

	//initialbackgroundtexture = App->textures->Load("Assets/cositasfondo/fondonegro.png");
	//App->audio->PlayMusic("Assets/Music/introTitle.ogg", 1.0f);
	App->audio->PlayMusic("Assets/Music/00 - Donkey Kong Main Theme (1).wav", 1.0f);

	letter.w = 7;
	letter.h = 7;

	backgroundTexture = App->textures->Load("Assets/cositasfondo/R1.png");
	aTexture = App->textures->Load("Assets/cositasfondo/R1.png");
	bTexture = App->textures->Load("Assets/cositasfondo/R1.png");
	cTexture = App->textures->Load("Assets/cositasfondo/R1.png");
	dTexture = App->textures->Load("Assets/cositasfondo/R1.png");
	eTexture = App->textures->Load("Assets/cositasfondo/R1.png");
	fTexture = App->textures->Load("Assets/cositasfondo/R1.png");
	gTexture = App->textures->Load("Assets/cositasfondo/R1.png");
	hTexture = App->textures->Load("Assets/cositasfondo/R1.png");
	iTexture = App->textures->Load("Assets/cositasfondo/R1.png");
	jTexture = App->textures->Load("Assets/cositasfondo/R1.png");
	kTexture = App->textures->Load("Assets/cositasfondo/R1.png");
	lTexture = App->textures->Load("Assets/cositasfondo/R1.png");
	mTexture = App->textures->Load("Assets/cositasfondo/R1.png");
	nTexture = App->textures->Load("Assets/cositasfondo/R1.png");
	oTexture = App->textures->Load("Assets/cositasfondo/R1.png");
	pTexture = App->textures->Load("Assets/cositasfondo/R1.png");
	qTexture = App->textures->Load("Assets/cositasfondo/R1.png");
	rTexture = App->textures->Load("Assets/cositasfondo/R1.png");
	sTexture = App->textures->Load("Assets/cositasfondo/R1.png");
	tTexture = App->textures->Load("Assets/cositasfondo/R1.png");
	uTexture = App->textures->Load("Assets/cositasfondo/R1.png");
	vTexture = App->textures->Load("Assets/cositasfondo/R1.png");
	wTexture = App->textures->Load("Assets/cositasfondo/R1.png");
	xTexture = App->textures->Load("Assets/cositasfondo/R1.png");
	yTexture = App->textures->Load("Assets/cositasfondo/R1.png");
	zTexture = App->textures->Load("Assets/cositasfondo/R1.png");
	

	return ret;
}

Update_Status InitialScreen::Update()
{
	if (App->input->keys[SDL_SCANCODE_SPACE] == Key_State::KEY_DOWN)
	{
		App->fade->FadeToBlack(this, (Module*)App->intro, 30);
	}

	return Update_Status::UPDATE_CONTINUE;
}

// Update: draw background
Update_Status InitialScreen::PostUpdate()
{
	// Draw everything --------------------------------------

	//App->render->Blit(initialbackgroundtexture, 0, 0, &initialbackground, 0);

	int whichletter = 0;

	for (int column = 0; column < 36; column++) {
		for (int row = 0; row < 36; row++) {

			whichletter = text[column][row];

			switch (whichletter) {

			case 0:
				letter.x = 0;
				letter.y = 0;
				App->render->Blit(backgroundTexture, row * 7, column * 7, &letter, 0);
				break;

			case 1:
				letter.x = 131;
				letter.y = 296;
				App->render->Blit(aTexture, row * 7, column * 7, &letter, 0);
				break;

			case 2:
				letter.x = 147;
				letter.y = 296;
				App->render->Blit(bTexture, row * 7, column * 7, &letter, 0);
				break;

			case 3:
				letter.x = 163;
				letter.y = 296;
				App->render->Blit(cTexture, row * 7, column * 7, &letter, 0);
				break;

			case 4:
				letter.x = 179;
				letter.y = 296;
				App->render->Blit(dTexture, row * 7, column * 7, &letter, 0);
				break;

			case 5:
				letter.x = 196;
				letter.y = 296;
				App->render->Blit(eTexture, row * 7, column * 7, &letter, 0);
				break;

			case 6:
				letter.x = 211;
				letter.y = 296 ;
				App->render->Blit(fTexture, row * 7, column * 7, &letter, 0);
				break;

			case 7:
				letter.x = 227;
				letter.y = 296;
				App->render->Blit(gTexture, row * 7, column * 7, &letter, 0);
				break;

			case 8:
				letter.x = 243;
				letter.y = 296;
				App->render->Blit(hTexture, row * 7, column * 7, &letter, 0);
				break;

			case 9:
				letter.x = 260;
				letter.y = 296;
				App->render->Blit(iTexture, row * 7, column * 7, &letter, 0);
				break;

			case 10:
				letter.x = 275;
				letter.y = 296;
				App->render->Blit(jTexture, row * 7, column * 7, &letter, 0);
				break;

			case 11:
				letter.x = 291;
				letter.y = 296;
				App->render->Blit(kTexture, row * 7, column * 7, &letter, 0);
				break;

			case 12:
				letter.x = 308;
				letter.y = 296;
				App->render->Blit(lTexture, row * 7, column * 7, &letter, 0);
				break;

			case 13:
				letter.x = 323;
				letter.y = 296;
				App->render->Blit(mTexture, row * 7, column * 7, &letter, 0);
				break;

			case 14:
				letter.x = 339;
				letter.y = 296;
				App->render->Blit(nTexture, row * 7, column * 7, &letter, 0);
				break;

			case 15:
				letter.x = 355;
				letter.y = 296;
				App->render->Blit(oTexture, row * 7, column * 7, &letter, 0);
				break;

			case 16:
				letter.x = 135;
				letter.y = 318;
				App->render->Blit(pTexture, row * 7, column * 7, &letter, 0);
				break;

			case 17:
				letter.x = 151;
				letter.y = 318;
				App->render->Blit(qTexture, row * 7, column * 7, &letter, 0);
				break;

			case 18:
				letter.x = 167;
				letter.y = 318;
				App->render->Blit(rTexture, row * 7, column * 7, &letter, 0);
				break;

			case 19:
				letter.x = 183;
				letter.y = 318;
				App->render->Blit(sTexture, row * 7, column * 7, &letter, 0);
				break;

			case 20:
				letter.x = 200;
				letter.y = 318;
				App->render->Blit(tTexture, row * 7, column * 7, &letter, 0);
				break;

			case 21:
				letter.x = 215;
				letter.y = 318;
				App->render->Blit(uTexture, row * 7, column * 7, &letter, 0);
				break;

			case 22:
				letter.x = 231;
				letter.y = 318;
				App->render->Blit(vTexture, row * 7, column * 7, &letter, 0);
				break;

			case 23:
				letter.x = 247;
				letter.y = 318;
				App->render->Blit(wTexture, row * 7, column * 7, &letter, 0);
				break;

			case 24:
				letter.x = 263;
				letter.y = 318;
				App->render->Blit(xTexture, row * 7, column * 7, &letter, 0);
				break;

			case 25:
				letter.x = 280;
				letter.y = 318;
				App->render->Blit(yTexture, row * 7, column * 7, &letter, 0);
				break;

			case 26:
				letter.x = 295;
				letter.y = 318;
				App->render->Blit(zTexture, row * 7, column * 7, &letter, 0);
				break;

			}
		}
	}


	return Update_Status::UPDATE_CONTINUE;
}

bool InitialScreen::CleanUp() {

	App->textures->Unload(initialbackgroundtexture);

	return true;
}