#include "EnemyFireballs.h"

#include "Application.h"
#include "ModuleCollisions.h"

Enemy_Fireballs::Enemy_Fireballs(int x, int y) : Enemies(x, y)
{
	leftAnim.PushBack({ 125, 97, 15, 12 });
	leftAnim.PushBack({ 148, 97, 16, 12 });
	leftAnim.speed = 0.2f;

	rightAnim.PushBack({ 117, 217, 15, 12 });
	rightAnim.PushBack({ 93, 217, 16,12 });
	rightAnim.speed = 0.2f;

	currentAnim = &leftAnim;

	collider = App->collision->AddCollider({ position.x, position.y, 15, 12 }, Collider::Type::ENEMY, (Module*)App->enemies);
}

void Enemy_Fireballs::Update()
{
	if (position.x < 24) {
		currentAnim = &rightAnim;
	}
	if (position.x > 220) {
		currentAnim = &leftAnim;
	}
	Enemies::Update();
}
