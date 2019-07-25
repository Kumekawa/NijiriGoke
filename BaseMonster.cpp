#include "BaseMonster.h"
#include "MacroFieldSize.h"
#include "Between.h"

void BaseMonster::Update() {
	
	UpdateMonster();
	switch (direction)
	{
	case eUp:
		y -= speed;
		break;
	case eDown:
		y += speed;
		break;
	case eRight:
		x += speed;
		break;
	case eLeft:
		x -= speed;
		break;
	default:
		break;
	}

	SetBetween(0, &x, FIELD_X * FIELD_BLOCK_SIZE);
	SetBetween(0, &y, FIELD_Y * FIELD_BLOCK_SIZE);

	fieldX = x / FIELD_BLOCK_SIZE + xOffset;
	fieldY = y / FIELD_BLOCK_SIZE + yOffset;

	switch (direction)
	{
	case eUp:yOffset = 1;
		break;
	case eDown:yOffset = 0;
		break;
	case eRight:xOffset = 0;
		break;
	case eLeft:xOffset = 1;
		break;
	default:
		break;
	}
}
void BaseMonster::Draw() {
	DrawMonster();
}
