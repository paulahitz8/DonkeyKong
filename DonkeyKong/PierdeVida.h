#pragma once

#ifndef __SCENE_PIERDEVIDA_H__
#define __SCENE_PIERDEVIDA_H__

#include "Module.h"
#include "Animation.h"

struct SDL_Texture;

class PierdeVida : public Module
{

	int j = 1;

	SDL_Rect back;
	SDL_Texture* backTexture = nullptr;

	SDL_Rect tile;
	SDL_Texture* liveTexture = nullptr;
	SDL_Texture* backgroundTexture = nullptr;
	

public:
	PierdeVida(bool startEnabled);
	~PierdeVida();
	bool Start() override;
	Update_Status Update() override;
	Update_Status PostUpdate() override;
	bool CleanUp();

};


#endif


