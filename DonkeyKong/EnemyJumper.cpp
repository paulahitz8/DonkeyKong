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
	position.x += speed;
	/*if (position.y == 120)
	{*/
	if (position.x < 15) {
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
