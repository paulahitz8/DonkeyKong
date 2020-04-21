#pragma once

#ifndef __MODULE_ENEMIES_H__
#define __MODULE_ENEMIES_H__

#include "Module.h"
#include "SDL_Rect.h"
#include "p2Point.h"
#include "Animation.h"

#define MAX_ENEMIES 5

enum class ENEMY_TYPE
{
	NO_TYPE,
	FIREBALLS
};

struct EnemySpawnpoint
{
	ENEMY_TYPE type = ENEMY_TYPE::NO_TYPE;
	int x, y;
};

class Enemies;
struct SDL_Texture;

class ModuleEnemies : public Module
{
public:

	ModuleEnemies(bool startEnabled);

	~ModuleEnemies();

	bool Start() override;

	Update_Status Update() override;

	Update_Status PostUpdate() override;

	bool CleanUp() override;

	void OnCollision(Collider* c1, Collider* c2) override;

	// Add an enemy into the queue to be spawned later
	bool AddEnemy(ENEMY_TYPE type, int x, int y);

	// Iterates the queue and checks for camera position
	void HandleEnemiesSpawn();

	// Destroys any enemies that have moved outside the camera limits
	void HandleEnemiesDespawn();

	// Spawns a new enemy using the data from the queue
	void SpawnEnemy(const EnemySpawnpoint& info);

private: //?

	// A queue with all spawn points information
	EnemySpawnpoint spawnQueue[MAX_ENEMIES];

	Enemies* enemies[MAX_ENEMIES] = { nullptr };

	SDL_Texture* enemiestexture = nullptr;

	int enemyDestroyedFx = 0;
};

#endif // __MODULE_ENEMIES_H__