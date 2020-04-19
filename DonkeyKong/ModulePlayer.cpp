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


	// left idle
	leftidleAnim.PushBack({ 0, 0 , 50, 26 });
	leftidleAnim.PushBack({ 0, 37, 50, 26 });
	leftidleAnim.speed = 0.1f;

	//right idle
	rightidleAnim.PushBack({ 0, 64, 50, 26 });
	rightidleAnim.PushBack({ 0, 100, 50, 26 });
	rightidleAnim.speed = 0.1f;

	// left animation
	leftAnim.PushBack({ 203, 1, 50, 26 });
	leftAnim.PushBack({ 203, 36, 50, 26 });
	leftAnim.PushBack({ 203, 63, 50, 26 });
	leftAnim.PushBack({ 203, 94, 50, 26 });
	leftAnim.speed = 0.1f;

	//right animation
	rightAnim.PushBack({ 203, 122, 50, 26 });
	rightAnim.PushBack({ 203, 161, 50, 26 });
	rightAnim.PushBack({ 203, 189, 50, 26 });
	rightAnim.PushBack({ 203, 227, 50, 26 });
	rightAnim.speed = 0.1f;

	//dead animation
	deadAnim1.PushBack({ 149, 41, 50, 26 });
	deadAnim4.PushBack({ 149, 71, 50, 26 });
	deadAnim2.PushBack({ 89, 68, 50, 26 });
	deadAnim3.PushBack({ 89, 101, 50, 26 });

	//dead angel animation
	angelAnim.PushBack({ 59, 67, 30, 26 });
}

ModulePlayer::~ModulePlayer() {

}


bool ModulePlayer::Start()
{
	LOG("Loading player textures");
	playertexture = App->textures->Load("Assets/Mario/mariosprites.png");
	walkingFx = App->audio->LoadFx("Assets/Music/15 SFX (Walking).wav");
	currentAnimation = &rightidleAnim; //mario empieza mirando a la derecha

	position.x = { 43 };
	position.y = { 222 };
								   
	 /*if (playertexture == nullptr) {
		return false;
	}*/

	player.x = 56;
	player.y = 2;
	player.w = 12;
	player.h = 16;


	destroyed = false;


	collider = App->collision->AddCollider({ position.x + 18, position.y + 10, 12, 16 }, Collider::Type::PLAYER, this);

	walkingFx = App->audio->LoadFx("Assets/Music/15 SFX (Walking).wav");
	silenceFx = App->audio->LoadFx("Assets/Music/silence.wav");
	deadFx = App->audio->LoadFx("Assets/Music/20 SFX (Miss).wav");
	


	return true;
}

Update_Status ModulePlayer::Update()
{
	if (destroyed) {

		//animació mort!!!!
		//SDL_Rect rect = currentAnimation->GetCurrentFrame();
		//App->render->Blit(playertexture, position.x, position.y, &rect);


		if (livecount == 0) {

			App->fade->FadeToBlack((Module*)App->lvl4, (Module*)App->gameover, 30);
			destroyed = false;
		}


		else {
			if (currentAnimation != &angelAnim && currentAnimation != &deadAnim2 && currentAnimation != &deadAnim3 && currentAnimation != &deadAnim4)
			{
				currentAnimation = &deadAnim1;
			}
			if (j <= 3)
			{
				if (currentAnimation == &deadAnim1 && i % 7 == 0)
				{
					currentAnimation = &deadAnim2;
				}
				if (currentAnimation == &deadAnim2 && i % 14 == 0)
				{
					currentAnimation = &deadAnim3;
				}
				if (currentAnimation == &deadAnim3 && i % 21 == 0)
				{
					currentAnimation = &deadAnim4;
				}
				if (currentAnimation == &deadAnim4 && i % 28 == 0)
				{
					currentAnimation = &deadAnim1;
					j++;
				}
			}
			else if (currentAnimation == &deadAnim1 && i % 40 == 0)
			{
				currentAnimation = &angelAnim;
			}
			else if(currentAnimation == &angelAnim && i % 200 == 0)
			{
				currentAnimation = &rightidleAnim;
				App->fade->FadeToBlack((Module*)App->lvl4, (Module*)App->pierdevida, 30);
				position.x = { 43 };
				position.y = { 222 };
				destroyed = false;
				i = 0;
				j = 0;
			}
			i++;
		}

	}


	if (!destroyed) {

		if (groundOn == true) {

			if (App->input->keys[SDL_SCANCODE_LEFT] == Key_State::KEY_REPEAT)
			{
				position.x -= speedx;
				currentAnimation = &leftAnim;
				//App->audio->PlayFx(walkingFx);
			}

			if (App->input->keys[SDL_SCANCODE_RIGHT] == Key_State::KEY_REPEAT)
			{
				position.x += speedx;
				currentAnimation = &rightAnim;
				//App->audio->PlayFx(walkingFx);
				//App->audio->PlayFx(silenceFx);
			}

			// If last movement was left, set the current animation back to left idle
			if (App->input->keys[SDL_SCANCODE_LEFT] == Key_State::KEY_UP)
			{
				currentAnimation = &leftidleAnim;
			}
			// If last movement was right, set the current animation back to left idle
			if (App->input->keys[SDL_SCANCODE_RIGHT] == Key_State::KEY_UP)
				currentAnimation = &rightidleAnim;


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
	}

	collider->SetPos(position.x + 18, position.y + 10);

	currentAnimation->Update();

	return Update_Status::UPDATE_CONTINUE;
	
}

Update_Status ModulePlayer::PostUpdate()
{


	SDL_Rect rect = currentAnimation->GetCurrentFrame();
	App->render->Blit(playertexture, position.x, position.y, &rect);



	return Update_Status::UPDATE_CONTINUE;
}

void ModulePlayer::OnCollision(Collider* c1, Collider* c2)
{

	// LADDER
		
	if (c2->type == Collider::Type::LADDER && ((position.x + 18) > (c2->rect.x - 8) && (position.x + 18) < (c2->rect.x)))
	{
		if (((position.y + 10) + player.h) < (c2->rect.y + 3)) {
			position.y += 1;
		}

		if (((position.y + 10) + player.h) > c2->rect.y + 42)
		{
			position.y -= 1;
		}

		if (((position.y + 10) < (c2->rect.y + 26)) && ((position.y + 10) > (c2->rect.y - 13)) && ((position.x + 18) < (c2->rect.x - 6))) {
			position.x += 1;
		}

		if (((position.y + 10) < (c2->rect.y + 26)) && ((position.y + 10) > (c2->rect.y - 13)) && ((position.x + 18) > (c2->rect.x - 4))) {
			position.x -= 1;
		}

		ladderOn = true;
	}
	else
		ladderOn = false;
		
	// GROUND

	if (c2->type == Collider::Type::GROUND || c2->type ==Collider::Type::LADDER)
	{

		groundOn = true;
	}
	else
		groundOn = false;


	// ENEMY
	if (c1 == collider && c2->type == Collider::ENEMY && destroyed == false)
	{
		App->audio->PlayFx(deadFx);
		livecount--;

		destroyed = true;
	}

	// WALL
	if (c1 == collider && destroyed == false && c2->type == Collider::WALL) {
		if ((position.x + 18) < (c2->GetRect().x + c2->GetRect().w) && (position.x + 18) > c2->GetRect().x) { position.x += 2; }
		if (((position.x + 18) + player.w) > c2->GetRect().x && ((position.x + 18) + player.w) < (c2->GetRect().x + c2->GetRect().w)) { position.x -= 2; }
	}

	// CARROT
	if (c2->type == Collider::Type::CARROT)
	{

		carrotcount--;

		if (carrotcount == 0) {

			App->fade->FadeToBlack((Module*)App->lvl4, (Module*)App->winning, 30);
		}

		colliderDelete = c2;

		carrotDeletex = c2->GetRect().x;
		carrotDeletey = c2->GetRect().y;

		groundOn = true;

	}


} 

bool ModulePlayer::CleanUp()
{
	return true;
}


