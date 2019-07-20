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
	SetOutApplicationLogValidFlag(false);//���O���o�͂��Ȃ�

	ChangeWindowMode(TRUE);
	//�W���C�p�b�h�����܂��N�����Ȃ��ꍇ�͉��̊֐����g���Ă��������B
	SetUseJoypadVibrationFlag(FALSE);

	SetWindowSizeChangeEnableFlag(FALSE, FALSE); //���[�U�[���̃E�B���h�E�T�C�Y�ύX�s��
	//SetAlwaysRunFlag(TRUE); //�őO�ʂɂȂ���������
	SetGraphMode(XSIZEMAX, YSIZEMAX, 32); //�E�B���h�E�̍ő�T�C�Y�w��
	SetWindowSize(XSIZEMAX, YSIZEMAX); //�E�B���h�E�̃T�C�Y�w��

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



	DxLib_End();				// �c�w���C�u�����g�p�̏I������

	return 0;				// �\�t�g�̏I�� 
}