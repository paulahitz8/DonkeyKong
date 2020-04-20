#pragma once

#ifndef __SCENE_WINNINGSCREEN_H__
#define __SCENE_WINNINGSCREEN_H__

#include "Module.h"
#include "Animation.h"
#include "p2Point.h"

struct SDL_Texture;

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

	Animation* currentAnimation = nullptr;
	Animation donkeyidleAnim, angryAnim1, angryAnim2, downAnim, dizzyAnim;

	iPoint donkeypos;
	//maybe un path?

private:
	int i = 1;
	int a = 0;
};


#endif


