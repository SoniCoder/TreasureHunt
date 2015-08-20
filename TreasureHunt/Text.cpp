#include "Text.h"


CText::CText(std::string message, std::string fontFile, SDL_Color passed_color, int fontSize, int passed_wrap)
{
	iH = 0;
	iW = 0;
	color = passed_color;
	wrap = passed_wrap;
	font = TTF_OpenFont(fontFile.c_str(), fontSize);
	surf = TTF_RenderText_Blended_Wrapped(font, message.c_str(), color, wrap);
	texture = SDL_CreateTextureFromSurface(((SDLmains*)MRef[0])->renderer, surf);
	SDL_QueryTexture(texture, NULL, NULL, &iW, &iH);
	Message_rect.w = iW;
	Message_rect.h = iH;
}


CText::~CText()
{
	SDL_FreeSurface(surf);
	TTF_CloseFont(font);
}

void CText::Render(int passed_x, int passed_y){
	Message_rect.x = passed_x;
	Message_rect.y = passed_y;
	SDL_RenderCopy(((SDLmains*)MRef[0])->renderer, texture, NULL, &Message_rect);
}

void CText::Render(){
	SDL_RenderCopy(((SDLmains*)MRef[0])->renderer, texture, NULL, &Message_rect);
}

void CText::setCoords(int passed_x, int passed_y){
	Message_rect.x = passed_x;
	Message_rect.y = passed_y;
}

void CText::changeText(std::string newtext){
	surf = TTF_RenderText_Blended_Wrapped(font, newtext.c_str(), color, wrap);
	texture = SDL_CreateTextureFromSurface(((SDLmains*)MRef[0])->renderer, surf);
	SDL_QueryTexture(texture, NULL, NULL, &iW, &iH);
	Message_rect.w = iW;
	Message_rect.h = iH;
}