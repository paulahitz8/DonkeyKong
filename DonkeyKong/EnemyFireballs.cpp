#include "EnemyFireballs.h"

#include "Application.h"
#include "ModuleCollisions.h"

Enemy_Fireballs::Enemy_Fireballs(int x, int y) : Enemies(x, y)
{
	leftAnim.PushBack({ 125, 97, 15, 12 });
	leftAnim.PushBack({ 148, 97, 16, 12 });
	leftAnim.speed = 0.2f;

	currentAnim = &leftAnim;

	colliderF = App->collision->AddCollider({ position.x, position.y, 15, 12 }, Collider::Type::ENEMY, (Module*)App->enemies);
}

void Enemy_Fireballs::Update()
{
	//path.Update();
	//position = spawnPos + path.GetRelativePosition();

	// Call to the base class. It must be called at the end
	// It will update the collider depending on the position
	Enemies::Update();
}
