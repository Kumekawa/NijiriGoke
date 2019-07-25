#include "Between.h"

//x‚ªmin–¢–‚È‚çmin‚ÉAx‚ªmaxˆÈã‚È‚çmax-1‚É‚·‚é
void SetBetween(int min, int *x, int max) {
	int t = CheckBetween(min, *x, max);
	switch (t)
	{
	case -1:*x = min;	break;
	case  1:*x = max - 1;	break;
	default:break;
	}
}

//x‚ªmin–¢–‚È‚ç-1,x‚ªmaxˆÈã‚È‚ç1,‚»‚êˆÈŠO‚È‚ç0‚ğ•Ô‚·
int CheckBetween(int min, int x, int max) {
	if (x < min) {
		return -1;
	}
	if (x >= max) {
		return 1;
	}
	return 0;
}
