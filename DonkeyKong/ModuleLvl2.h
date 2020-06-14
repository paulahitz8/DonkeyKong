
#pragma once
#ifndef __MODULE_LVL2_H__
#define __MODULE_LVL2_H__

#include "Module.h"
#include "SDL_Rect.h"
#include "p2Point.h"

struct SDL_Texture;

class ModuleLvl2 : public Module
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
	SDL_Texture* background2Texture = nullptr;
	SDL_Texture* floorTexture = nullptr;
	SDL_Texture* floorCarrotTexture = nullptr;
	SDL_Texture* carrotTexture = nullptr;
	SDL_Texture* ladderTexture = nullptr;
	SDL_Texture* floorLadderTexture = nullptr;
	SDL_Texture* leftPoleTexture = nullptr;
	SDL_Texture* rightPoleTexture = nullptr;
	SDL_Texture* liveTexture = nullptr;

	int i = 1;
	int t = 1;
	int j = 1;


	int lvl2[32][32] = {};

	//Moving ladders
	float ladVel;
	int count;
	SDL_Rect leftLad;
	SDL_Texture* ladTexture = nullptr;
	iPoint leftLadposition;


	Collider* leftLadcollider = nullptr;


public:
	ModuleLvl2(bool startEnabled);
	~ModuleLvl2();
	bool Start() override;
	Update_Status Update() override;
	Update_Status PostUpdate() override;
	bool CleanUp() override;
	bool lvl2score = false;

};

#endif
