#include "ModuleEnemies.h"

#include "Application.h"

#include "ModulePlayer.h"
#include "ModuleRender.h"
#include "ModuleTextures.h"
#include "ModuleAudio.h"
#include "ModuleCollisions.h"

#include "Enemies.h"
#include "EnemyFireballs.h"
#include "EnemyFiresparks.h"
#include "EnemyCakes.h"
#include "EnemyJumper.h"

#define SPAWN_MARGIN 50


ModuleEnemies::ModuleEnemies(bool startEnabled) : Module(startEnabled)
{
	deadAnim.PushBack({ 82, 168, 14, 12 });
	deadAnim.PushBack({ 108, 170 , 10 , 8 });
	deadAnim.PushBack({ 82, 168, 14, 12 });
	deadAnim.PushBack({ 108, 170 , 10 , 8 });
	deadAnim.PushBack({ 82, 168, 14, 12 });
	deadAnim.PushBack({ 108, 170 , 10 , 8 });
	deadAnim.PushBack({ 134, 171, 6, 6 });
	deadAnim.PushBack({ 154, 168, 14, 12 });
	deadAnim.speed = 0.11f;

	blankAnim.PushBack({ 0, 0, 20, 20 });

	for (uint i = 0; i < MAX_ENEMIES; ++i)
		enemies[i] = nullptr;

	for (uint i = 0; i < MAX_CAKES; ++i)
		enemiescakes[i] = nullptr;
}

ModuleEnemies::~ModuleEnemies()
{

}

bool ModuleEnemies::Start()
{
	enemiestexture = App->textures->Load("Assets/Enemies/Enemies2.png");
	enemiestexture2 = App->textures->Load("Assets/Enemies/EnemiesSprites.png");
	particlestexture = App->textures->Load("Assets/Lady/RandomSprites.png");
	enemyDestroyedFx = App->audio->LoadFx("Assets/Music/21 SFX (Kill).wav");

	currentAnim2 = &blankAnim;

	return true;
}

Update_Status ModuleEnemies::Update()
{
	HandleEnemiesSpawn();

	for (uint i = 0; i < MAX_ENEMIES; ++i)
	{
		if (enemies[i] != nullptr)
			enemies[i]->Update();
	}

	for (uint i = 0; i < MAX_CAKES; ++i)
	{
		if (enemiescakes[i] != nullptr)
			enemiescakes[i]->Update();
	}

	HandleEnemiesDespawn();

	if (enemyDead == true)
	{
		i = 1;
		currentAnim2 = &deadAnim;
		enemyDead = false;
	}

	if (currentAnim2 == &deadAnim && i % 71 == 0)
	{
		currentAnim2 = &blankAnim;
	}

	i++;
	currentAnim2->Update();

	return Update_Status::UPDATE_CONTINUE;
}

Update_Status ModuleEnemies::PostUpdate()
{
	for (uint i = 0; i < MAX_ENEMIES; ++i)
	{
		if (enemies[i] != nullptr)
			enemies[i]->Draw();
	}

	for (uint i = 0; i < MAX_CAKES; ++i)
	{
		if (enemiescakes[i] != nullptr)
			enemiescakes[i]->Draw();
	}

	if (currentAnim2 != nullptr)
		App->render->Blit(particlestexture, position.x, position.y, &(currentAnim2->GetCurrentFrame()));

	return Update_Status::UPDATE_CONTINUE;
}

// Called before quitting
bool ModuleEnemies::CleanUp()
{
	LOG("Freeing all enemies");

	for (uint i = 0; i < MAX_ENEMIES; ++i)
	{
		if (enemies[i] != nullptr)
		{
			delete enemies[i];
			enemies[i] = nullptr;
		}
	}

	for (uint i = 0; i < MAX_CAKES; ++i)
	{
		if (enemiescakes[i] != nullptr)
		{
			delete enemiescakes[i];
			enemiescakes[i] = nullptr;
		}
	}

	return true;
}

bool ModuleEnemies::AddEnemy(ENEMY_TYPE type, int x, int y)
{
	bool ret = false;

	if (type != ENEMY_TYPE::CAKES)
	{
		for (uint i = 0; i < MAX_ENEMIES; ++i)
		{
			if (spawnQueue[i].type == ENEMY_TYPE::NO_TYPE)
			{
				spawnQueue[i].type = type;
				spawnQueue[i].x = x;
				spawnQueue[i].y = y;
				ret = true;
				break;
			}
		}
	}
	else
	{
		for (uint i = 0; i < MAX_CAKES; ++i)
		{
			if (spawnQueuecakes[i].type == ENEMY_TYPE::NO_TYPE)
			{
				spawnQueuecakes[i].type = type;
				spawnQueuecakes[i].x = x;
				spawnQueuecakes[i].y = y;
				ret = true;
				break;
			}
		}
	}

	return ret;
}

void ModuleEnemies::HandleEnemiesSpawn()
{
	// Iterate all the enemies queue
	for (uint i = 0; i < MAX_ENEMIES; ++i)
	{
		if (spawnQueue[i].type != ENEMY_TYPE::NO_TYPE)
		{
			// Spawn a new enemy if the screen has reached a spawn position
			if (spawnQueue[i].x * SCREEN_SIZE < App->render->camera.x + (App->render->camera.w * SCREEN_SIZE) + SPAWN_MARGIN || spawnQueue[i].y * SCREEN_SIZE < App->render->camera.y + (App->render->camera.h * SCREEN_SIZE) + SPAWN_MARGIN)
			{
				LOG("Spawning enemy at %d", spawnQueue[i].x * SCREEN_SIZE);
				LOG("Spawning enemy at %d", spawnQueue[i].y * SCREEN_SIZE);

				SpawnEnemy(spawnQueue[i]);
				spawnQueue[i].type = ENEMY_TYPE::NO_TYPE; // Removing the newly spawned enemy from the queue
			}
		}
	}
	for (uint i = 0; i < MAX_CAKES; ++i)
	{
		if (spawnQueuecakes[i].type != ENEMY_TYPE::NO_TYPE)
		{
			// Spawn a new enemy if the screen has reached a spawn position
			if (spawnQueuecakes[i].x * SCREEN_SIZE < App->render->camera.x + (App->render->camera.w * SCREEN_SIZE) + SPAWN_MARGIN)
			{
				LOG("Spawning enemy at %d", spawnQueuecakes[i].x * SCREEN_SIZE);

				SpawnEnemy(spawnQueuecakes[i]);
				spawnQueuecakes[i].type = ENEMY_TYPE::NO_TYPE; // Removing the newly spawned enemy from the queue
			}
		}
	}
}

void ModuleEnemies::HandleEnemiesDespawn()
{
	// Iterate existing enemies
	for (uint i = 0; i < MAX_ENEMIES; ++i)
	{
		if (enemies[i] != nullptr)
		{
			// Delete the enemy when it has reached the end of the screen
			if (enemies[i]->position.x * SCREEN_SIZE < (App->render->camera.x) - SPAWN_MARGIN || enemies[i]->position.y > 257)
			{
				LOG("DeSpawning enemy at %d", enemies[i]->position.x * SCREEN_SIZE);
				LOG("DeSpawning enemy at %d", enemies[i]->position.y * SCREEN_SIZE);

				delete enemies[i];
				enemies[i] = nullptr;
			}
		}
	}
	for (uint i = 0; i < MAX_CAKES; ++i)
	{
		if (enemiescakes[i] != nullptr)
		{
			// Delete the enemy when it has reached the end of the screen
			if (enemiescakes[i]->position.x * SCREEN_SIZE < (App->render->camera.x) - SPAWN_MARGIN || (enemiescakes[i]->position.x == 120 && enemiescakes[i]->position.y == 120) || position.x == 240)
			{
				LOG("DeSpawning enemy at %d", enemiescakes[i]->position.x * SCREEN_SIZE);

				delete enemiescakes[i];
				enemiescakes[i] = nullptr;
			}
		}
	}
}

void ModuleEnemies::SpawnEnemy(const EnemySpawnpoint& info)
{
	// Find an empty slot in the enemies array
	if (info.type != ENEMY_TYPE::CAKES)
	{
		for (uint i = 0; i < MAX_ENEMIES; ++i)
		{
			if (enemies[i] == nullptr)
			{
				switch (info.type)
				{
				case ENEMY_TYPE::FIREBALLS:
					enemies[i] = new Enemy_Fireballs(info.x, info.y);
					break;
				case ENEMY_TYPE::FIRESPARKS:
					enemies[i] = new Enemy_Firesparks(info.x, info.y);
					break;
				case ENEMY_TYPE::JUMPER:
					enemies[i] = new Enemy_Jumper(info.x, info.y);
					break;
				}
				enemies[i]->enemiestexture = enemiestexture;
				enemies[i]->enemiestexture2 = enemiestexture2;
				enemies[i]->destroyedFx = enemyDestroyedFx;
				break;
			}
		}
	}
	else
	{
		for (uint i = 0; i < MAX_CAKES; ++i)
		{
			if (enemiescakes[i] == nullptr)
			{
				switch (info.type)
				{
				case ENEMY_TYPE::CAKES:
					enemiescakes[i] = new Enemy_Cakes(info.x, info.y);
					break;
				}
				enemiescakes[i]->enemiestexture2 = enemiestexture2;
				enemiescakes[i]->destroyedFx = enemyDestroyedFx;
				break;
			}
		}
	}
}

void ModuleEnemies::OnCollision(Collider* c1, Collider* c2)
{
	for (uint i = 0; i < MAX_ENEMIES; ++i)
	{
		if (enemies[i] != nullptr && enemies[i]->GetCollider() == c1 && c2->type == Collider::Type::HAMMER)
		{
			enemies[i]->OnCollision(c2); //Notify collision of an enemy

			App->player->n = App->player->n + 8;

			position = enemies[i]->GetPos();

			enemyDead = true;

			App->audio->PlayFx(enemyDestroyedFx);

			delete enemies[i];
			enemies[i] = nullptr;
			break;
		}
	}
	for (uint i = 0; i < MAX_CAKES; ++i)
	{

		if (enemiescakes[i] != nullptr && enemiescakes[i]->GetCollider() == c1 && c2->type == Collider::Type::HAMMER)
		{
			enemiescakes[i]->OnCollision(c2); //Notify collision of an enemy

			App->player->n = App->player->n + 8;

			position = enemiescakes[i]->GetPos();

			enemyDead = true;

			App->audio->PlayFx(enemyDestroyedFx);

			delete enemiescakes[i];
			enemiescakes[i] = nullptr;
			break;
		}
	}
}