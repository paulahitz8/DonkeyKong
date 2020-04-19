#include "ModuleHammer.h"
#include "ModulePlayer.h"
#include "Application.h"
#include "Animation.h"
#include "ModuleTextures.h"
#include "ModuleInput.h"
#include "ModuleRender.h"
#include "ModuleCollisions.h"
#include "ModuleAudio.h"
#include "ModulePlayer.h"
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

	hammerCollider = App->collision->AddCollider({ App->player->position.x + 17 , App->player->position.y - 1, 9,5 }, Collider::Type::HAMMER, this);
	return ret;
}

Update_Status ModuleHammer::Update()
{
	if (App->player->currentAnimation->GetFrame() % 2 == 0) // Hammer down
	{
		if ((App->player->currentAnimation == &App->player->leftAnim) || (App->player->currentAnimation == &App->player->leftidleAnim)) {
			//hammerPosition.x = App->player->position.x + 3;
			//hammerPosition.y = App->player->position.y - 16;
			hammerCollider->SetPos(App->player->position.x + 3, App->player->position.y - 16);
		}
		else if ((App->player->currentAnimation == &App->player->rightAnim) || (App->player->currentAnimation == &App->player->rightidleAnim)) {
			//hammerPosition.x = App->player->position.x + 35;
			//hammerPosition.y = App->player->position.y - 16;
			hammerCollider->SetPos(App->player->position.x + 35, App->player->position.y - 16);
		}
	}

	else // Hammer up
	{
		if ((App->player->currentAnimation == &App->player->leftAnim) || (App->player->currentAnimation == &App->player->leftidleAnim)) {
			//hammerPosition.x = App->player->position.x + 19;
			//hammerPosition.y = App->player->position.y - 1;
			hammerCollider->SetPos(App->player->position.x + 19, App->player->position.y - 1);
		}
		else if ((App->player->currentAnimation == &App->player->rightAnim) || (App->player->currentAnimation == &App->player->rightidleAnim)) {
			//hammerPosition.x = App->player->position.x + 17;
			//hammerPosition.y = App->player->position.y - 1;
			hammerCollider->SetPos(App->player->position.x + 17, App->player->position.y - 1);
		}
	}
	hammerCollider->SetPos(hammerPosition.x + 17, hammerPosition.y - 1);

	return Update_Status::UPDATE_CONTINUE;
}

// Called at the end of the application loop
Update_Status ModuleHammer::PostUpdate()
{

	return Update_Status::UPDATE_CONTINUE;
}

// Collision callback, called when the player intersects with another collider
void ModuleHammer::OnCollision(Collider* c1, Collider* c2)
{

}