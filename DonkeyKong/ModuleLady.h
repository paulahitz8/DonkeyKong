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
	iPoint helpPosition = { 120, 26 };
	SDL_Texture* ladytexture = nullptr;
	SDL_Texture* helptexture = nullptr;
	int i = 1;
	int j;

public:

	ModuleLady(bool startEnabled);
	~ModuleLady();
	bool Start() override;
	Update_Status Update() override;
	Update_Status PostUpdate() override;
	bool CleanUp() override;

	//Animation
	Animation* currentAnimation = nullptr;
	Animation* currentAnimationhelp = nullptr;
	Animation ladyidleAnim;
	Animation ladyAnim1;
	Animation ladyAnim2;
	Animation ladyAnim3;
	Animation ladyAnim4;
	Animation ladyAnim5;
	Animation leftladyAnim;
	Animation rightladyAnim;
	Animation leftidleladyAnim;
	Animation rightidleladyAnim;
	Animation lefthelpAnim;
	Animation righthelpAnim;
	Animation helpidleAnim;


};

#endif