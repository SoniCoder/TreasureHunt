#include "LayerHandler.h"

void drawLayers(){
	drawTextLayer();
	return;
}

void drawTextLayer(){
	for (int i = 0; i < (((int*)MRef[5])[1]); i++){
		(((CText**)MRef[4])[i])->Render();
	}
	return;
}