#pragma once
#ifndef __ENEMY_FIRESPARKS_H__
#define __ENEMY_FIRESPARKS_H__

#include "Enemies.h"
#include "Path.h"

class Enemy_Firesparks : public Enemies
{
public:

	// Constructor (x y coordinates in the world)
	Enemy_Firesparks(int x, int y);

	void Update() override;

private:

	Collider* colliderFS = nullptr;

	Animation leftAnim;
	Animation rightAnim;
};

#endif 

