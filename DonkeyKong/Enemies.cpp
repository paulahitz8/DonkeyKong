#include "Enemies.h"

#include "Application.h"
#include "ModuleCollisions.h"
#include "ModuleRender.h"

Enemies::Enemies(int x, int y) : position(x, y)
{
	spawnPos = position;
}

Enemies::~Enemies()
{
	if (collider != nullptr)
		collider->pendingToDelete = true;
}

const Collider* Enemies::GetCollider() const
{
	return collider;
}

iPoint Enemies::GetPos() const
{
	return position;
}

void Enemies::Update()
{
	if (currentAnimfireballs != nullptr)
		currentAnimfireballs->Update();

	if (currentAnimcakes != nullptr)
		currentAnimcakes->Update();

	if (currentAnimfiresparks != nullptr)
		currentAnimfiresparks->Update();

	if (currentAnimjumper != nullptr)
		currentAnimjumper->Update();

	if (collider != nullptr)
		collider->SetPos(position.x, position.y);

	/*position.x += speed;
	if (position.y == 196)
	{
		if (position.x < 24) {
			speed = -speed;
		}
		if (position.x > 220) {
			speed = -speed;
		}
	}
	if (position.y == 156)
	{
		if (position.x < 32) {
			speed = -speed;
		}
		if (position.x > 212) {
			speed = -speed;
		}
	}
	if (position.y == 116)
	{
		if (position.x < 40) {
			speed = -speed;
		}
		if (position.x > 206) {
			speed = -speed;
		}
	}*/
}

void Enemies::Draw()
{
	if (currentAnimfireballs != nullptr)
	{
		App->render->Blit(enemiestexture, position.x, position.y, &(currentAnimfireballs->GetCurrentFrame()));
	}
	if (currentAnimcakes != nullptr)
	{
		App->render->Blit(enemiestexture2, position.x, position.y, &(currentAnimcakes->GetCurrentFrame()));
	}
	if (currentAnimfiresparks != nullptr)
	{
		App->render->Blit(enemiestexture2, position.x, position.y, &(currentAnimfiresparks->GetCurrentFrame()));
	}
	if (currentAnimjumper != nullptr)
	{
		App->render->Blit(enemiestexture, position.x, position.y, &(currentAnimjumper->GetCurrentFrame()));
	}
}

void Enemies::OnCollision(Collider* collider)
{
	//Current anim == dead anim
}

