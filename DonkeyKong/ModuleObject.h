#pragma once

#ifndef MODULE_OBJECT_H
#define MODULE_OBJECT_H

#include "Module.h"
#include "SDL_Rect.h"
#include "ModuleTextures.h"
#include "p2Point.h"
#include "Animation.h"


class ModuleObject : public Module
{
public:

	ModuleObject(bool startEnabled);
	~ModuleObject();
	bool Start() override;
	Update_Status Update() override;
	Update_Status PostUpdate() override;
	bool CleanUp() override;
	void OnCollision(Collider* c1, Collider* c2) override;


	bool hammer1exists = true;
	bool hammer2exists = true;
	bool bagexists = true;
	bool hatexists = true;
	bool paraguasexists = true;

	bool hammerOn = false;

	int k = 0;

private:
	Collider* colliderDelete = nullptr;
	iPoint cienpos;
	Collider* hammer1col = nullptr;
	Collider* hammer2col = nullptr;
	Collider* bagcol = nullptr;
	Collider* hatcol = nullptr;
	Collider* paraguascol = nullptr;
	int objetetodeletex;
	int objetetodeletey;
	SDL_Texture* hammer = nullptr;
	SDL_Texture* hat = nullptr;
	SDL_Texture* bag = nullptr;
	SDL_Texture* paraguas = nullptr;
	SDL_Rect hammerrect;
	SDL_Rect hatrect;
	SDL_Rect bagrect;
	SDL_Rect paraguasrect;


	iPoint ochopos;
	SDL_Texture* ochotexture = nullptr;
	SDL_Rect ochorect;


	int objectFx = 0;
	int hammerFx = 0;
	

	SDL_Rect rectnegro;
	SDL_Texture* negro = nullptr;

	iPoint position;

};

#endif