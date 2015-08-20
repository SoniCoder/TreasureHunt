#include "Question.h"


CQuestion::CQuestion(qtype q_type, const char* txt)
: text(txt)
{  
	type = q_type;
	White = { 255, 255, 255 };
	sdltext = new CText(std::string(txt), std::string("OpenSans-Regular.ttf"), White, 24, 600);
}


CQuestion::~CQuestion()
{
}

qresponse CQuestion::askQuestion(CAnswer* ansptr){
	sdltext->Render(20, 20);
	ares = ansptr->showNgetAns();
	if (((CKeyboardHandler*)MRef[6])->wasPressedNowReleased(SDL_SCANCODE_S)){
		((CKeyboardHandler*)MRef[6])->keyboardhandler();
		return SKIP;
	}
	return NONE;
}