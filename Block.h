#pragma once
#include "BaseButton.h"

class Block :public BaseButton{
	int nourishment;
	int majic;
	bool existF;
public:
	Block(int x,int y);
	void Update();
	void Draw();
};
