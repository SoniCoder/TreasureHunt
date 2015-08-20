#pragma once

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <iostream>
#include <SDL_ttf.h>
#include <string>

extern void* MRef[100];

enum spriteprop{ BLENDABLE };
enum qtype{ TEXT, PICTURE };
enum ans_type{MCQ};
enum qresponse{NONE, SKIP};
enum aresponse{ ANS_NONE, ANS_WRONG, ANS_CORRECT };

struct SDLmains {
	SDL_Event* event;
	SDL_Renderer* renderer;
};
