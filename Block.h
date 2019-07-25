#pragma once
#include "BaseButton.h"

class Block :public BaseButton{
	int nourishment;
	int majic;
	bool existF;
	bool newMonsterF;
public:
	Block(int x,int y);
	void Update();
	void Draw();
	bool GetMonsterF() {
		return newMonsterF;
	}
};
