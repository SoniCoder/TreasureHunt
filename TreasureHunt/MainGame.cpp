#include "MainGame.h"


CMainGame::CMainGame()
{
	response = NONE;
	qindex = 0;
	getNewQuestion = false;
	player =new CPlayer;
	MRef[3] = (void*)player;
}


CMainGame::~CMainGame()
{
}

void CMainGame::inGame(){
	(((CSprite**)MRef[1])[1])->Draw(650,20,50,50);
	drawLayers();
	askQuestions();
}

void CMainGame::updatePlayerGold(int newgold){
	player->setGold(newgold);
	(((CText**)MRef[4])[0])->changeText(std::to_string(newgold));
}

void CMainGame::askQuestions(){
	if (getNewQuestion){
		qindex++;
		updatePlayerGold((player->getGold()) - 50);
		getNewQuestion = false;
	}
	response = ((((QAPair*)MRef[2])[qindex]).quesptr)->askQuestion(((((QAPair*)MRef[2])[qindex]).ansptr));
	switch (response){
		case NONE: break;
		case SKIP: 
			if (qindex < (((int*)MRef[5])[0])-1){
				getNewQuestion = true;
			}
				break;
	}
}