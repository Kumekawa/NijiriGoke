#include <stdio.h>
#include <math.h>
#include <windows.h>
#include <string.h>
#include <stdarg.h>
#include "MyHeader.h"
#include "MyHeader.cpp"
#include "Field.h"

#define XSIZEMAX 960
#define XSIZEMIN   0
#define YSIZEMAX 540
#define YSIZEMIN   0

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	SetOutApplicationLogValidFlag(false);//ログを出力しない

	ChangeWindowMode(TRUE);
	//ジョイパッドがうまく起動しない場合は下の関数を使ってください。
	SetUseJoypadVibrationFlag(FALSE);

	SetWindowSizeChangeEnableFlag(FALSE, FALSE); //ユーザー側のウィンドウサイズ変更不可
	//SetAlwaysRunFlag(TRUE); //最前面にない時も動作
	SetGraphMode(XSIZEMAX, YSIZEMAX, 32); //ウィンドウの最大サイズ指定
	SetWindowSize(XSIZEMAX, YSIZEMAX); //ウィンドウのサイズ指定

	if (DxLib_Init() == -1)
	{
		return -1;
	}

	SetDrawScreen(DX_SCREEN_BACK);

	Field field(10,10);
	
	while (ProcessMessage() == 0)
	{
		MasterButton::main();
		field.Update();
		field.Draw();
		DxLibDefault();
		if (CheckHitKey(KEY_INPUT_ESCAPE)) {
			break;
		}
	}



	DxLib_End();				// ＤＸライブラリ使用の終了処理

	return 0;				// ソフトの終了 
}