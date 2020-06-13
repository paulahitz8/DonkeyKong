#include "EnemyJumper.h"
#include "Application.h"
#include "ModuleCollisions.h"

Enemy_Jumper::Enemy_Jumper(int x, int y) : Enemies(x, y)
{
	AnimUp.PushBack({ 82, 70, 16, 15 });

	AnimDown.PushBack({ 106, 70, 16, 15 });

	currentAnimjumper = &AnimUp;

	collider = App->collision->AddCollider({ position.x, position.y, 16, 15 }, Collider::Type::ENEMY, (Module*)App->enemies);
}

void Enemy_Jumper::Update()
{
	position.y += speed;
	if (position.x < 200)
	{
		position.x++;
		if (position.y < 70)
		{
			currentAnimjumper = &AnimUp;
		}
		else
		{
			currentAnimjumper = &AnimDown;
			if (position.y == 74)
			{
				speed = -speed;
			}
		}
	}
	if (position.y == 57)
	{
		speed = -speed;
	}
	if (position.y < 90 && position.y > 74)
	{
		currentAnimjumper = &AnimDown;
		position.y += speed;
	}
	else if (position.y < 120 && position.y > 90)
	{
		currentAnimjumper = &AnimUp;
		position.y += speed;
	}
	else if (position.y < 130 && position.y > 120)
	{
		currentAnimjumper = &AnimDown;
		position.y += speed;
	}
	else if (position.y < 160 && position.y > 130)
	{
		currentAnimjumper = &AnimUp;
		position.y += speed;
	}
	else if (position.y < 170 && position.y > 160)
	{
		currentAnimjumper = &AnimDown;
		position.y += speed;
	}
	else if (position.y < 200 && position.y > 170)
	{
		currentAnimjumper = &AnimUp;
		position.y += speed;
	}
	else if (position.y < 210 && position.y > 200)
	{
		currentAnimjumper = &AnimDown;
		position.y += speed;
	}
	else if (position.y > 210)
	{
		currentAnimjumper = &AnimUp;
		position.y += speed;
	}
	Enemies::Update();
}
