#include "BaseButton.h"
#include "DxLib.h"

bool BaseButton::GetMouseOn(){
	int mx, my;
	GetMousePoint(&mx, &my);
	if (x <= mx && mx < x + xSize) {
		if (y <= my && my < y + ySize) {
			return true;
		}
	}
	return false;
}

bool BaseButton::GetClick(){
	if (GetMouseOn()) {
		if (click > 0) {
			return true;
		}
	}
	return false;
}

bool BaseButton::GetClickNow(){
	if (GetMouseOn()) {
		if (click == 1) {
			return true;
		}
	}
	return false;
}
