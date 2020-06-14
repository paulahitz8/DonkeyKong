
#pragma once

#ifndef __SCENE_MUSIC_H__
#define __SCENE_MUSIC_H__

#include "Module.h"
#include "Animation.h"

struct SDL_Texture;

class ModuleMusic : public Module
{




public:
	ModuleMusic(bool startEnabled);
	~ModuleMusic();
	bool Start() override;
	Update_Status Update() override;
	Update_Status PostUpdate() override;
	bool CleanUp();

};


#endif


