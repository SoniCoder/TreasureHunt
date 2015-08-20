#pragma once
#include "Includes.h"
#include "Sprite.h"
#include "Text.h"
#include "ascmod.h"
#include "MainGame.h"
#include "KeyboardHandler.h"
class CSDL_Setup
{
public:
	CSDL_Setup();
	~CSDL_Setup();
	void GameLoop();
	void Begin();
	void End();
private:

	bool quit;
	bool locked;
	bool ingame;

	SDL_Window* window;
	SDLmains sdlmain;
	SDL_Renderer* renderer;
	SDL_Event* mainEvent;

	SDL_Color White;  
	SDL_Rect Message_rect;

	CMainGame* maingame;

	int time;

};

