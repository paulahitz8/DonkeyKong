#pragma once

#ifndef __SCENE_INITIAL_H__
#define __SCENE_INITIAL_H__

#include "Module.h"
#include "Animation.h"
#include "SDL_Rect.h"
#include "p2Point.h"

struct SDL_Texture;


class InitialScreen : public Module
{
private:
	iPoint position = { 0, 0 };

	SDL_Rect letter;


	SDL_Texture* backgroundTexture = nullptr;
	SDL_Texture* aTexture = nullptr;
	SDL_Texture* bTexture = nullptr;
	SDL_Texture* cTexture = nullptr;
	SDL_Texture* dTexture = nullptr;
	SDL_Texture* eTexture = nullptr;
	SDL_Texture* fTexture = nullptr;
	SDL_Texture* gTexture = nullptr;
	SDL_Texture* hTexture = nullptr;
	SDL_Texture* iTexture = nullptr;
	SDL_Texture* jTexture = nullptr;
	SDL_Texture* kTexture = nullptr;
	SDL_Texture* lTexture = nullptr;
	SDL_Texture* mTexture = nullptr;
	SDL_Texture* nTexture = nullptr;
	SDL_Texture* oTexture = nullptr;
	SDL_Texture* pTexture = nullptr;
	SDL_Texture* qTexture = nullptr;
	SDL_Texture* rTexture = nullptr;
	SDL_Texture* sTexture = nullptr;
	SDL_Texture* tTexture = nullptr;
	SDL_Texture* uTexture = nullptr;
	SDL_Texture* vTexture = nullptr;
	SDL_Texture* wTexture = nullptr;
	SDL_Texture* xTexture = nullptr;
	SDL_Texture* yTexture = nullptr;
	SDL_Texture* zTexture = nullptr;



public:
	InitialScreen(bool startEnabled);
	~InitialScreen();
	bool Start() override;
	Update_Status Update() override;
	Update_Status PostUpdate() override;
	bool CleanUp();

	SDL_Rect initialbackground;
	SDL_Texture* initialbackgroundtexture = nullptr;
};


#endif
