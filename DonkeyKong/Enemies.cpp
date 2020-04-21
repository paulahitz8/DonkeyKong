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
	if (currentAnim != nullptr)
		currentAnim->Update();

	if (collider != nullptr)
		collider->SetPos(position.x, position.y);

	position.x += speed;
	if (position.x < 24) {
		speed = -speed;
	}
	if (position.x > 220) {
		speed = -speed;
	}
}

void Enemies::Draw()
{
	if (currentAnim != nullptr)
		App->render->Blit(enemiestexture, position.x, position.y, &(currentAnim->GetCurrentFrame()));
}

void Enemies::OnCollision(Collider* collider)
{
	//Current anim == dead anim
}

