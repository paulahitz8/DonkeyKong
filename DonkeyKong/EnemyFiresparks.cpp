#include "EnemyFiresparks.h"
#include "Application.h"
#include "ModuleCollisions.h"

#include "ModuleEnemies.h"


Enemy_Firesparks::Enemy_Firesparks(int x, int y) : Enemies(x, y)
{
	leftAnim.PushBack({ 33, 47, 13, 15 });
	leftAnim.PushBack({ 56, 46, 15, 16 });
	leftAnim.speed = 0.2f;

	rightAnim.PushBack({ 80, 47, 13, 15 });
	rightAnim.PushBack({ 103, 46, 15, 16 });
	rightAnim.speed = 0.2f;

	currentAnimfiresparks = &leftAnim;

	collider = App->collision->AddCollider({ position.x, position.y, 13, 15 }, Collider::Type::ENEMY, (Module*)App->enemies);
}

void Enemy_Firesparks::Update()
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

	/*if (App->enemies->spawnQueue->y == 105)
	{*/
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
	/*}
	if (App->enemies->spawnQueue->type == ENEMY_TYPE::FIRESPARKS && App->enemies->spawnQueue->y == 120)
	{
		if (position.x > 80)
		{
			position.x--;
		}
	}*/

	/*if (position.y == 196)
	{
		if (position.x < 24) {
			currentAnim = &rightAnim;
		}
		if (position.x > 220) {
			currentAnim = &leftAnim;
		}
	}
	if (position.y == 156)
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
