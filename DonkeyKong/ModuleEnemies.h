#pragma once
#ifndef __MODULE_ENEMIES_H__
#define __MODULE_ENEMIES_H__

#include "Module.h"
#include "SDL_Rect.h"
#include "p2Point.h"

struct SDL_Texture;

class ModuleEnemies : public Module
{
private:

	SDL_Rect fireballs;
	iPoint position = { 130, 154 };
	SDL_Texture* fireballstexture = nullptr;

	//Collider* collider = nullptr;

public:

	ModuleEnemies(bool startEnabled);
	~ModuleEnemies();

	bool Start() override;

	Update_Status Update() override;
	Update_Status PostUpdate() override;

	//virtual void OnCollision(Collider* collider);

	bool CleanUp() override;

};

#endif
