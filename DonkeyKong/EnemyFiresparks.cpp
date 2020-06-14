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
		
	if (position.x == 109 && position.y == 105)
	{
		up = false;
		down = true;
		right = false;
		left = true;
		currentAnimfiresparks = &leftAnim;
	}
	if (position.x == 102 && position.y == 112)
	{
		up = false;
		down = false;
		right = false;
		left = true;
	}
	if (position.x == 16 && position.y == 112)
	{
		up = false;
		down = false;
		right = true;
		left = false;
		currentAnimfiresparks = &rightAnim;
	}
	if (position.x == 93 && position.y == 112 && currentAnimfiresparks == &rightAnim)
	{
		up = false;
		down = true;
		right = false;
		left = false;
	}
	if (position.x == 93 && position.y == 152)
	{
		up = false;
		down = false;
		right = false;
		left = true;
		currentAnimfiresparks = &leftAnim;
	}
	if (position.x == 79 && position.y == 152)
	{
		up = false;
		down = true;
		right = false;
		left = false;
	}
	if (position.x == 79 && position.y == 192)
	{
		up = false;
		down = false;
		right = false;
		left = true;
	}
	if (position.x == 37 && position.y == 192)
	{
		up = false;
		down = true;
		right = false;
		left = false;
	}
	if (position.x == 37 && position.y == 232)
	{
		up = false;
		down = false;
		right = true;
		left = false;
		currentAnimfiresparks = &rightAnim;
	}
	if (position.x == 93 && position.y == 232)
	{
		up = true;
		down = false;
		right = false;
		left = false;
	}
	if (position.x == 93 && position.y == 192)
	{
		up = false;
		down = false;
		right = true;
		left = false;
	}
	


	if (position.x == 95 && position.y == 120)
	{
		up = false;
		down = false;
		right = false;
		left = true;
		currentAnimfiresparks = &leftAnim;
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
		currentAnimfiresparks = &rightAnim;
	}
	if (position.x == 95 && position.y == 193)
	{
		up = true;
		down = false;
		right = false;
		left = false;
	}



	if (position.x == 215 && position.y == 128)
	{
		up = false;
		down = false;
		right = false;
		left = true;
		currentAnimfiresparks = &leftAnim;
	}
	if (position.x == 198 && position.y == 128)
	{
		up = false;
		down = true;
		right = false;
		left = false;
	}
	if (position.x == 198 && position.y == 160)
	{
		up = false;
		down = false;
		right = false;
		left = true;
	}
	if (position.x == 197 && position.y == 160)
	{
		up = true;
		down = false;
		right = false;
		left = false;
	}
	if (position.x == 197 && position.y == 127)
	{
		up = false;
		down = false;
		right = true;
		left = false;
		currentAnimfiresparks = &rightAnim;
	}
	if (position.x == 221 && position.y == 127)
	{
		up = true;
		down = false;
		right = false; 
		left = false;
	}
	if (position.x == 221 && position.y == 89)
	{
		up = false;
		down = false;
		right = true;
		left = false;
	}
	if (position.x == 222 && position.y == 89)
	{
		up = false;
		down = true;
		right = false;
		left = false;
	}
	if (position.x == 222 && position.y == 128)
	{
		up = false;
		down = false;
		right = false;
		left = true;
		currentAnimfiresparks = &leftAnim;
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
