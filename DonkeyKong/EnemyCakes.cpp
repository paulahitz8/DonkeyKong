#include "EnemyCakes.h"
#include "Application.h"
#include "ModuleCollisions.h"

Enemy_Cakes::Enemy_Cakes(int x, int y) : Enemies(x, y)
{
	Anim.PushBack({ 181, 168, 16, 8 });

	currentAnimcakes = &Anim;

	collider = App->collision->AddCollider({ position.x, position.y, 16, 8 }, Collider::Type::ENEMY, (Module*)App->enemies);
}

void Enemy_Cakes::Update()
{
	position.x += speed;
	if (position.x < 24) {
		speed = -speed;
	}
	if (position.x > 220) {
		speed = -speed;
	}
	if (position.y == 120)
	{
		if (position.x == 144)
		{
			speed = -speed;
		}
		if (position.x == 96)
		{
			speed = -speed;
		}
	}
	Enemies::Update();
}
