#include "ModuleHammer.h"
#include "ModulePlayer.h"

#include "Application.h"
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

	hammerCollider = App->collision->AddCollider({ App->player->position.x, App->player->position.y, 10,10 }, Collider::Type::HAMMER);
	return ret;
}

Update_Status ModuleHammer::Update()
{

	/*if ((App->player->currentAnimation == &App->player->leftAnim) || App->player->currentAnimation.getCurrentFrame() == ) {
		//hammerPosition.x = App->player->position.x - 16;
		//hammerPosition.y = App->player->position.y + 4;
		hammerCollider->SetPos(App->player->position.x - 16, App->player->position.y + 4);
	}
	else if ((App->player->currentAnimation == &App->player->rightAnim)) {
		//hammerPosition.x = App->player->position.x + 18;
		//hammerPosition.y = App->player->position.y + 4;
		hammerCollider->SetPos(App->player->position.x + 18, App->player->position.y + 4);
	}


	if ((App->player->currentAnimation == &App->player->hammerLeftAnim) || (App->player->currentAnimation == &App->player->hammerLeftIdleAnim)) {
		//hammerPosition.x = App->player->position.x + 1;
		//hammerPosition.y = App->player->position.y - 11;
		hammerCollider->SetPos(App->player->position.x + 1, App->player->position.y - 11);
	}
	else if ((App->player->currentAnimation == &App->player->hammerRightAnim) || (App->player->currentAnimation == &App->player->hammerRightIdleAnim)) {
		//hammerPosition.x = App->player->position.x + 1;
		//hammerPosition.y = App->player->position.y - 11;
		hammerCollider->SetPos(App->player->position.x + 1, App->player->position.y - 11);
	}*/
	
	//hammerCollider->SetPos(hammerPosition.x, hammerPosition.y);



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