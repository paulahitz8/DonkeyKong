#pragma once
#ifndef __ENEMY_BROWNSHIP_H__
#define __ENEMY_BROWNSHIP_H__

#include "Enemies.h"
#include "Path.h"

class Enemy_Fireballs : public Enemies
{
public:
	// Constructor (x y coordinates in the world)
	// Creates animation and movement data and the collider
	Enemy_Fireballs(int x, int y);

	// The enemy is going to follow the different steps in the path
	// Position will be updated depending on the speed defined at each step
	void Update() override;

private:
	// A set of steps that define the position in the screen
	// And an animation for each step
	Path path;


	Collider* colliderF = nullptr;

	// This enemy has one sprite and one frame
	// We are keeping it an animation for consistency with other enemies
	Animation leftAnim;
};

#endif // __ENEMY_BROWNSHIP_H__

