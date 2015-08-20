#include "SDL_Setup.h"


CSDL_Setup::CSDL_Setup()
{
	quit = false;
	locked = true;
	ingame = false;

	window = SDL_CreateWindow("Treasure Road", 50, 50, 800, 600, SDL_WINDOW_SHOWN);
	sdlmain.renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	sdlmain.event = new SDL_Event();
	MRef[0] = (void*)(&sdlmain);
	time = SDL_GetTicks();
	Message_rect.x = 0;
	Message_rect.y = 50;
	Message_rect.w = 220;
	Message_rect.h = 35;
	White = { 255, 255, 255 };
	CText* press_enter = new CText(std::string("PRESS ENTER"), std::string("OpenSans-Regular.ttf"), White, 24, 200);
	MRef[98] = (void*)press_enter;
	maingame = new CMainGame();
	MRef[6] = (void*)(new CKeyboardHandler());
	((CKeyboardHandler*)MRef[6])->keyboardhandler();
}


CSDL_Setup::~CSDL_Setup()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(sdlmain.renderer);
	delete sdlmain.event;

}

void CSDL_Setup::Begin(){
	SDL_PollEvent(sdlmain.event);
	SDL_RenderClear(sdlmain.renderer);
}

void CSDL_Setup::End(){
	SDL_RenderPresent(sdlmain.renderer);
}

void CSDL_Setup::GameLoop(){
	std::cout << "LOCKED(PRESS TAB TO UNLOCK)" << std::endl;
	while (!quit && sdlmain.event->type != SDL_QUIT){
		if (time + 20 < (int)SDL_GetTicks()){
			if (sdlmain.event->type == SDL_KEYDOWN)
			{
				((CKeyboardHandler*)MRef[6])->setstate(sdlmain.event->key.keysym.scancode, SDL_PRESSED);
			}
			if (sdlmain.event->type == SDL_KEYUP)
			{
				((CKeyboardHandler*)MRef[6])->setstate(sdlmain.event->key.keysym.scancode, SDL_RELEASED);
			}
			Begin();
			if (!ingame)
			{
				(((CSprite**)MRef[1])[0])->Blink(150, 200, 2);
				if (locked)	LockingMech(&locked);
				if (!locked){
					SDL_RenderFillRect(sdlmain.renderer, &Message_rect);
					((CText*)MRef[98])->Render(50, 50);
					if (((CKeyboardHandler*)MRef[6])->wasPressedNowReleased(SDL_SCANCODE_RETURN)){
						((CKeyboardHandler*)MRef[6])->keyboardhandler();
						ingame = true;
						system("cls");
					}
				}
			}
			else{
				maingame->inGame();
			}
			End();
			time = SDL_GetTicks();
		}
	}
}
