#pragma once
#ifndef __MODULE_LVL4_H__
#define __MODULE_LVL4_H__

#include "Module.h"
#include "SDL_Rect.h"
#include "p2Point.h"

struct SDL_Texture;

class ModuleLvl4 : public Module
{

private:
	SDL_Rect background;
	iPoint position = { 0, 0 }; //x y
	SDL_Texture* texture = nullptr; 
	

public:
	ModuleLvl4(bool startEnabled);
	~ModuleLvl4();
	bool Start() override;
	Update_Status Update() override;
	Update_Status PostUpdate() override;
	bool CleanUp() override;
};

#endif