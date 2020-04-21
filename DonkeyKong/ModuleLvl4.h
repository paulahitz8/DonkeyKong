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
	
	iPoint position = { 0, 0 };
	iPoint cienpos;
	SDL_Texture* cientexture = nullptr;
	SDL_Rect cienrect;

	//TILEMAP
	SDL_Rect back;
	SDL_Rect tile;

	SDL_Texture* backTexture = nullptr;
	SDL_Texture* backgroundTexture = nullptr;
	SDL_Texture* floorTexture = nullptr;
	SDL_Texture* floorCarrotTexture = nullptr;
	SDL_Texture* carrotTexture = nullptr;
	SDL_Texture* ladderTexture = nullptr;
	SDL_Texture* floorLadderTexture = nullptr;
	SDL_Texture* leftPoleTexture = nullptr;
	SDL_Texture* rightPoleTexture = nullptr;
	SDL_Texture* liveTexture = nullptr;
	
	int i = 1;
	int j = 0;
	int t = 1;

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