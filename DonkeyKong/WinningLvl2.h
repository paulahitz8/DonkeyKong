#pragma once

#ifndef __SCENE_WINNINGLVL2_H__
#define __SCENE_WINNINGLVL2_H__

#include "Module.h"
#include "Animation.h"
#include "p2Point.h"

struct SDL_Texture;
struct pos1 {
	float x;
	float y;
};

class WinningLvl2 : public Module
{
public:
	WinningLvl2(bool startEnabled);
	~WinningLvl2();
	bool Start() override;
	Update_Status Update() override;
	Update_Status PostUpdate() override;
	bool CleanUp();

public:
	SDL_Rect back;
	SDL_Texture* spritesTexture = nullptr;
	SDL_Texture* backgroundTexture = nullptr;
	SDL_Texture* heartTexture = nullptr;
	SDL_Texture* ladyTexture = nullptr;
	SDL_Texture* marioTexture = nullptr;

	SDL_Rect tile;
	SDL_Texture* liveTexture = nullptr;
	SDL_Texture* backgroundtileTexture = nullptr;

	Animation* currentAnimation = nullptr;
	Animation* currentheartAnim = nullptr;
	Animation* currentladyAnim = nullptr;
	Animation* currentmarioAnim = nullptr;

	Animation donkeyidleAnim;
	Animation donkeyupAnim;
	Animation donkeywithoutladyAnim;
	Animation donkeywithladyAnim;
	Animation heartAnim;
	Animation heartAnim1;
	Animation heartAnimvoid;
	Animation rightidleladyAnim;
	Animation ladyvoidAnim;
	Animation leftmarioAnim;
	pos1 donkeypos;


private:
	int i = 1;
	/*int a = 0;*/


};


#endif


