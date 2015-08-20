#pragma once
#include "Includes.h"
#include "Text.h"
#include "KeyboardHandler.h"
#include "Answer.h"
class CQuestion
{
public:
	CQuestion(qtype q_type, const char* txt);
	~CQuestion();
	qresponse askQuestion(CAnswer*);
private:
	qtype type;
	std::string text;
	CText* sdltext;
	SDL_Color White;
	aresponse ares;
};

