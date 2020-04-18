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

void Enemies::Update()
{
	if (currentAnim != nullptr)
		currentAnim->Update();

	if (collider != nullptr)
		collider->SetPos(position.x, position.y);
}

void Enemies::Draw()
{
	if (currentAnim != nullptr)
		App->render->Blit(enemiestexture, position.x, position.y, &(currentAnim->GetCurrentFrame()));
}

void Enemies::OnCollision(Collider* collider)
{
	/*App->particles->AddParticle(App->particles->explosion, position.x, position.y);*/
	/*App->audio->PlayFx(destroyedFx);*/
}
