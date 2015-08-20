#include "Sprite.h"


CSprite::CSprite(std::string FilePath, spriteprop prop)
{
	image = IMG_LoadTexture(((SDLmains*)MRef[0])->renderer, FilePath.c_str());
	imgHeight = 0;
	imgWidth = 0;
	SDL_QueryTexture(image, NULL, NULL, &imgWidth, &imgHeight);
	dispRect.x = 0;
	dispRect.y = 0;
	dispRect.h = 0;
	dispRect.w = 0;
	cropRect = NULL;
	alpha = 255;
	blinking = false;
	switch (prop){
	case BLENDABLE:SDL_SetTextureBlendMode(image, SDL_BLENDMODE_BLEND);
	}
}

CSprite::~CSprite()
{
	SDL_DestroyTexture(image);
}

void CSprite::Draw(int x, int y, int w, int h){
	dispRect.x = x;
	dispRect.y = y;
	dispRect.w = w;
	dispRect.h = h;
	SDL_RenderCopy(((SDLmains*)MRef[0])->renderer, image, cropRect, &dispRect);
}

void CSprite::Blink(int initalpha, int finalalpha,int speed)
{ 
	if (!blinking){
		blinking = true;
		cur_blinkspeed = speed;
	}
	if (alpha<initalpha || alpha>finalalpha) {
		if (alpha > finalalpha) alpha = finalalpha;
		else alpha = initalpha;
	}
	if (alpha == initalpha)
	{
		cur_blinkspeed = abs(cur_blinkspeed);
	}
	if (alpha == finalalpha) {
		cur_blinkspeed = -abs(cur_blinkspeed);
	}
	if (alpha >= initalpha&&alpha <= finalalpha){
		alpha = alpha + cur_blinkspeed;
	} 
	SDL_SetTextureAlphaMod(image, alpha);
	Draw(0, 0, 800, 600);
}

void CSprite::setCrop(int x, int y, int w, int h){
	cropRect = (SDL_Rect*)malloc(sizeof(SDL_Rect));
	cropRect->x = x;
	cropRect->y = y;
	cropRect->w = w;
	cropRect->h = h;
}