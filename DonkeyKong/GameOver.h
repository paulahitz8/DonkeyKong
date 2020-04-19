#pragma once

#ifndef __SCENE_GAMEOVER_H__
#define __SCENE_GAMEOVER_H__

#include "Module.h"
#include "SDL_Rect.h"
#include "Animation.h"

struct SDL_Texture;

class GameOver : public Module
{

private:

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

	int map[32][32];


public:

	GameOver(bool startEnabled);
	~GameOver();
	bool Start() override;
	Update_Status Update() override;
	Update_Status PostUpdate() override;
	bool CleanUp();
};


#endif


