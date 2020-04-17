#pragma once
#ifndef __MODULE_DONKEY_H__
#define __MODULE_DONKEY_H__

#include "Module.h"
#include "SDL_Rect.h"
#include "p2Point.h"

struct SDL_Texture;

class ModuleDonkey : public Module
{
private:

	SDL_Rect donkey;
	iPoint position = { 108, 56 };
	SDL_Texture* donkeytexture = nullptr;

	//Collider* collider = nullptr;

public:

	ModuleDonkey(bool startEnabled);
	~ModuleDonkey();

	bool Start() override;

	Update_Status Update() override;
	Update_Status PostUpdate() override;

	//virtual void OnCollision(Collider* collider);

	bool CleanUp() override;

};

#endif