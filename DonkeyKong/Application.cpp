#include "Application.h"

#include "Module.h"
#include "ModuleWindow.h"
#include "ModuleInput.h"
#include "ModuleTextures.h"
#include "ModuleAudio.h"
#include "ModuleRender.h"
#include "InitialScreen.h"
#include "IntroScreen.h"
#include "ModuleLvl2.h"
#include "ModuleLvl3.h"
#include "ModuleLvl4.h"
#include "ModuleMusic.h"
#include "ModulePlayer.h"
#include "ModuleDonkey.h"
#include "ModuleFadeToBlack.h"
#include "ModuleEnemies.h"
#include "ModuleLady.h"
#include "ModuleHammer.h"
#include "ModuleScore.h"
#include "ModuleObject.h"
#include "SiguienteNivel.h"
#include "PierdeVida.h"
#include "GameOver.h"
#include "WinningScreen.h"
#include "WinningLvl2.h"
//#include "WinningLvl3.h"

#include "ModuleCollisions.h"

Application::Application()
{
	// The order in which the modules are added is very important.
	// It will define the order in which Pre/Update/Post will be called
	// Render should always be last, as our last action should be updating the screen
	int i = 0;
	modules[i++] =	window =		new ModuleWindow(true);
	modules[i++] =	input =			new ModuleInput(true);
	modules[i++] =	textures =		new ModuleTextures(true);
	modules[i++] =	audio =			new ModuleAudio(true);
	
	modules[i++] =  initial =		new InitialScreen(true);
	modules[i++] =  intro =			new IntroScreen(false);
	modules[i++] =  lvl2 =			new ModuleLvl2(false);
	modules[i++] =  lvl3 =			new ModuleLvl3(false);
	modules[i++] =	lvl4 =			new ModuleLvl4(false);
	modules[i++] =	music =			new ModuleMusic(false);
	modules[i++] =	object =		new ModuleObject(false);
	modules[i++] =	player =		new ModulePlayer(false);
	modules[i++] =	donkey =		new ModuleDonkey(false);
	modules[i++] =  lady =			new ModuleLady(false);
	modules[i++] =  enemies =		new ModuleEnemies(false);
	modules[i++] =  hammer =		new ModuleHammer(false);
	modules[i++] =  score =			new ModuleScore(false);


	modules[i++] =  pierdevida =	new PierdeVida(false);
	modules[i++] =  siguientenivel =new SiguienteNivel(false);
	modules[i++] =  gameover =		new GameOver(false);
	modules[i++] =  winning =		new WinningScreen(false);
	modules[i++] =  winninglvl2 =	new WinningLvl2(false);
	//modules[i++] =  winninglvl3 =	new WinningLvl3(false);
	
	
	
	
	modules[i++] = collision =		new ModuleCollisions(true);
	modules[i++] =	fade	=		new ModuleFadeToBlack(true);


	modules[i++] =	render =		new ModuleRender(true);
}

Application::~Application()
{
	for (int i = 0; i < NUM_MODULES; ++i)
	{
		//Important: when deleting a pointer, set it to nullptr afterwards
		//It allows us for null check in other parts of the code
		delete modules[i];
		modules[i] = nullptr;
	}
}

bool Application::Init()
{
	bool ret = true;

	//player->Disable();
	//lvl4->Disable();
	//donkey->Disable();

	// All modules (active and disabled) will be initialized
	for (int i = 0; i < NUM_MODULES && ret; ++i)
		ret = modules[i]->Init();

	// Only active modules will be 'started'
	for (int i = 0; i < NUM_MODULES && ret; ++i)
		ret = modules[i]->IsEnabled() ? modules[i]->Start() : true;

	return ret;
}

Update_Status Application::Update()
{
	Update_Status ret = Update_Status::UPDATE_CONTINUE;

	for (int i = 0; i < NUM_MODULES && ret == Update_Status::UPDATE_CONTINUE; ++i)
		ret = modules[i]->IsEnabled() ? modules[i]->PreUpdate() : Update_Status::UPDATE_CONTINUE;

	for (int i = 0; i < NUM_MODULES && ret == Update_Status::UPDATE_CONTINUE; ++i)
		ret = modules[i]->IsEnabled() ? modules[i]->Update() : Update_Status::UPDATE_CONTINUE;

	for (int i = 0; i < NUM_MODULES && ret == Update_Status::UPDATE_CONTINUE; ++i)
		ret = modules[i]->IsEnabled() ? modules[i]->PostUpdate() : Update_Status::UPDATE_CONTINUE;

	return ret;
}
 
bool Application::CleanUp()
{
	bool ret = true;

	for (int i = NUM_MODULES - 1; i >= 0 && ret; --i)
		ret = modules[i]->IsEnabled() ? modules[i]->CleanUp() : true;

	return ret;
}
