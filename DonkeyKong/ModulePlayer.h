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
	iPoint position;
	SDL_Texture* playertexture = nullptr;
	
	int livecount = 3;
	int speedx = 1;
	int speedy = 1;

	// Sound effects indices
	uint walkingFx = 0;

	// The player's collider
	Collider* collider = nullptr;

	// A flag to detect when the player has been destroyed
	bool destroyed = false;
	bool ladderOn = false;
	bool groundOn = false;


	// Animation
	Animation* currentAnimation = nullptr;
	Animation leftidleAnim;
	Animation rightidleAnim;
	Animation leftAnim;
	Animation rightAnim;
	Animation rightwalkAnim;

	uint silenceFx = 0;
	

public:
	// Constructor
	ModulePlayer(bool startEnabled);

	// Destructor
	~ModulePlayer();

	// Called when the module is activated
	// Loads the necessary textures for the player
	bool Start() override;

	// Called at the middle of the application loop
	// Processes new input and handles player movement
	Update_Status Update() override;

	// Called at the end of the application loop
	// Performs the render call of the player sprite
	Update_Status PostUpdate() override;

	//This is NOT in the handout!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	bool CleanUp() override;
	// Collision callback, called when the player intersects with another collider
	void OnCollision(Collider* c1, Collider* c2) override;
	



};

#endif