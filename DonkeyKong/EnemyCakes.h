#pragma once
#ifndef __ENEMY_CAKES_H__
#define __ENEMY_CAKES_H__

#include "Enemies.h"
#include "Path.h"

class Enemy_Cakes : public Enemies
{
public:

	// Constructor (x y coordinates in the world)
	Enemy_Cakes(int x, int y);

	void Update() override;

private:

	int i = 1;

	Collider* colliderC = nullptr;

	Animation Anim;
};

#endif
