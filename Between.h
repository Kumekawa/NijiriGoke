#pragma once

//xがmin未満ならminに、xがmax以上ならmax-1にする
void SetBetween(int min, int *x, int max);
//xがmin未満なら-1,xがmax以上なら1,それ以外なら0を返す
int CheckBetween(int min, int x, int max);
