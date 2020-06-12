#include "EnemyCakes.h"
#include "EnemyFireballs.h"
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
	/*if (position.y == 120)
	{*/
		if (position.x < 24) {
			speed = -speed;
		}
		if (position.x > 220) {
			speed = -speed;
		}
	/*}*/
	/*if (position.y == 156)
	{
		if (position.x < 32) {
			currentAnim = &rightAnim;
		}
		if (position.x > 212) {
			currentAnim = &leftAnim;
		}
	}
	if (position.y == 116)
	{
		if (position.x < 40) {
			currentAnim = &rightAnim;
		}
		if (position.x > 206) {
			currentAnim = &leftAnim;
		}
	}*/
	Enemies::Update();
}
