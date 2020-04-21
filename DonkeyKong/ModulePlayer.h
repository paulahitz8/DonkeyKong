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

	SDL_Texture* playertexture = nullptr;
	

	int speedx = 1;
	int speedy = 1;

	// Sound effects indices
	uint walkingFx = 0;
	uint silenceFx = 0;
	uint deadFx = 0;
	uint bonusFx = 0;

	// The player's collider
	Collider* collider = nullptr;

	// A flag to detect when the player has been destroyed
	bool destroyed = false;
	bool ladderOn = false;
	bool groundOn = false;

	int i = 1;
	int j = 0;

	bool godmode = false;

public:

	iPoint position;

	// Animation
	Animation* currentAnimation = nullptr;
	Animation leftidleAnim;
	Animation rightidleAnim;
	Animation leftAnim;
	Animation rightAnim;
	Animation upladderAnim;
	Animation upladderAnim1;
	Animation upladderAnim2;
	Animation upladderAnim3;
	Animation downladderAnim;
	Animation downladderAnim1;
	Animation downladderAnim2;
	Animation downladderAnim3;
	Animation deadAnim1;
	Animation deadAnim2;
	Animation deadAnim3;
	Animation deadAnim4;
	Animation angelAnim;

	int n = 0;
	
	bool resetVidas = false;
	int livecount = 3;
	int carrotcount = 8;
	Collider* colliderDelete = nullptr;

	int carrotDeletex, carrotDeletey;


	ModulePlayer(bool startEnabled);

	~ModulePlayer();

	bool Start() override;
	Update_Status Update() override;
	Update_Status PostUpdate() override;
	bool CleanUp() override;
	void OnCollision(Collider* c1, Collider* c2) override;

};

#endif