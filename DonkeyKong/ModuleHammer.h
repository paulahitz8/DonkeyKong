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
	bool CleanUp() override;
	void OnCollision(Collider* c1, Collider* c2) override;

public:

	int temp = 0;

	SDL_Texture* texture = nullptr;

	Animation* currentAnimation = nullptr;

	Collider* hammerCollider = nullptr;




};

#endif