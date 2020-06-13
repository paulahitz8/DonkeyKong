#ifndef __APPLICATION_H__
#define __APPLICATION_H__

#include "Globals.h"

#define NUM_MODULES 23 //actualiza esto

class Module; //este no cuenta en NUM_MODULES :D
class ModuleWindow;
class ModuleInput;
class ModuleTextures;
class ModuleAudio;
class ModuleRender;
class InitialScreen;
class IntroScreen;
class ModuleLvl2;
class ModuleLvl3;
class ModuleLvl4;
class ModulePlayer;
class ModuleDonkey;
class ModuleObject;
class ModuleEnemies;
class ModuleHammer;
class ModuleScore;
class ModuleLady;
class PierdeVida;
class SiguienteNivel;
class GameOver;
class WinningScreen;

class ModuleFadeToBlack;
class ModuleCollisions;


class Application
{

public:

	//Constructor. Creates all necessary modules for the application
	Application();

	//Destructor. Removes all module objects
	~Application();

	//Initializes all modules
	bool Init();

	//Updates all modules (PreUpdate, Update and PostUpdate)
	Update_Status Update();

	//Releases all the application data
	bool CleanUp();

public:
	// An array to store all modules
	Module* modules[NUM_MODULES];

	// All the modules stored individually
	ModuleWindow* window = nullptr;
	ModuleInput* input = nullptr;
	ModuleTextures* textures = nullptr;
	ModuleAudio* audio = nullptr;
	InitialScreen* initial = nullptr;
	IntroScreen* intro = nullptr;
	ModuleLvl2* lvl2 = nullptr;
	ModuleLvl3* lvl3 = nullptr;
	ModuleLvl4* lvl4 = nullptr;
	ModuleObject* object = nullptr;
	ModulePlayer* player = nullptr;
	ModuleDonkey* donkey = nullptr;
	ModuleEnemies* enemies = nullptr;
	ModuleHammer* hammer = nullptr;
	ModuleScore* score = nullptr;
	ModuleLady* lady = nullptr;
	PierdeVida* pierdevida = nullptr;
	SiguienteNivel* siguientenivel = nullptr;
	GameOver* gameover = nullptr;
	WinningScreen* winning = nullptr;

	
	ModuleCollisions* collision = nullptr;
	ModuleFadeToBlack* fade = nullptr;

	ModuleRender* render = nullptr;
};

// Global var made extern for Application ---
extern Application* App;

#endif // __APPLICATION_H__