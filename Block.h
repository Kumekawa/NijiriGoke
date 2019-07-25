#pragma once
#include "BaseButton.h"

class Block :public BaseButton{
	int nourishment;
	int magic;
	bool existF;
	bool newMonsterF;
public:
	Block(int x,int y);
	void Update();
	void Draw();
	bool GetMonsterF() {
		return newMonsterF;
	}
	bool GetExistF() {
		return existF;
	}
	int GetNourishment() {
		return nourishment;
	}
	int GetMagic() {
		return magic;
	}
};
