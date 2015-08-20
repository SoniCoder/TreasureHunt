#include <iostream>
#include "Includes.h"
#include "SDL_Setup.h"
#include "ascmod.h"
#include "Sprite.h"
#include "DataLoader.h"
#include "preSdlSetup.h"
void* MRef[100];

int main(int argc, char* argv[]){
	SDL_Init(SDL_INIT_VIDEO);
	TTF_Init();
	preSdlSetup();
	CSDL_Setup* csdl_setup = new CSDL_Setup();
	loadData();
	csdl_setup->GameLoop();
	SDL_Quit();
	return 0;
}

/*
BITS-Pilani Treasure Hunt
MRef details:
0 : sdlmain
1 : sprites
2 : qapairs
3 : theplayer
4 : text stage
5 : count of various things
    0 : no. of questions
	1 : no. of unhandled text
6 : keyhandler
98: text tests
99: temp const strings
*/