#pragma once

#ifndef __SCENE_WINNINGLVL3_H__
#define __SCENE_WINNINGLVL3_H__

#include "Module.h"
#include "Animation.h"
#include "p2Point.h"

struct SDL_Texture;
struct pos2 {
	float x;
	float y;
};

class WinningLvl3 : public Module
{
public:
	WinningLvl3(bool startEnabled);
	~WinningLvl3();
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
	Animation donkeyidleAnim;
	Animation heartAnim;
	Animation heartAnim1;
	Animation heartAnimvoid;
	pos2 donkeypos;

	bool win = false;
	int p = 1;

private:
	int i = 1;
	int a = 0;

};


#endif


