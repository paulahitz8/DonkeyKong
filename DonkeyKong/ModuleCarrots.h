#pragma once
#ifndef __MODULE_CARROT_H__
#define __MODULE_DONKEY_H__

#include "Module.h"
#include "SDL_Rect.h"
#include "p2Point.h"

struct SDL_Texture;

class ModuleCarrot : public Module
{
private:

	SDL_Rect carrot;
	iPoint carrotPosition;
	SDL_Texture* carrottexture = nullptr;
	//Collider* colliderC = nullptr;

	int i = 1;


public:

	ModuleCarrot(bool startEnabled);
	~ModuleCarrot();
	bool Start() override;
	Update_Status Update() override;
	Update_Status PostUpdate() override;
	bool CleanUp() override;

};

#endif