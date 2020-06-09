#include "ModuleHammer.h"

#include "ModulePlayer.h"
#include "Application.h"
#include "Animation.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModuleCollisions.h"
#include "ModuleLvl4.h"
#include "ModuleEnemies.h"

#include "SDL_scancode.h"

// Constructor
ModuleHammer::ModuleHammer(bool startEnabled) : Module(startEnabled)
{
}


// Destructor
ModuleHammer::~ModuleHammer()
{
}


bool ModuleHammer::Start()
{
	LOG("Loading player textures");

	bool ret = true;

	hammerCollider = App->collision->AddCollider({ App->player->position.x + 18 , App->player->position.y + 1, 10,10 }, Collider::Type::HAMMER, this);
	return ret;
}

Update_Status ModuleHammer::Update()
{
	if ((App->player->currentAnimation == &App->player->upladderAnim) || (App->player->currentAnimation == &App->player->downladderAnim) || (App->player->currentAnimation == &App->player->deadAnim1) || (App->player->currentAnimation == &App->player->deadAnim2) || (App->player->currentAnimation == &App->player->deadAnim3) || (App->player->currentAnimation == &App->player->deadAnim4)) {

		hammerCollider->SetPos(0, 0);

	}

	if (App->player->currentAnimation->GetFrame() % 2 == 0)
	{
		if ((App->player->currentAnimation == &App->player->leftAnim) || (App->player->currentAnimation == &App->player->leftidleAnim)) {
			hammerCollider->SetPos(App->player->position.x + 18, App->player->position.y + 1);
		}
		else if ((App->player->currentAnimation == &App->player->rightAnim) || (App->player->currentAnimation == &App->player->rightidleAnim)) {
			hammerCollider->SetPos(App->player->position.x + 17, App->player->position.y + 1);
		}
	}

	else
	{
	
		if ((App->player->currentAnimation == &App->player->leftAnim) || (App->player->currentAnimation == &App->player->leftidleAnim)) {
			hammerCollider->SetPos(App->player->position.x + 3, App->player->position.y + 16);
		}
		else if ((App->player->currentAnimation == &App->player->rightAnim) || (App->player->currentAnimation == &App->player->rightidleAnim)) {
			hammerCollider->SetPos(App->player->position.x + 35, App->player->position.y + 16);
		}
	}


	return Update_Status::UPDATE_CONTINUE;
}

Update_Status ModuleHammer::PostUpdate()
{

	return Update_Status::UPDATE_CONTINUE;
}

void ModuleHammer::OnCollision(Collider* c1, Collider* c2)
{

}