#pragma once

#ifndef __SCENE_INTRO_H__
#define __SCENE_INTRO_H__

#include "Module.h"
#include "Animation.h"

struct SDL_Texture;

class IntroScreen : public Module
{
public:

	IntroScreen(bool startEnabled);

	~IntroScreen();


	bool Start() override;
	Update_Status Update() override;
	Update_Status PostUpdate() override;
	bool CleanUp();

public:

	SDL_Rect background;
	SDL_Texture* introBackground = nullptr;
};


#endif