#include "preSdlSetup.h"

CText* TextPtrs[100];
int numObj[100];

void loadTexts(){

	MRef[4] = (void*)TextPtrs;
	MRef[5] = (void*)numObj;
	for (int i = 0; i < 100;i++)
	numObj[i] = 0;
}

void preSdlSetup(){
	loadTexts();
}