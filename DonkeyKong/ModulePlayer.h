#pragma once
#ifndef __MODULE_PLAYER_H__
#define __MODULE_PLAYER_H__

#include "Module.h"
#include "SDL_Rect.h"
#include "p2Point.h"
#include "Animation.h"

struct SDL_Texture;

class ModulePlayer : public Module
{
private:
	SDL_Rect player;
	iPoint position = { 46, 232 };
	SDL_Texture* playertexture = nullptr;

public:
	ModulePlayer(bool startEnabled);
	~ModulePlayer();
	bool Start() override;
	Update_Status Update() override;
	Update_Status PostUpdate() override;
	bool CleanUp() override;
	Animation* currentAnimation = nullptr;
	Animation leftidleAnim;
	Animation rightidleAnim;
	Animation leftAnim;
	Animation rightAnim;
	
};

#endif