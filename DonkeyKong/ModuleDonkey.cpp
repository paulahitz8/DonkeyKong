#include "ModuleDonkey.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleInput.h"
#include "ModuleRender.h"
#include "ModuleAudio.h"
#include "ModuleFadeToBlack.h"
#include "ModuleCollisions.h"

#include "SDL_scancode.h"

ModuleDonkey::ModuleDonkey(bool startEnabled) : Module(startEnabled)
{

	//donkey idle
	donkeyidleAnim.PushBack({ 34,66,40,32 });

	//donkey moving
	donkeyAnim1.PushBack({ 82,66,46,32 });
	donkeyAnim2.PushBack({ 136,66,46,32 });
	donkeyAnim3.PushBack({ 82,66,46,32 });
	donkeyidleAnim.speed = 0.1f;
}

ModuleDonkey::~ModuleDonkey() {

}


bool ModuleDonkey::Start()
{
	LOG("Loading player textures");
	donkeytexture = App->textures->Load("Assets/Donkey/DonkeyKongSprites2.png");
	currentAnimation = &donkeyidleAnim; 
	/*if (playertexture == nullptr) {
		return false;
	}*/

	donkey.x = 34;
	donkey.y = 66;
	donkey.w = 40;
	donkey.h = 32;

	colliderD = App->collision->AddCollider({ donkeyPosition.x, donkeyPosition.y, 40, 32 }, Collider::Type::WALL, this);


	//añadir sonido con la animacion

	return true;
}

Update_Status ModuleDonkey::Update()
{
	
	
	
	
	if (i % 501 == 0)
	{
		currentAnimation = &donkeyAnim1;

	}
	
	/*if (i % 50 == 0){
		currentAnimation = &donkeyidleAnim;
	}*/
	


	if (currentAnimation == &donkeyAnim1) {
		if (i % 20 == 0) {
			currentAnimation = &donkeyAnim2;
		}
	}

	else if (currentAnimation == &donkeyAnim2) {
		if (i % 20 == 0) {
			currentAnimation = &donkeyAnim3;
		}
	}

	else if (currentAnimation == &donkeyAnim3) {
		if (i % 20 == 0) {
			currentAnimation = &donkeyidleAnim;
		}
	}

	currentAnimation->Update();
	//if (currentAnimation->HasFinished() == true) {
	//	currentAnimation->Reset();
	//}
	
	i++;

	return Update_Status::UPDATE_CONTINUE;
}

Update_Status ModuleDonkey::PostUpdate()
{
	SDL_Rect rect = currentAnimation->GetCurrentFrame();
	App->render->Blit(donkeytexture, donkeyPosition.x, donkeyPosition.y, &rect);

	return Update_Status::UPDATE_CONTINUE;
}


bool ModuleDonkey::CleanUp()
{
	return true;
}


