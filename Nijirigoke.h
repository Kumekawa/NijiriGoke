#pragma once
#include "BaseMonster.h"
#include <vector>
using namespace std;

class Nijirigoke : public BaseMonster {
	void UpdateMonster();
	void DrawMonster();
	vector<eDirection> GetNextDirection();
public:
	Nijirigoke(vector<vector<Block>> *blocks,int nourishment, int magic, int x,int y);
};
