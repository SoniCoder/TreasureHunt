#include "Answer.h"


CAnswer::CAnswer(ans_type a_type, int n_choice)
{
	choice_ctr = 0;
	type = a_type;
	num_choices = n_choice;
	White = { 255, 255, 255 };
	textVisible = false;
}


CAnswer::~CAnswer()
{
}

void CAnswer::setChoice(const char* chptr){
	strcpy(choices[choice_ctr], chptr);
	choice_ctr++;
}

void CAnswer::setCorChoice(int c_choice){
	cor_choice = c_choice;
}

aresponse CAnswer::showNgetAns(){
	for (int i = 0; i < num_choices; i++)
	(anstxtptrs[i])->Render(20, 230+50*i);
	return ANS_NONE;
}

void CAnswer::createAnsTextures(){
	for (int i = 0; i < 4; i++){
		anstxtptrs[i] = new CText(std::string(choices[i]), std::string("OpenSans-Regular.ttf"), White, 24, 500);
	}
}