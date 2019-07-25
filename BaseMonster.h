#pragma once
#include "BaseObject.h"
#include "Block.h"
#include <vector>
using namespace std;

enum eDirection{eUp,eDown,eRight,eLeft};

class BaseMonster : public BaseObject{
protected:
	int speed;
	eDirection direction;
	int HP;
	int maxHP;
	int nourishment;
	int magic;
	int breedingNum;
	int breedingNumMax;
	int atk;
	int def;
	vector<vector<Block>> *blocks;
	virtual void UpdateMonster() = 0;
	virtual void DrawMonster() = 0;
	int fieldX;//fieldè„Ç≈ÇÃxç¿ïW
	int fieldY;//fieldè„Ç≈ÇÃyç¿ïW
	int xOffset;
	int yOffset;
public:
	void Update() override;
	void Draw() override;
};
