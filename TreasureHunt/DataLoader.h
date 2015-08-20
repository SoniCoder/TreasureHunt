#pragma once
#include "Includes.h"
#include "Sprite.h"
#include "misc.h"
#include <fstream>
#include "Question.h"
#include "Answer.h"
#include "Text.h"
#include "preSdlSetup.h"

extern void* MRef[100];
CSprite* Sprites[100];

void CreateSprites();
void loadData();
void loadQAPairs();
void getPath(const char*, const char*);

void CreateSprites(){
	MRef[1] = (void*)Sprites;
	Sprites[0] = new CSprite("data/bg/mainmenu.jpg", BLENDABLE);
	Sprites[0]->setCrop(0, 0, 800, 600);
	Sprites[1] = new CSprite("data/sprites/goldcoin.png", BLENDABLE);
}
void loadData(){
	std::cout << "BITS Pilani Production\nLoading Data..\n";
	loadQAPairs();
	CreateSprites();
	system("cls");
}
void loadQAPairs(){
	FILE* file;
	std::string line, line2;
	char buff[100];
	MRef[99] = calloc(100,sizeof(char));
	file = fopen("data/questions/number.txt", "r");
	int txtnum, picnum, i, cor_choice, k;
	fscanf_s(file, "%d", &txtnum);
	fscanf_s(file, "%d", &picnum);
	fclose(file);
	QAPair* qapairs = (QAPair*)calloc(txtnum+picnum,sizeof(QAPair));
	MRef[2] = (void*)qapairs;
	std::ifstream input("data/questions/text/mcq.txt");
	for (i = 0; i < txtnum; i++){
		std::getline(input, line);
		getPath(line.c_str(), "qmcq");
		std::ifstream input2((const char*)MRef[99]);
		std::getline(input2, line2);
		qapairs[i].quesptr = new CQuestion(TEXT, line2.c_str());
		(((int*)MRef[5])[0])++;
		getPath(line.c_str(), "amcq");
		qapairs[i].ansptr = new CAnswer(MCQ, 4);
		std::ifstream input3((const char*)MRef[99]);
		input3 >> cor_choice;
		(qapairs[i].ansptr)->setCorChoice(cor_choice);
		while (!input3.eof()){
			input3 >> line2;
			(qapairs[i].ansptr)->setChoice(line2.c_str());
			(qapairs[i].ansptr)->createAnsTextures();
		}
	}
}

void getPath(const char* name, const char* type){
	if (type == "qmcq"){
		strcpy((char *)MRef[99],(std::string("data/questions/text/mcq/")+std::string(name)).c_str());
	}
	if (type == "amcq"){
		strcpy((char *)MRef[99], (std::string("data/answers/mcq/") + std::string(name)).c_str());
	}
	return;
}