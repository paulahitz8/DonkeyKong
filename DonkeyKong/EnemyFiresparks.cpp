#include "EnemyFiresparks.h"
#include "Application.h"
#include "ModuleCollisions.h"

#include "ModuleEnemies.h"


Enemy_Firesparks::Enemy_Firesparks(int x, int y) : Enemies(x, y)
{
	leftAnim.PushBack({ 33, 47, 15, 16 });
	leftAnim.PushBack({ 56, 46, 15, 16 });
	leftAnim.speed = 0.2f;

	rightAnim.PushBack({ 80, 46, 15, 16 });
	rightAnim.PushBack({ 103, 46, 15, 16 });
	rightAnim.speed = 0.2f;

	currentAnimfiresparks = &leftAnim;

	collider = App->collision->AddCollider({ position.x, position.y, 13, 15 }, Collider::Type::ENEMY, (Module*)App->enemies);
}

void Enemy_Firesparks::Update()
{
	if (App->enemies->spawnQueue->y == 105)
	{
		if (position.y >= 105 && position.y < 112)
		{
			position.y++;
		}
		position.x -= speed;
		if (position.x < 24) {
			currentAnimfiresparks = &rightAnim;
			speed = -speed;
		}
		if (position.x > 220) {
			currentAnimfiresparks = &leftAnim;
			speed = -speed;
		}
	}

	if (position.x == 95 && position.y == 120)
	{
		up = false;
		down = false;
		right = false;
		left = true;
	}
	if (position.x == 77 && position.y == 120)
	{
		up = false;
		down = true;
		right = false;
		left = false;
	}
	if (position.x == 77 && position.y == 193)
	{
		up = false;
		down = false;
		right = true;
		left = false;
	}
	if (position.x == 95 && position.y == 193)
	{
		up = true;
		down = false;
		right = false;
		left = false;
	}

	if (up == true)
	{
		position.y -= speed;
	}
	if (down == true)
	{
		position.y += speed;
	}
	if (right == true)
	{
		position.x += speed;
	}
	if (left == true)
	{
		position.x -= speed;
	}

	Enemies::Update();
}
