#pragma once
#ifndef __MODULE_LADY_H__
#define __MODULE_LADY_H__

#include "Module.h"
#include "SDL_Rect.h"
#include "p2Point.h"
#include "Animation.h"

struct SDL_Texture;

class ModuleLady : public Module
{
private:

	SDL_Rect lady;
	iPoint ladyPosition = { 120, 26 };
	SDL_Texture* ladytexture = nullptr;
	int i = 1;

public:

	ModuleLady(bool startEnabled);
	~ModuleLady();
	bool Start() override;
	Update_Status Update() override;
	Update_Status PostUpdate() override;
	bool CleanUp() override;

	//Animation
	Animation* currentAnimation = nullptr;
	Animation ladyidleAnim;
	Animation ladyAnim1;
	Animation ladyAnim2;


};

#endif