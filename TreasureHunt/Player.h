#pragma once
#include "Text.h"
#include "Includes.h"
class CPlayer
{
public:
	CPlayer();
	~CPlayer();
	int getGold();
	void setGold(int);
private:
	int gold;
	CText* goldtxt;
	SDL_Color White;
};

