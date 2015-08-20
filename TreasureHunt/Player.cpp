#include "Player.h"


CPlayer::CPlayer()
{
	gold = 1000;
	White = { 255, 255, 255 };
	((CText**)MRef[4])[(((int*)MRef[5])[1])] = new CText(std::to_string(gold), std::string("OpenSans-Regular.ttf"), White, 24, 200);
	(((CText**)MRef[4])[(((int*)MRef[5])[1])])->setCoords(700, 24);
	(((int*)MRef[5])[1])++;

}


CPlayer::~CPlayer()
{
}

int CPlayer::getGold(){
	return gold;
}
void CPlayer::setGold(int g){
	gold = g;
	return;
}