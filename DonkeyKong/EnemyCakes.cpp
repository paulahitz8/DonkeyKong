#include "EnemyCakes.h"
#include "Application.h"
#include "ModuleCollisions.h"
#include "ModuleEnemies.h"
#include "ModuleLvl2.h"

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
	if (App->lvl2->change == true)
	{
		speed = -speed;
		App->lvl2->change = false;
	}
	i++;
	Enemies::Update();
}
