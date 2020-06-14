#include "EnemyFireballs.h"
#include "Application.h"
#include "ModuleCollisions.h"
#include "ModuleObject.h"

Enemy_Fireballs::Enemy_Fireballs(int x, int y) : Enemies(x, y)
{
	leftAnimhammer.PushBack({ 125, 97, 15, 12 });
	leftAnimhammer.PushBack({ 148, 97, 16, 12 });
	leftAnimhammer.speed = 0.2f;

	rightAnimhammer.PushBack({ 117, 217, 15, 12 });
	rightAnimhammer.PushBack({ 93, 217, 16,12 });
	rightAnimhammer.speed = 0.2f;

	leftAnim.PushBack({ 77, 97, 15, 12 });
	leftAnim.PushBack({ 100, 97, 16, 12 });
	leftAnim.speed = 0.2f;

	rightAnim.PushBack({ 165, 217, 15, 12 });
	rightAnim.PushBack({ 141, 217, 16,12 });
	rightAnim.speed = 0.2f;

	currentAnimfireballs = &leftAnim;

	collider = App->collision->AddCollider({ position.x, position.y, 15, 12 }, Collider::Type::ENEMY, (Module*)App->enemies);
}

void Enemy_Fireballs::Update()
{
	if (App->object->hammerOn == true)
	{
		if (currentAnimfireballs == &leftAnim)
		{
			currentAnimfireballs = &leftAnimhammer;
		}
		else if (currentAnimfireballs == &rightAnim)
		{
			currentAnimfireballs = &rightAnimhammer;
		}
	}
	position.x += speed;
	if (position.y == 196)
	{
		if (position.x < 24) {
			currentAnimfireballs = &rightAnim;
			speed = -speed;
		}
		if (position.x > 220) {
			currentAnimfireballs = &leftAnim;
			speed = -speed;
		}
	}
	if (position.y == 156)
	{
		if (position.x < 32) {
			currentAnimfireballs = &rightAnim;
			speed = -speed;
		}
		if (position.x > 212) {
			currentAnimfireballs = &leftAnim;
			speed = -speed;
		}
	}
	if (position.y == 116)
	{
		if (position.x < 40) {
			currentAnimfireballs = &rightAnim;
			speed = -speed;
		}
		if (position.x > 206) {
			currentAnimfireballs = &leftAnim;
			speed = -speed;
		}
	}

	Enemies::Update();
}
