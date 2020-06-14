#include "EnemyCakes.h"
#include "Application.h"
#include "ModuleCollisions.h"
#include "ModuleEnemies.h"

Enemy_Cakes::Enemy_Cakes(int x, int y) : Enemies(x, y)
{
	Anim.PushBack({ 181, 168, 16, 8 });

	currentAnimcakes = &Anim;

	collider = App->collision->AddCollider({ position.x, position.y, 16, 8 }, Collider::Type::ENEMY, (Module*)App->enemies);

	i = 1;
}

void Enemy_Cakes::Update()
{
	position.x += speed;
	/*if (position.x < 24) {			
		speed = -speed;
	}
	if (position.x > 220) {
		speed = -speed;
	}*/
	if (i % 100 == 0)
	{
		speed = -speed;
	}
	i++;
	Enemies::Update();
}
