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
	rightAnim.speed = 0.1f;
}

ModulePlayer::~ModulePlayer() {

}


bool ModulePlayer::Start()
{
	LOG("Loading player textures");
	playertexture = App->textures->Load("Assets/Mario/mariosprites.png");
	walkingFx = App->audio->LoadFx("Assets/Music/15 SFX (Wave).wav");
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

	if (App->input->keys[SDL_SCANCODE_LEFT] == Key_State::KEY_REPEAT)
	{
		position.x -= speed;
		/*if (currentAnimation != &leftAnim)
		{
			leftAnim.Reset();
			currentAnimation = &leftAnim;
		}*/
			currentAnimation = &leftAnim;
			//App->audio->PlayFx(walkingFx);
	}

	if (App->input->keys[SDL_SCANCODE_RIGHT] == Key_State::KEY_REPEAT)
	{
		position.x += speed;
		/*if (currentAnimation != &rightAnim)
		{
			rightAnim.Reset();
			currentAnimation = &rightAnim;
		}*/
			currentAnimation = &rightAnim;
			//App->audio->PlayFx(walkingFx);
			//App->audio->PlayFx(silenceFx);
	}

	if (App->input->keys[SDL_SCANCODE_DOWN] == Key_State::KEY_REPEAT)
	{
		position.y += speed;
	}

	if (App->input->keys[SDL_SCANCODE_UP] == Key_State::KEY_REPEAT)
	{
		position.y -= speed;
	}

	collider->SetPos(position.x, position.y);

	currentAnimation->Update();

	return Update_Status::UPDATE_CONTINUE;
	
}

Update_Status ModulePlayer::PostUpdate()
{

	if (!destroyed)
	{
		SDL_Rect rect = currentAnimation->GetCurrentFrame();
		App->render->Blit(playertexture, position.x, position.y, &rect);
	}

	return Update_Status::UPDATE_CONTINUE;
}

void ModulePlayer::OnCollision(Collider* c1, Collider* c2)
{
	if (c1 == collider && destroyed == false)
	{

		// Aquí necesitamos el sonido de muerte que es el 20. en la lista. lo que pasa es que se carga con loadfx y no con loadmusic y no se como hacerlo.App->audio->PlayFx(explosionFx);

		App->fade->FadeToBlack((Module*)App->lvl4, (Module*)App->intro, 60);

		destroyed = true;
	}
}

bool ModulePlayer::CleanUp()
{
	return true;
}


