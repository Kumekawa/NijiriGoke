#include "Block.h"
#include "DxLib.h"
#include "MacroColor.h"
#include <string>
#include <sstream>
using namespace std;

Block::Block(int x,int y){
	nourishment = GetRand(10);
	majic = GetRand(10);

	xSize = 100;
	ySize = xSize;
	this->x = x;
	this->y = y;
	existF = true;
}

void Block::Update(){
	if (GetClick()) {
		existF = false;
	}
}

void Block::Draw() {
	if (existF) {
		DrawBox(x, y, x + xSize, y + ySize, MC_BROWN, 1);
		DrawBox(x, y, x + xSize, y + ySize, MC_BLACK, 0);

		ostringstream t;
		t << nourishment;
		DrawFormatString(x, y, MC_WHITE, t.str().c_str());
	}
}
