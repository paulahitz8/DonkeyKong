#pragma once
#ifndef __MODULE_HAMMER_H__
#define __MODULE_HAMMER_H__

#include "Module.h"
#include "SDL_Rect.h"
#include "p2Point.h"
#include "Animation.h"



struct SDL_Texture;
struct Collider;

class ModuleHammer : public Module
{

private: 

	int i = 1;

public:
	// Constructor
	ModuleHammer(bool startEnabled);

	// Destructor
	~ModuleHammer();

	bool Start() override;
	Update_Status Update() override;
	Update_Status PostUpdate() override;
	void OnCollision(Collider* c1, Collider* c2) override;

public:

	int temp = 0;

	// The player spritesheet loaded into an SDL_Texture
	SDL_Texture* texture = nullptr;

	// The pointer to the current player animation
	// It will be switched depending on the player's movement direction
	Animation* currentAnimation = nullptr;

	// Player's collider
	Collider* hammerCollider = nullptr;




};

#endif