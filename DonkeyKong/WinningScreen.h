#pragma once

#ifndef __SCENE_WINNINGSCREEN_H__
#define __SCENE_WINNINGSCREEN_H__

#include "Module.h"
#include "Animation.h"
#include "p2Point.h"

struct SDL_Texture;
struct pos {
	float x;
	float y;
};

class WinningScreen : public Module
{
public:
	WinningScreen(bool startEnabled);
	~WinningScreen();
	bool Start() override;
	Update_Status Update() override;
	Update_Status PostUpdate() override;
	bool CleanUp();

public:
	SDL_Rect back;
	SDL_Rect pauline, mario, heart, donkey;
	SDL_Texture* spritesTexture = nullptr;
	SDL_Texture* backgroundTexture = nullptr;
	SDL_Texture* happybackgroundTexture = nullptr;

	SDL_Rect tile;
	SDL_Texture* liveTexture = nullptr;
	SDL_Texture* backgroundtileTexture = nullptr;

	Animation* currentAnimation = nullptr;
	Animation donkeyidleAnim, angryAnim, downAnim, dizzyAnim;
	pos donkeypos;

private:
	int i = 1;
	int a = 0;
	
};


#endif


