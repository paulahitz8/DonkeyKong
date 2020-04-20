#pragma once
#ifndef __MODULE_DONKEY_H__
#define __MODULE_DONKEY_H__

#include "Module.h"
#include "SDL_Rect.h"
#include "p2Point.h"
#include "Animation.h"

struct SDL_Texture;

class ModuleDonkey : public Module
{
private:

	SDL_Rect donkey;
	iPoint donkeyPosition = { 108, 56 };
	SDL_Texture* donkeytexture = nullptr;
	Collider* colliderD = nullptr;

	uint stompFx = 0;

	int i = 1;


public:

	ModuleDonkey(bool startEnabled);
	~ModuleDonkey();
	bool Start() override;
	Update_Status Update() override;
	Update_Status PostUpdate() override;
	bool CleanUp() override;

	

	//Animation
	Animation* currentAnimation = nullptr;
	Animation donkeyidleAnim;
	Animation donkeyAnim1;
	Animation donkeyAnim2;
	Animation donkeyAnim3;

};

#endif