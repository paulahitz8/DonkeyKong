#include "ModuleObject.h"
#include "Application.h"
#include "ModulePlayer.h"
#include "ModuleRender.h"
#include "ModuleTextures.h"
#include "ModuleAudio.h"
#include "ModuleCollisions.h"




ModuleObject::ModuleObject(bool startEnabled) : Module(startEnabled)
{
	
}

ModuleObject::~ModuleObject()
{

}

bool ModuleObject::Start()
{
	hammer = App->textures->Load("Assets/objects/RandomSprites.png");
	hat = App->textures->Load("Assets/objects/RandomSprites.png");
	bag = App->textures->Load("Assets/objects/RandomSprites.png");
	paraguas = App->textures->Load("Assets/objects/RandomSprites.png");
	
	hammerrect = { 144, 81, 9, 10 };
	bagrect = { 191, 81, 9, 9 };
	paraguasrect = { 212, 75, 16, 15 };
	hatrect = { 165, 82, 15, 8 };

	


	if (App->player->activelevel == 2) {

		hammer1col = App->collision->AddCollider({ 121, 178, 9, 9 }, Collider::Type::OBJECT, this);
	
		hammer2col = App->collision->AddCollider({ 32, 138, 9, 9 }, Collider::Type::OBJECT, this);
		
		bagcol = App->collision->AddCollider({ 134, 238, 9, 9 }, Collider::Type::OBJECT, this);
	
		paraguascol = App->collision->AddCollider({ 212, 152, 9, 9 }, Collider::Type::OBJECT, this);
	
		hatcol = App->collision->AddCollider({ 77, 159, 9, 9 }, Collider::Type::OBJECT, this);
		
	

	}

	//if (App->player->activelevel == 3) {


	//

	//}

	//if (App->player->activelevel == 4) {


	//}
	//
	return true;
}

Update_Status ModuleObject::Update()
{
	if (App->player->activelevel == 2) {

	

		if (objetetodeletey == 178 && objetetodeletex == 121) {
			cienpos.y = 216;
			cienpos.x = 69;
		
			colliderDelete->pendingToDelete = true;
		}
		else if (objetetodeletey == 138 && objetetodeletex == 32) {
			cienpos.y = 216;
			cienpos.x = 69;

			colliderDelete->pendingToDelete = true;
		}
		else if (objetetodeletey == 238 && objetetodeletex == 134) {
			cienpos.y = 216;
			cienpos.x = 69;

			colliderDelete->pendingToDelete = true;
		}
		else if (objetetodeletey == 152 && objetetodeletex == 212) {
			cienpos.y = 216;
			cienpos.x = 69;

			colliderDelete->pendingToDelete = true;
		}
		else if (objetetodeletey == 159 && objetetodeletex == 77) {
			cienpos.y = 216;
			cienpos.x = 69;

			colliderDelete->pendingToDelete = true;
		}
	}



	return Update_Status::UPDATE_CONTINUE;
}

Update_Status ModuleObject::PostUpdate()
{
	if (App->player->activelevel == 2) {
	
		App->render->Blit(hammer, 121, 178, &hammerrect);
		App->render->Blit(hammer, 32, 138, &hammerrect);
		App->render->Blit(bag, 134, 238, &bagrect);
		App->render->Blit(paraguas, 212, 152, &paraguasrect);
		App->render->Blit(hat, 77, 159, &hatrect);
	
	}

	if (App->player->activelevel == 3) {
	

		App->render->Blit(bag, 104, 34, &bagrect);
		App->render->Blit(paraguas, 104, 34, &paraguasrect);
		App->render->Blit(hat, 104, 34, &hatrect);
	
	}

	if (App->player->activelevel == 4) {
	
		App->render->Blit(hammer, 104, 34, &hammerrect);
		App->render->Blit(hammer, 104, 34, &hammerrect);
		App->render->Blit(bag, 104, 34, &bagrect);
		App->render->Blit(paraguas, 104, 34, &paraguasrect);
		App->render->Blit(hat, 104, 34, &hatrect);
	
	}
	


	return Update_Status::UPDATE_CONTINUE;
}

// Called before quitting
bool ModuleObject::CleanUp()
{

	

	return true;
}





void ModuleObject::OnCollision(Collider* c1, Collider* c2)
{

	if (c1 == hammer1col && c2->type == Collider::Type::PLAYER)
	{
		colliderDelete = c1;
		objetetodeletex = c1->GetRect().x;
		objetetodeletey = c1->GetRect().y;
		
		App->player->n = App->player->n + 8;



		//App->audio->PlayFx(enemyDestroyedFx);

	}
	if (c1 == hammer2col && c2->type == Collider::Type::PLAYER)
	{
		colliderDelete = c1;
		objetetodeletex = c1->GetRect().x;
		objetetodeletey = c1->GetRect().y;

		App->player->n = App->player->n + 8;



		//App->audio->PlayFx(enemyDestroyedFx);

	}
	if (c1 == bagcol && c2->type == Collider::Type::PLAYER)
	{
		colliderDelete = c1;
		objetetodeletex = c1->GetRect().x;
		objetetodeletey = c1->GetRect().y;

		App->player->n = App->player->n + 8;



		//App->audio->PlayFx(enemyDestroyedFx);

	}
	if (c1 == hatcol && c2->type == Collider::Type::PLAYER)
	{
		colliderDelete = c1;
		objetetodeletex = c1->GetRect().x;
		objetetodeletey = c1->GetRect().y;

		App->player->n = App->player->n + 8;



		//App->audio->PlayFx(enemyDestroyedFx);

	}
	if (c1 == paraguascol && c2->type == Collider::Type::PLAYER)
	{
		colliderDelete = c1;
		objetetodeletex = c1->GetRect().x;
		objetetodeletey = c1->GetRect().y;

		App->player->n = App->player->n + 8;



		//App->audio->PlayFx(enemyDestroyedFx);

	}

}