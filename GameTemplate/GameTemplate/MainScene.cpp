#include "MainScene.h"

MainScene::MainScene(){
	SetFontSize(24);	// ���ׂ��d���炵���̂ŁA�p�ɂɌĂяo���Ȃ��悤����
	ChangeFont("���C���I");	// ���ׂ��d���炵���̂ŁA�p�ɂɌĂяo���Ȃ��悤����
	text = "�L�����Z���L�[�ŏI�����܂�";
}

MainScene::~MainScene(){
}

void MainScene::Update(){
	BaseScene::Update();

	if (KeyInput::GetKeyCancel(PushedNow)){
		EndGame();
	}
}

void MainScene::Draw(){
	BaseScene::Draw();

	DrawFormatString(10, 10, GetColor(255, 255, 255), text.c_str());
}
