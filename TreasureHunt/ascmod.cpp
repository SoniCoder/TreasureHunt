#include "ascmod.h"

void LockingMech(bool* locked){
	if (!(*locked)){
		;
	}
	else{
		if (((CKeyboardHandler*)MRef[6])->isPressed(SDL_SCANCODE_TAB)){
			*locked = false;
			system("cls");
			std::cout << "Unlocked!" << std::endl;
		}
	}
	return;
}