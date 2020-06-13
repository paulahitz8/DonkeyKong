#pragma once
#ifndef __ENEMY_JUMPER_H__
#define __ENEMY_JUMPER_H__

#include "Enemies.h"
#include "Path.h"

class Enemy_Jumper : public Enemies
{
public:

	// Constructor (x y coordinates in the world)
	Enemy_Jumper(int x, int y);

	void Update() override;

	int i = 0;

private:

	Collider* colliderJ = nullptr;

	Animation AnimUp;
	Animation AnimDown;
};

#endif
