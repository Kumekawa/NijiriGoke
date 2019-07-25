#pragma once
#include "BaseObject.h"
#include "Block.h"
#include <vector>
#include "Between.h"
#include "Nijirigoke.h"
#include "MacroFieldSize.h"
using namespace std;


class Field :public BaseObject{
	vector<vector<Block>> blocks;
	vector<Nijirigoke> monsters;
public:
	Field();
	void Update();
	void Draw();
	Block GetBlock(int x, int y) {
		return blocks[x][y];
	}
};

//現在の座標をフィールドでの座標に変換する
struct fieldposition {
	int fieldX;
	int fieldY;
	fieldposition (int x,int y) {
		setPosition(x, y, &fieldX, &fieldY);
	}
	static void setPosition(int x, int y, int *fieldX, int *fieldY) {
		*fieldX = x / FIELD_BLOCK_SIZE;
		*fieldY = y / FIELD_BLOCK_SIZE;
		SetBetween(0, fieldX, FIELD_X);
		SetBetween(0, fieldY, FIELD_Y);
	}
};
