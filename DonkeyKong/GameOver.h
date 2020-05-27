#pragma once

#ifndef __SCENE_GAMEOVER_H__
#define __SCENE_GAMEOVER_H__

#include "Module.h"
#include "SDL_Rect.h"
#include "Animation.h"

struct SDL_Texture;

class GameOver : public Module
{

public:

	SDL_Rect backgroundgameover;
	SDL_Texture* backgroundgameoverTexture = nullptr;
	int b = 0;

public:

	GameOver(bool startEnabled);
	~GameOver();
	bool Start() override;
	Update_Status Update() override;
	Update_Status PostUpdate() override;
	bool CleanUp();
	bool gameover = false;
};


#endif


