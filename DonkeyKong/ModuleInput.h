#ifndef __MODULE_INPUT_H__
#define __MODULE_INPUT_H__

#include "Module.h"
#include "Globals.h"
#include "SDL_scancode.h"

#define MAX_KEYS 256
#define MAX_PADS 1

struct _SDL_GameController;
struct _SDL_Haptic;
struct SDL_Cursor;

struct GamePad
{
	//Input data
	bool start, back, guide;
	bool x, y, a, b, l1, r1, l3, r3;
	bool up, down, left, right;
	float l2, r2;
	float l_x, l_y, r_x, r_y, l_dz, r_dz;

	//Controller data
	bool enabled;
	int index;
	_SDL_GameController* controller;
	_SDL_Haptic* haptic;

};

enum Key_State
{
	KEY_IDLE,
	KEY_DOWN,
	KEY_REPEAT,
	KEY_UP
};

class ModuleInput : public Module
{
public:
	// Constructor
	ModuleInput(bool startEnabled);

	// Destructor
	~ModuleInput();

	// Called on application start.
	// Initializes the SDL system for input detection
	bool Init() override;

	// Called at the beginning of the application loop
	// Updates all input data received from SDL
	Update_Status PreUpdate() override;

	// Called on application exit.
	// Uninitializes the SDL system for input detection
	bool CleanUp() override;
	
	void HandleDeviceConnection(int index);
	void HandleDeviceRemoval(int index);
	void UpdateGamepadsInput();
	const char* GetControllerName(int id) const;


	

	int GetCursorState() const;
	int GetMouseX() const;
	int GetMouseY() const;
	bool CheckIfClicked() const;

public:
	// An array to fill in the state of all the keyboard keys
	Key_State keys[MAX_KEYS] = { KEY_IDLE };

	GamePad pads[MAX_PADS];

	SDL_Cursor* cursor;
	int mouseX;
	int mouseY;
	bool clicked;

};

#endif // __ModuleInput_H__