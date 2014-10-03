#include "MainScene.h"

MainScene::MainScene(){
	font["�e�L�X�g"] = Font::Create("���C���I", Vector2d(10, 10), 24);
}

MainScene::~MainScene(){
}

void MainScene::Update(){
	BaseScene::Update();

	if (KeyInput::GetKey(Cancel, PushedNow)){
		EndGame();
	}
}

void MainScene::Draw(){
	BaseScene::Draw();

	font["�e�L�X�g"]->Print("�L�����Z���L�[�ŏI�����܂�");
}
