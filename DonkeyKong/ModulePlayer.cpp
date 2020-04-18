#include "ModulePlayer.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleInput.h"
#include "ModuleRender.h"
#include "ModuleAudio.h"
#include "ModuleFadeToBlack.h"
#include "ModuleCollisions.h"

#include "SDL_scancode.h"

ModulePlayer::ModulePlayer(bool startEnabled) : Module(startEnabled)
{
	position.x = { 46 };
	position.y = { 232 };

	// left idle
	leftidleAnim.PushBack({ 37, 68, 12, 26 });

	//right idle
	rightidleAnim.PushBack({ 207, 194, 12, 26 });

	// left animation
	leftAnim.PushBack({ 59, 78, 30, 16 });
	leftAnim.PushBack({ 101, 68, 13, 26 });
	leftAnim.speed = 0.1f;

	//right animation
	rightAnim.PushBack({ 167, 204, 30, 16 });
	rightAnim.PushBack({ 142, 194, 13, 26 });
	rightAnim.speed = 0.1f; rightAnim.PushBack({ 142, 194, 13, 26 });
}

ModulePlayer::~ModulePlayer() {

}


bool ModulePlayer::Start()
{
	LOG("Loading player textures");
	playertexture = App->textures->Load("Assets/Mario/mariosprites.png");
	walkingFx = App->audio->LoadFx("Assets/Music/15 SFX (Walking).wav");
	currentAnimation = &rightAnim; //mario empieza mirando a la derecha
								   
	 /*if (playertexture == nullptr) {
		return false;
	}*/

	player.x = 56;
	player.y = 2;
	player.w = 12;
	player.h = 16;

	destroyed = false;


	collider = App->collision->AddCollider({ position.x, position.y, 12, 16 }, Collider::Type::PLAYER, this);

	walkingFx = App->audio->LoadFx("Assets/Music/15 SFX (Walking).wav");
	silenceFx = App->audio->LoadFx("Assets/Music/silence.wav");
	


	return true;
}

Update_Status ModulePlayer::Update()
{

	if (!destroyed) {

		if (groundOn == true) {

			if (App->input->keys[SDL_SCANCODE_LEFT] == Key_State::KEY_REPEAT)
			{
				position.x -= speedx;
				//if (currentAnimation != &leftAnim)
				//{
					//leftAnim.Reset();
					//currentAnimation = &leftAnim;
				//}
				currentAnimation = &leftAnim;
				//App->audio->PlayFx(walkingFx);
			}

			if (App->input->keys[SDL_SCANCODE_RIGHT] == Key_State::KEY_REPEAT)
			{
				position.x += speedx;
				//if (currentAnimation != &rightAnim)
				//{
					//rightAnim.Reset();
					//currentAnimation = &rightAnim;
				//}
				currentAnimation = &rightAnim;
				//App->audio->PlayFx(walkingFx);
				//App->audio->PlayFx(silenceFx);
			}

			if (ladderOn == true) {

				if (App->input->keys[SDL_SCANCODE_DOWN] == Key_State::KEY_REPEAT)
				{
					position.y += speedy;

				}

				if (App->input->keys[SDL_SCANCODE_UP] == Key_State::KEY_REPEAT)
				{
					position.y -= speedy;
				}

			}

		}

		else {

			if (ladderOn == true) {
				
				if (App->input->keys[SDL_SCANCODE_DOWN] == Key_State::KEY_REPEAT)
				{
					position.y += speedy;

				}

				if (App->input->keys[SDL_SCANCODE_UP] == Key_State::KEY_REPEAT)
				{
					position.y -= speedy;
				}
			}

		}
		 
		collider->SetPos(position.x, position.y);

		currentAnimation->Update();
	}

	/*if (groundOn == true) {

		if (App->input->keys[SDL_SCANCODE_LEFT] == Key_State::KEY_REPEAT)
		{
			position.x -= speedx;
			//if (currentAnimation != &leftAnim)
			//{
				//leftAnim.Reset();
				//currentAnimation = &leftAnim;
			//}
			currentAnimation = &leftAnim;
			//App->audio->PlayFx(walkingFx);
		}

		if (App->input->keys[SDL_SCANCODE_RIGHT] == Key_State::KEY_REPEAT)
		{
			position.x += speedx;
			//if (currentAnimation != &rightAnim)
			//{
				//rightAnim.Reset();
				//currentAnimation = &rightAnim;
			//}
			currentAnimation = &rightAnim;
			//App->audio->PlayFx(walkingFx);
			//App->audio->PlayFx(silenceFx);
		}

	}

	else {

	}

	if (ladderOn == true) {
		
		if (App->input->keys[SDL_SCANCODE_DOWN] == Key_State::KEY_REPEAT)
		{
			position.y += speedy;

		}

		if (App->input->keys[SDL_SCANCODE_UP] == Key_State::KEY_REPEAT)
		{
			position.y -= speedy;
		}

	}

	collider->SetPos(position.x, position.y);

	currentAnimation->Update();
	}*/

	if (destroyed) {



	}

	return Update_Status::UPDATE_CONTINUE;
	
}

Update_Status ModulePlayer::PostUpdate()
{

	if (!destroyed)
	{
		SDL_Rect rect = currentAnimation->GetCurrentFrame();
		App->render->Blit(playertexture, position.x, position.y, &rect);
	}

	if (destroyed) {

		//animació mort
		SDL_Rect rect = currentAnimation->GetCurrentFrame();
		App->render->Blit(playertexture, position.x, position.y, &rect);

	}

	return Update_Status::UPDATE_CONTINUE;
}

/*void ModulePlayer::OnCollision(Collider* c1, Collider* c2)
{
	if (c1 == collider && destroyed == false)
	{

		// Aquí necesitamos el sonido de muerte que es el 20. en la lista. lo que pasa es que se carga con loadfx y no con loadmusic y no se como hacerlo.App->audio->PlayFx(explosionFx);

		//App->fade->FadeToBlack((Module*)App->lvl4, (Module*)App->intro, 60);

		destroyed = true;
	}

}*/

void ModulePlayer::OnCollision(Collider* c1, Collider* c2)
{

	// LADDER
	/*if (c1 == collider && c2->type == Collider::LADDER) {

		//position.y -= 2; ?
		if (position.x + 4 < c2->rect.x && position.x + 9 > c2->rect.x + 1)
			ladderOn = true; 
	} 
	else { ladderOn = false; }*/
	
	if (c2->type == Collider::Type::LADDER && (position.x > (c2->rect.x - 4) && position.x < (c2->rect.x + 4)))
	{
		if ((position.y + player.h) < (c2->rect.y + 2)) {
			position.y += 1;
		}

		if ((position.y + player.h) > c2->rect.y + 44)
		{
			position.y -= 1;
		}
		
		if ((position.y < (c2->rect.y + 26)) && (position.y > (c2->rect.y - 14)) && (position.x < (c2->rect.x - 2))) {
			position.x += 1;
		}

		if ((position.y < (c2->rect.y + 26)) && (position.y > (c2->rect.y - 14)) && (position.x > (c2->rect.x))) {
			position.x -= 1;
		}

			ladderOn = true;
	}
	else
		ladderOn = false;
		
		
	// GROUND
	/*if (c1 == collider && c2->type == Collider::GROUND){ groundOn = true; } //position.y -= 2;
	else { groundOn = false; }*/

	if (c2->type == Collider::Type::GROUND || c2->type ==Collider::Type::LADDER)
	{
		groundOn = true;
		/*if (ladderOn == true) {

			speedy = 2;

		}
		if (ladderOn == false)
		{
			if (position.y + 16 > c2->rect.y)
			{
				position.y = c2->rect.y - 15;
				speedy = 0;
			}

		}*/
	}
	else
		groundOn = false;




	// ENEMY
	if (c1 == collider && c2->type == Collider::ENEMY && destroyed == false)
	{
		// Aquí necesitamos el sonido de muerte que es el 20. en la lista. lo que pasa es que se carga con loadfx y no con loadmusic y no se como hacerlo.App->audio->PlayFx(explosionFx);

		App->fade->FadeToBlack((Module*)App->lvl4, (Module*)App->intro, 60);

		destroyed = true;
	}

	// WALL
	if (c1 == collider && destroyed == false && c2->type == Collider::WALL) {
		if (position.x < (c2->GetRect().x + c2->GetRect().w)	&&	   position.x > c2->GetRect().x)	{ position.x = (c2->GetRect().x + c2->GetRect().w); }
		if ((position.x + player.w) > c2->GetRect().x	&&  (position.x + player.w) < (c2->GetRect().x + c2->GetRect().w) )  	{ position.x  = (c2->GetRect().x - player.w); }
		if (position.y < (c2->GetRect().y + c2->GetRect().h) && position.y >(c2->GetRect().y)) { position.y = (c2->GetRect().y + c2->GetRect().h); }
	}

} 

bool ModulePlayer::CleanUp()
{
	return true;
}


