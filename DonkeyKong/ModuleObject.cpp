#include "ModuleObject.h"
#include "Application.h"
#include "ModulePlayer.h"
#include "ModuleRender.h"
#include "ModuleTextures.h"
#include "ModuleAudio.h"
#include "ModuleCollisions.h"
#include "ModuleHammer.h"




ModuleObject::ModuleObject(bool startEnabled) : Module(startEnabled)
{

}

ModuleObject::~ModuleObject()
{

}

bool ModuleObject::Start()
{

	objetetodeletey = 0;
	objetetodeletex = 0;
	ochopos.x = 0;
	ochopos.y = 0;
	ochorect = { 155,104,15,7 };
	ochotexture = App->textures->Load("Assets/objects/RandomSprites.png");
	hammer = App->textures->Load("Assets/objects/RandomSprites.png");
	hat = App->textures->Load("Assets/objects/RandomSprites.png");
	bag = App->textures->Load("Assets/objects/RandomSprites.png");
	paraguas = App->textures->Load("Assets/objects/RandomSprites.png");
	negro = App->textures->Load("Assets/cositasfondo/fondonegro.png");



	hammerrect = { 144, 81, 9, 10 };
	bagrect = { 191, 81, 9, 9 };
	paraguasrect = { 212, 75, 16, 15 };
	hatrect = { 165, 82, 15, 8 };

	objectFx = App->audio->LoadFx("Assets/Music/19 SFX (Bonus).wav");
	

	if (App->player->activelevel == 2) {

		hammer1col = App->collision->AddCollider({ 121, 178, 9, 10 }, Collider::Type::OBJECT, this);

		hammer2col = App->collision->AddCollider({ 32, 138, 9, 10 }, Collider::Type::OBJECT, this);

		bagcol = App->collision->AddCollider({ 134, 238, 9, 9 }, Collider::Type::OBJECT, this);

		paraguascol = App->collision->AddCollider({ 212, 152, 16, 15 }, Collider::Type::OBJECT, this);

		hatcol = App->collision->AddCollider({ 77, 159, 15, 8 }, Collider::Type::OBJECT, this);



	}


	if (App->player->activelevel == 3) {
		//falta poner posiciones correctas
		bagcol = App->collision->AddCollider({ 223, 94, 9, 9 }, Collider::Type::OBJECT, this);

		paraguascol = App->collision->AddCollider({ 20, 120, 16, 15 }, Collider::Type::OBJECT, this);

		hatcol = App->collision->AddCollider({ 85, 199, 15, 8 }, Collider::Type::OBJECT, this);

	}

	if (App->player->activelevel == 4) {

		//falta poner posiciones correctas
		hammer1col = App->collision->AddCollider({ 24, 138, 9, 10 }, Collider::Type::OBJECT, this);

		hammer2col = App->collision->AddCollider({ 121, 98, 9, 10 }, Collider::Type::OBJECT, this);

		bagcol = App->collision->AddCollider({ 143, 238, 9, 9 }, Collider::Type::OBJECT, this);

		paraguascol = App->collision->AddCollider({ 44, 72, 16, 15 }, Collider::Type::OBJECT, this);

		hatcol = App->collision->AddCollider({ 213, 199, 15, 8 }, Collider::Type::OBJECT, this);



	}
	return true;
}

Update_Status ModuleObject::Update()
{

	// LEVEL 2

	if (App->player->activelevel == 2) {
		if (objetetodeletey == 178 && objetetodeletex == 121) {
			ochopos.y = 180;
			ochopos.x = 123;
			hammer1exists = false;
			colliderDelete->pendingToDelete = true;
		}
		else if (objetetodeletey == 138 && objetetodeletex == 32) {
			ochopos.y = 140;
			ochopos.x = 34;
			hammer2exists = false;
			colliderDelete->pendingToDelete = true;
		}
		else if (objetetodeletey == 238 && objetetodeletex == 134) {
			ochopos.y = 238;
			ochopos.x = 135;
			bagexists = false;
			colliderDelete->pendingToDelete = true;
		}
		else if (objetetodeletey == 152 && objetetodeletex == 212) {
			ochopos.y = 154;
			ochopos.x = 214;
			paraguasexists = false;
			colliderDelete->pendingToDelete = true;
		}
		else if (objetetodeletey == 159 && objetetodeletex == 77) {
			ochopos.y = 159;
			ochopos.x = 77;
			hatexists = false;
			colliderDelete->pendingToDelete = true;
		}
	}

	// LEVEL 3

	if (App->player->activelevel == 3) {

		if (objetetodeletey == 94 && objetetodeletex == 223) {
			ochopos.y = 94;
			ochopos.x = 221;
			bagexists = false;
			colliderDelete->pendingToDelete = true;
		}
		else if (objetetodeletey == 120 && objetetodeletex == 20) {
			ochopos.y = 120;
			ochopos.x = 18;
			paraguasexists = false;
			colliderDelete->pendingToDelete = true;
		}
		else if (objetetodeletey == 199 && objetetodeletex == 85) {
			ochopos.y = 199;
			ochopos.x = 83;
			hatexists = false;
			colliderDelete->pendingToDelete = true;
		}

	}

	// LEVEL 4
	if (App->player->activelevel == 4) {
		if (objetetodeletey == 138 && objetetodeletex == 24) {
			ochopos.y = 138;
			ochopos.x = 22;
			hammer1exists = false;
			colliderDelete->pendingToDelete = true;
		}
		else if (objetetodeletey == 98 && objetetodeletex == 121) {
			ochopos.y = 98;
			ochopos.x = 119;
			hammer2exists = false;
			colliderDelete->pendingToDelete = true;
		}
		else if (objetetodeletey == 238 && objetetodeletex == 143) {
			ochopos.y = 238;
			ochopos.x = 141;
			bagexists = false;
			colliderDelete->pendingToDelete = true;
		}
		else if (objetetodeletey == 72 && objetetodeletex == 44) {
			ochopos.y = 72;
			ochopos.x = 42;
			paraguasexists = false;
			colliderDelete->pendingToDelete = true;
		}
		else if (objetetodeletey == 199 && objetetodeletex == 213) {
			ochopos.y = 199;
			ochopos.x = 211;
			hatexists = false;
			colliderDelete->pendingToDelete = true;
		}
	}

	return Update_Status::UPDATE_CONTINUE;
}

Update_Status ModuleObject::PostUpdate()
{
	if (App->player->activelevel == 2) {

		if (hammer1exists == true) {
			App->render->Blit(hammer, 121, 178, &hammerrect);
		}
		if (hammer2exists == true) {

			App->render->Blit(hammer, 32, 138, &hammerrect);
		}
		if (bagexists == true) {

			App->render->Blit(bag, 134, 238, &bagrect);
		}if (paraguasexists == true) {

			App->render->Blit(paraguas, 212, 152, &paraguasrect);
		}if (hatexists == true) {

			App->render->Blit(hat, 77, 159, &hatrect);
		}


		if (ochopos.x != 0 && ochopos.y != 0) {

			App->render->Blit(ochotexture, ochopos.x, ochopos.y, &ochorect);

		}

	}

	if (App->player->activelevel == 3) {


		if (bagexists == true) {

			App->render->Blit(bag, 223, 94, &bagrect);
		}if (paraguasexists == true) {

			App->render->Blit(paraguas, 20, 120, &paraguasrect);
		}if (hatexists == true) {

			App->render->Blit(hat, 85, 199, &hatrect);
		}
		if (ochopos.x != 0 && ochopos.y != 0) {

			App->render->Blit(ochotexture, ochopos.x, ochopos.y, &ochorect);

		}

	}

	if (App->player->activelevel == 4) {
		if (hammer1exists == true) {
			App->render->Blit(hammer, 24, 138, &hammerrect);
		}
		if (hammer2exists == true) {

			App->render->Blit(hammer, 121, 98, &hammerrect);
		}

		if (bagexists == true) {
			App->render->Blit(bag, 143, 238, &bagrect);

		}
		if (paraguasexists == true) {

			App->render->Blit(paraguas, 44, 72, &paraguasrect);
		}if (hatexists == true) {
			App->render->Blit(hat, 213, 199, &hatrect);
		}

		if (ochopos.x != 0 && ochopos.y != 0) {

			App->render->Blit(ochotexture, ochopos.x, ochopos.y, &ochorect);

		}
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

		hammerOn = true;
		App->hammer->Enable();

		App->audio->PlayFx(objectFx);


	}
	if (c1 == hammer2col && c2->type == Collider::Type::PLAYER)
	{
		colliderDelete = c1;
		objetetodeletex = c1->GetRect().x;
		objetetodeletey = c1->GetRect().y;

		App->player->n = App->player->n + 8;
		hammerOn = true;
		App->hammer->Enable();


		App->audio->PlayFx(objectFx);
	
	}
	if (c1 == bagcol && c2->type == Collider::Type::PLAYER)
	{
		colliderDelete = c1;
		objetetodeletex = c1->GetRect().x;
		objetetodeletey = c1->GetRect().y;

		App->player->n = App->player->n + 8;



		App->audio->PlayFx(objectFx);

	}
	if (c1 == hatcol && c2->type == Collider::Type::PLAYER)
	{
		colliderDelete = c1;
		objetetodeletex = c1->GetRect().x;
		objetetodeletey = c1->GetRect().y;

		App->player->n = App->player->n + 8;



		App->audio->PlayFx(objectFx);

	}
	if (c1 == paraguascol && c2->type == Collider::Type::PLAYER)
	{
		colliderDelete = c1;
		objetetodeletex = c1->GetRect().x;
		objetetodeletey = c1->GetRect().y;

		App->player->n = App->player->n + 8;



		App->audio->PlayFx(objectFx);

	}

}