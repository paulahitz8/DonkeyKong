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
public:
	// Constructor
	ModuleHammer(bool startEnabled);

	// Destructor
	~ModuleHammer();

	// Called when the module is activated
	// Loads the necessary textures for the hammer
	bool Start() override;

	// Called at the middle of the application loop
	// Processes new input and handles hammer movement
	Update_Status Update() override;

	// Called at the end of the application loop
	Update_Status PostUpdate() override;

	// Collision callback, called when the player intersects with another collider
	void OnCollision(Collider* c1, Collider* c2) override;

public:


	int temp = 0;

	// A flag to detect when the hammer has been destroyed
	bool hammerExist = true;

	// The player spritesheet loaded into an SDL_Texture
	SDL_Texture* texture = nullptr;

	// The pointer to the current player animation
	// It will be switched depending on the player's movement direction
	Animation* currentAnimation = nullptr;

	// Player's collider
	Collider* hammerCollider = nullptr;




};

#endif