#include "Nijirigoke.h"
#include "DxLib.h"
#include "MacroColor.h"
#include "MacroFieldSize.h"
#include "Between.h"

Nijirigoke::Nijirigoke(vector<vector<Block>> *blocks,int nourishment, int magic, int x,int y) {
	this->blocks = blocks;
	speed = 2;
	direction = (eDirection)GetRand(3);
	HP = 10;
	maxHP = 20;
	this->nourishment = nourishment;
	this->magic = magic;
	breedingNum = 0;
	breedingNumMax = 1;
	atk = 1;
	def = 1;
	fieldX = x / FIELD_BLOCK_SIZE;
	fieldY = y / FIELD_BLOCK_SIZE;
	this->x = x;
	this->y = y;
	xOffset = 0;
	yOffset = 0;

}

void Nijirigoke::UpdateMonster(){
	vector<eDirection> td = GetNextDirection();
	for (int k = 0; k < 4; ++k) {
		int i = 0;
		int j = 0;
		switch (td[k])
		{
		case eUp:
			j = -1;
			break;
		case eDown:
			j = 1;
			break;
		case eRight:
			i = 1;
			break;
		case eLeft:
			i = -1;
			break;
		default:
			break;
		}

		//外にはみ出していたらアウト
		int tx = CheckBetween(0, fieldX + i, FIELD_X);
		int ty = CheckBetween(0, fieldY + j, FIELD_Y);

		//外にはみ出ていない場合、壁の判定
		if (tx == 0 && ty == 0) {
			//行先に壁が無ければOK!
			if ((*blocks)[fieldX + i][fieldY + j].GetExistF() == false) {
				direction = td[k];
				break;
			}
		}
	}
}

void Nijirigoke::DrawMonster(){
	const int fbs = FIELD_BLOCK_SIZE;
	DrawCircle(x + fbs / 2, y + fbs / 2, fbs / 4, MC_GREEN);
	DrawCircle(x + fbs / 2, y + fbs / 2, fbs / 4, MC_BLACK,0,3);
}

vector<eDirection> Nijirigoke::GetNextDirection(){
	vector<eDirection> directions;
	directions.push_back(direction);

	int r = GetRand(1);
	for (int i = 0; i < 2; ++i) {
		if (r == 1) {
			switch (direction)
			{
			case eUp:
			case eDown:directions.push_back(eRight);
				break;
			case eRight:
			case eLeft:directions.push_back(eUp);
				break;
			default:
				break;
			}
		}
		else {
			switch (direction)
			{
			case eUp:
			case eDown:directions.push_back(eLeft);
				break;
			case eRight:
			case eLeft:directions.push_back(eDown);
				break;
			default:
				break;
			}
		}
		r = (r + 1) % 2;
	}

	switch (direction)
	{
	case eUp:directions.push_back(eDown);
		break;
	case eDown:directions.push_back(eUp);
		break;
	case eRight:directions.push_back(eLeft);
		break;
	case eLeft:directions.push_back(eRight);
		break;
	default:
		break;
	}

	return directions;
}
