#include "Between.h"

//xがmin未満ならminに、xがmax以上ならmax-1にする
void SetBetween(int min, int *x, int max) {
	int t = CheckBetween(min, *x, max);
	switch (t)
	{
	case -1:*x = min;	break;
	case  1:*x = max - 1;	break;
	default:break;
	}
}

//xがmin未満なら-1,xがmax以上なら1,それ以外なら0を返す
int CheckBetween(int min, int x, int max) {
	if (x < min) {
		return -1;
	}
	if (x >= max) {
		return 1;
	}
	return 0;
}
