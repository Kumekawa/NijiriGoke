#include "Between.h"

//x��min�����Ȃ�min�ɁAx��max�ȏ�Ȃ�max-1�ɂ���
void SetBetween(int min, int *x, int max) {
	int t = CheckBetween(min, *x, max);
	switch (t)
	{
	case -1:*x = min;	break;
	case  1:*x = max - 1;	break;
	default:break;
	}
}

//x��min�����Ȃ�-1,x��max�ȏ�Ȃ�1,����ȊO�Ȃ�0��Ԃ�
int CheckBetween(int min, int x, int max) {
	if (x < min) {
		return -1;
	}
	if (x >= max) {
		return 1;
	}
	return 0;
}
