#pragma once
#include "Includes.h"
#include "Sprite.h"
#include "Player.h"
#include "Text.h"
#include "misc.h"
#include "LayerHandler.h"
class CMainGame
{
public:
	CMainGame();
	~CMainGame();
	void inGame();
	void updatePlayerGold(int);
	void askQuestions();
private:
	CPlayer* player;

	bool getNewQuestion;

	int qindex;

	qresponse response;
};

