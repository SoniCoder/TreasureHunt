#pragma once
#include "Includes.h"

extern void* MRef[100];
class CText
{
public:
	CText(std::string, std::string, SDL_Color, int, int);
	~CText();
	void Render(int, int);
	void Render();
	void changeText(std::string);
	void setCoords(int, int);
private:
	SDL_Texture* texture;
	TTF_Font *font;
	SDL_Surface *surf;
	SDL_Rect Message_rect;
	SDL_Color color;

	int wrap;
	int iW, iH;
};

