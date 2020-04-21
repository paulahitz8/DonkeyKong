#include "ModuleCollisions.h"


#include "Application.h"

#include "ModuleRender.h"
#include "ModuleInput.h"
#include "SDL/include/SDL_Scancode.h"

ModuleCollisions::ModuleCollisions(bool startEnabled) : Module(startEnabled)
{
	for (uint i = 0; i < MAX_COLLIDERS; ++i)
		colliders[i] = nullptr;

	matrix[Collider::Type::PLAYER][Collider::Type::PLAYER] = false;
	matrix[Collider::Type::PLAYER][Collider::Type::ENEMY] = true;
	matrix[Collider::Type::PLAYER][Collider::Type::HAMMER] = false;
	matrix[Collider::Type::PLAYER][Collider::Type::WALL] = true;
	matrix[Collider::Type::PLAYER][Collider::Type::GROUND] = true;
	matrix[Collider::Type::PLAYER][Collider::Type::LADDER] = true;
	matrix[Collider::Type::PLAYER][Collider::Type::CARROT] = true;
	matrix[Collider::Type::PLAYER][Collider::Type::OBJECT] = true;

	matrix[Collider::Type::ENEMY][Collider::Type::PLAYER] = true;
	matrix[Collider::Type::ENEMY][Collider::Type::ENEMY] = false;
	matrix[Collider::Type::ENEMY][Collider::Type::HAMMER] = true;
	matrix[Collider::Type::ENEMY][Collider::Type::WALL] = true;
	matrix[Collider::Type::ENEMY][Collider::Type::GROUND] = true;
	matrix[Collider::Type::ENEMY][Collider::Type::LADDER] = true;
	matrix[Collider::Type::ENEMY][Collider::Type::CARROT] = false;
	matrix[Collider::Type::ENEMY][Collider::Type::OBJECT] = false;

	matrix[Collider::Type::HAMMER][Collider::Type::PLAYER] = false;
	matrix[Collider::Type::HAMMER][Collider::Type::ENEMY] = false;
	matrix[Collider::Type::HAMMER][Collider::Type::HAMMER] = false;
	matrix[Collider::Type::HAMMER][Collider::Type::WALL] = true;
	matrix[Collider::Type::HAMMER][Collider::Type::GROUND] = false;
	matrix[Collider::Type::HAMMER][Collider::Type::LADDER] = false;
	matrix[Collider::Type::HAMMER][Collider::Type::CARROT] = false;
	matrix[Collider::Type::HAMMER][Collider::Type::OBJECT] = false;

	matrix[Collider::Type::WALL][Collider::Type::PLAYER] = true;
	matrix[Collider::Type::WALL][Collider::Type::ENEMY] = true;
	matrix[Collider::Type::WALL][Collider::Type::HAMMER] = true;
	matrix[Collider::Type::WALL][Collider::Type::WALL] = false;
	matrix[Collider::Type::WALL][Collider::Type::GROUND] = false;
	matrix[Collider::Type::WALL][Collider::Type::LADDER] = false;
	matrix[Collider::Type::WALL][Collider::Type::CARROT] = false;
	matrix[Collider::Type::WALL][Collider::Type::OBJECT] = false;

	matrix[Collider::Type::GROUND][Collider::Type::PLAYER] = true;
	matrix[Collider::Type::GROUND][Collider::Type::ENEMY] = true;
	matrix[Collider::Type::GROUND][Collider::Type::HAMMER] = false;
	matrix[Collider::Type::GROUND][Collider::Type::WALL] = false;
	matrix[Collider::Type::GROUND][Collider::Type::GROUND] = false;
	matrix[Collider::Type::GROUND][Collider::Type::LADDER] = false;
	matrix[Collider::Type::GROUND][Collider::Type::CARROT] = false;
	matrix[Collider::Type::GROUND][Collider::Type::OBJECT] = false;

	matrix[Collider::Type::LADDER][Collider::Type::PLAYER] = true;
	matrix[Collider::Type::LADDER][Collider::Type::ENEMY] = true;
	matrix[Collider::Type::LADDER][Collider::Type::HAMMER] = false;
	matrix[Collider::Type::LADDER][Collider::Type::WALL] = false;
	matrix[Collider::Type::LADDER][Collider::Type::GROUND] = false;
	matrix[Collider::Type::LADDER][Collider::Type::LADDER] = false;
	matrix[Collider::Type::LADDER][Collider::Type::CARROT] = false;
	matrix[Collider::Type::LADDER][Collider::Type::OBJECT] = false;

	matrix[Collider::Type::CARROT][Collider::Type::PLAYER] = true;
	matrix[Collider::Type::CARROT][Collider::Type::ENEMY] = false;
	matrix[Collider::Type::CARROT][Collider::Type::HAMMER] = false;
	matrix[Collider::Type::CARROT][Collider::Type::WALL] = false;
	matrix[Collider::Type::CARROT][Collider::Type::GROUND] = false;
	matrix[Collider::Type::CARROT][Collider::Type::LADDER] = false;
	matrix[Collider::Type::CARROT][Collider::Type::CARROT] = false;
	matrix[Collider::Type::CARROT][Collider::Type::OBJECT] = false;

	matrix[Collider::Type::OBJECT][Collider::Type::PLAYER] = true;
	matrix[Collider::Type::OBJECT][Collider::Type::ENEMY] = false;
	matrix[Collider::Type::OBJECT][Collider::Type::HAMMER] = false;
	matrix[Collider::Type::OBJECT][Collider::Type::WALL] = false;
	matrix[Collider::Type::OBJECT][Collider::Type::GROUND] = false;
	matrix[Collider::Type::OBJECT][Collider::Type::LADDER] = false;
	matrix[Collider::Type::OBJECT][Collider::Type::CARROT] = false;
	matrix[Collider::Type::OBJECT][Collider::Type::OBJECT] = false;
}

// Destructor
ModuleCollisions::~ModuleCollisions()
{

}

Update_Status ModuleCollisions::PreUpdate()
{
	// Remove all colliders scheduled for deletion
	for (uint i = 0; i < MAX_COLLIDERS; ++i)
	{
		if (colliders[i] != nullptr && colliders[i]->pendingToDelete == true)
		{
			delete colliders[i];
			colliders[i] = nullptr;
		}
	}

	Collider* c1;
	Collider* c2;

	for (uint i = 0; i < MAX_COLLIDERS; ++i)
	{
		// skip empty colliders
		if (colliders[i] == nullptr)
			continue;

		c1 = colliders[i];

		// avoid checking collisions already checked
		for (uint k = i + 1; k < MAX_COLLIDERS; ++k)
		{
			// skip empty colliders
			if (colliders[k] == nullptr)
				continue;

			c2 = colliders[k];

			if (c1->Intersects(c2->rect))
			{
				if (matrix[c1->type][c2->type] && c1->listener)
					c1->listener->OnCollision(c1, c2);

				if (matrix[c2->type][c1->type] && c2->listener)
					c2->listener->OnCollision(c2, c1);
			}
		}
	}

	return Update_Status::UPDATE_CONTINUE;
}

Update_Status ModuleCollisions::Update()
{
	if (App->input->keys[SDL_SCANCODE_F1] == KEY_DOWN)
		debug = !debug;

	return Update_Status::UPDATE_CONTINUE;
}

Update_Status ModuleCollisions::PostUpdate()
{
	if (debug)
		DebugDraw();

	return Update_Status::UPDATE_CONTINUE;
}

void ModuleCollisions::DebugDraw()
{
	Uint8 alpha = 80;
	for (uint i = 0; i < MAX_COLLIDERS; ++i)
	{
		if (colliders[i] == nullptr)
			continue;

		switch (colliders[i]->type)
		{
		case Collider::Type::NONE: // white
			App->render->DrawQuad(colliders[i]->rect, 255, 255, 255, alpha);
			break;
		case Collider::Type::PLAYER: // green
			App->render->DrawQuad(colliders[i]->rect, 0, 255, 0, alpha);
			break;
		case Collider::Type::ENEMY: // red
			App->render->DrawQuad(colliders[i]->rect, 255, 0, 0, alpha);
			break;
		case Collider::Type::HAMMER: // yellow
			App->render->DrawQuad(colliders[i]->rect, 255, 255, 0, alpha);
			break;
		case Collider::Type::WALL: // blue
			App->render->DrawQuad(colliders[i]->rect, 0, 0, 255, alpha);
			break;
		case Collider::Type::GROUND: // blue??
			App->render->DrawQuad(colliders[i]->rect, 0, 255, 255, alpha);
			break;
		case Collider::Type::LADDER: // purple
			App->render->DrawQuad(colliders[i]->rect, 152, 74, 255, alpha);
			break;   
		case Collider::Type::CARROT: // orange
			App->render->DrawQuad(colliders[i]->rect, 255, 157, 66, alpha);
			break;
		case Collider::Type::OBJECT: // pink
			App->render->DrawQuad(colliders[i]->rect, 255, 97, 208, alpha);
			break;
		}

	}
}

// Called before quitting
bool ModuleCollisions::CleanUp()
{
	LOG("Freeing all colliders");

	for (uint i = 0; i < MAX_COLLIDERS; ++i)
	{
		if (colliders[i] != nullptr)
		{
			delete colliders[i];
			colliders[i] = nullptr;
		}
	}

	return true;
}

Collider* ModuleCollisions::AddCollider(SDL_Rect rect, Collider::Type type, Module* listener)
{
	Collider* ret = nullptr;

	for (uint i = 0; i < MAX_COLLIDERS; ++i)
	{
		if (colliders[i] == nullptr)
		{
			ret = colliders[i] = new Collider(rect, type, listener);
			break;
		}
	}

	return ret;
}

