#pragma once
#include "Includes.h"
extern void* MRef[100];

class CSprite
{
public:
	CSprite(std::string FilePath, spriteprop prop);
	~CSprite();
	void Draw(int x, int y, int w, int h);
	void Blink(int initalpha, int finalalpha, int speed);
	void setCrop(int x, int y, int w, int h);

private:
	SDL_Texture* image;
	SDL_Rect dispRect;
	SDL_Rect* cropRect;
	int imgWidth;
	int imgHeight;
	int alpha;
	bool blinking;
	int cur_blinkspeed;
	
};

