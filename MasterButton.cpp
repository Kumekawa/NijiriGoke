#include "MasterButton.h"
#include "DxLib.h"

unsigned MasterButton::click = 0;

void MasterButton::main(){
	if (GetMouseInput() & MOUSE_INPUT_LEFT) {
		click++;
		if (click > MAXINT) {
			click = MAXINT;
		}
	}
	else {
		click = 0;
	}
}
