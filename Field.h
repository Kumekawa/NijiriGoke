#pragma once
#include "BaseObject.h"
#include "Block.h"
#include <vector>
using namespace std;

class Field :public BaseObject{
	vector<vector<Block>> blocks;
public:
	Field(int xNum,int yNum);
	void Update();
	void Draw();
};
