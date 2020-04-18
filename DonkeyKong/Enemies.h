#ifndef __ENEMIES_H__
#define __ENEMIES_H__

#include "p2Point.h"
#include "Animation.h"

struct SDL_Texture;
struct Collider;

class Enemies
{
public:
	// Constructor
	// Saves the spawn position for later movement calculations
	Enemies(int x, int y);

	// Destructor
	virtual ~Enemies();

	// Returns the enemy's collider
	const Collider* GetCollider() const;

	// Called from inhering enemies' Udpate
	// Updates animation and collider position
	virtual void Update();

	// Called from ModuleEnemies' Update
	virtual void Draw();

	// Collision response
	// Triggers an animation and a sound fx
	virtual void OnCollision(Collider* collider);

public:
	// The current position in the world
	iPoint position;

	// The enemy's texture
	SDL_Texture* enemiestexture = nullptr;

	// Sound fx when destroyed
	int destroyedFx = 0;


	// A ptr to the current animation
	Animation* currentAnim = nullptr;

	// The enemy's collider
	Collider* collider = nullptr;

	// Original spawn position. Stored for movement calculations
	iPoint spawnPos;
};

#endif // __ENEMIES_H__