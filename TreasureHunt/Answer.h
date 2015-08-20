#pragma once
#include "Includes.h"
#include "Text.h"
class CAnswer
{
public:
	CAnswer(ans_type a_type, int n_choice);
	~CAnswer();
	void setChoice(const char *);
	void setCorChoice(int);
	aresponse showNgetAns();
	void createAnsTextures();
private:
	bool textVisible;
	ans_type type;
	int num_choices;
	char choices[4][30]; 
	int choice_ctr;
	int cor_choice;
	CText* anstxtptrs[4]; 
	SDL_Color White;
};

