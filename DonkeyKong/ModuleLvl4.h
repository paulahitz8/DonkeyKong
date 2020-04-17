#pragma once
#ifndef __MODULE_LVL4_H__
#define __MODULE_LVL4_H__

#include "Module.h"
#include "SDL_Rect.h"
#include "p2Point.h"

struct SDL_Texture;

class ModuleLvl4 : public Module
{

private:
	
	iPoint position = { 0, 0 }; //x y
	 

	//TILEMAP

	SDL_Rect tile;

	SDL_Texture* backgroundTexture = nullptr;
	SDL_Texture* floorTexture = nullptr;
	SDL_Texture* floorCarrotTexture = nullptr;
	SDL_Texture* carrotTexture = nullptr;
	SDL_Texture* ladderTexture = nullptr;
	SDL_Texture* floorLadderTexture = nullptr;
	SDL_Texture* leftPoleTexture = nullptr;
	SDL_Texture* rightPoleTexture = nullptr;
	

	int map[32][32];
	

public:
	ModuleLvl4(bool startEnabled);
	~ModuleLvl4();
	bool Start() override;
	Update_Status Update() override;
	Update_Status PostUpdate() override;
	bool CleanUp() override;


};

#endif