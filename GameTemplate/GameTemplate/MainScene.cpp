#include "MainScene.h"

MainScene::MainScene(){
	SetFontSize(24);	// ���ׂ��d���炵���̂ŁA�p�ɂɌĂяo���Ȃ��悤����
	ChangeFont("���C���I");	// ���ׂ��d���炵���̂ŁA�p�ɂɌĂяo���Ȃ��悤����
	text = "�L�����Z���L�[�ŏI�����܂�";

	//ChangeState(State::c);
	//switch (GetState()){
	//case State::a:
	//	text = "a";
	//	break;
	//case State::b:
	//	text = "b";
	//	break;
	//case State::c:
	//	text = "c";
	//	break;
	//}
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

	//DrawFormatString(10, 10+GetStateTime(), GetColor(255, 255, 255), text.c_str());
	//if (GetStateTime() > 100){
	//	ChangeState(State::b);
	//}
}
